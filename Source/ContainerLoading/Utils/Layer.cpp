#include "Layer.h"

namespace ContainerLoading
{
    namespace Utils
    {
        Layer::Layer(const Utils::Dimensions containerDimensions, const glm::vec3 layerPosition)
        {
            _containerDimensions = containerDimensions;
            _position = layerPosition;
            _packagesCapacity = .0f;

            _topSections.insert(Section(.0f, _containerDimensions.length, .0f));
        }

        bool Layer::tryPut(const Utils::Package& package)
        {
            SectionIter section = _topSections.begin();
            while(section != _topSections.end())
            {
                if(fitInSection(package, section))
                {
                    insertInSection(package, section);
                    joinSectionsOfEqualHeights();
                    return true;
                }
                ++section;
            }
            return false;
        }

        Utils::Package Layer::takeRandomTopPackage()
        {
            std::vector<PackageIter> packages = getTopPackages();
            PackageIter it = packages[rand() % packages.size()];
            PackageIter last = --_packages.end();
            std::iter_swap(it, last);

            Utils::Package res = *last;
            _packages.pop_back();

            SectionIter section = _topSections.lower_bound(Section(res.getPosition().z - _position.z));
            
            removeFromSection(res, section);
            joinSectionsOfEqualHeights();

            return res;
        }

        std::vector<Utils::Package> Layer::getPackages() const
        {
            return _packages;
        }

        glm::float32 Layer::spaceFilledByPackages() const
        {
            return _packagesCapacity;
        }

        std::vector<Layer::PackageIter> Layer::getTopPackages()
        {
            std::vector<PackageIter> res;

            for(Layer::PackageIter it = _packages.begin() ; it != _packages.end() ; it++)
                if(isTopPackage(*it))
                    res.push_back(it);

            return res;
        }

        bool Layer::isTopPackage(const Utils::Package& package)
        {
            glm::vec3 pos1 = package.getPosition();

            for(Utils::Package& p : _packages)
            {
                glm::vec3 pos2 = p.getPosition();
                if(p.layAbove(package))
                {
                    return false;
                }
            }

            return true;
        }

        void Layer::joinSectionsOfEqualHeights()
        {
            SectionIter it = _topSections.begin();
        
            while(it != _topSections.end())
            {
                SectionIter next = std::next(it, 1);
                Section joined(it->left, it->right, it->height);

                while(next != _topSections.end() && next->height == it->height)
                {
                    joined.right = next->right;
                    next++;
                    _topSections.erase(std::next(next, -1));
                }
                if(it->right != joined.right)
                {
                    _topSections.erase(it);
                    _topSections.insert(joined);
                }
                it = next;
            }
        }

        bool Layer::fitInSection(const Utils::Package& package, SectionIter section) const
        {
            return section->right - section->left >= package.getDimensions().length && 
                section->height + package.getDimensions().height <= _containerDimensions.height;
        }

        void Layer::insertInSection(const Utils::Package& package, SectionIter section)
        {
            Utils::Package p = package;
            p.setPosition(_position + glm::vec3(.0f, section->height, section->left));
            _packages.push_back(p);
            _packagesCapacity += p.getDimensions().capacity();

            splitSection(package, section);
        }

        void Layer::splitSection(const Utils::Package& package, SectionIter section)
        {
            _topSections.insert(Section(
                section->left, 
                section->left + package.getDimensions().length, 
                section->height + package.getDimensions().height)
            );
            if(section->left + package.getDimensions().length != section->right)
            {
                _topSections.insert(Section(
                    section->left + package.getDimensions().length,
                    section->right,
                    section->height)
                );
            }

            _topSections.erase(section);
        }

        void Layer::removeFromSection(const Utils::Package& package, SectionIter section)
        {
            Section packageSection(
                package.getPosition().z - _position.z,
                package.getPosition().z - _position.z + package.getDimensions().length,
                package.getPosition().y - _position.y
            );
            
            _topSections.insert(packageSection);
            
            if(section->left != packageSection.left)
                _topSections.insert(Section(section->left, packageSection.left, section->height));

            if(section->right != packageSection.right)
                _topSections.insert(Section(packageSection.right, section->right, section->height));            

            _topSections.erase(section);
        }
    }
}