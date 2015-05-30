#include "Layer.h"

namespace ContainerLoading
{
    namespace Utils
    {
        Layer::Layer(const Utils::Dimensions containerDimensions, const glm::vec3 layerPosition)
        {
            _containerDimensions = containerDimensions;
            _position = layerPosition;

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
            return Utils::Package(Utils::Dimensions(0,0,0));
        }

        std::vector<Utils::Package> Layer::getPackages() const
        {
            return _packages;
        }

        std::vector<Layer::PackageIter> Layer::getTopPackages()
        {
            return std::vector<Layer::PackageIter>();
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
    }
}