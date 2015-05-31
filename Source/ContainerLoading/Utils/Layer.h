#ifndef CONTAINERLOADER_LAYER
#define CONTAINERLOADER_LAYER

#include "Package.h"
#include <set>
#include <vector>

namespace ContainerLoading
{
    namespace Utils
    {
        class Layer
        {
        public:
            Layer(const Utils::Dimensions containerDimensions, const glm::vec3 layerPosition);

            bool tryPut(const Utils::Package& package);
            Utils::Package takeRandomTopPackage();
            std::vector<Utils::Package> getPackages() const;
            glm::float32 spaceFilledByPackages() const;

        public:
            struct Section
            {
                glm::float32 left, right, height;
                Section(const glm::float32 l = .0f, const glm::float32 r = .0f, const glm::float32 h = .0f)
                {
                    left   = l;
                    right  = r;
                    height = h;
                };
            };

            struct SectionCmp
            {
                bool operator()(const Section& a, const Section& b)
                {
                    if(a.left == b.left)
                    {
                        return (a.right == b.right) ? (a.height < b.height) : (a.right < b.right);
                    }
                    else
                    {
                        return a.left < b.left;
                    }
                }
            };

            typedef std::vector<Utils::Package>::iterator PackageIter;
            typedef std::set<Section, SectionCmp>::iterator SectionIter;

        public:
            std::vector<PackageIter> getTopPackages();
            bool isTopPackage(const Utils::Package& package);
            void joinSectionsOfEqualHeights();
            bool fitInSection(const Utils::Package& package, SectionIter section) const;
            void insertInSection(const Utils::Package& package, SectionIter section);
            void splitSection(const Utils::Package& package, SectionIter section);
            void removeFromSection(const Utils::Package& package, SectionIter section);

            std::set<Section, SectionCmp> _topSections; 
            std::vector<Utils::Package> _packages;
            Utils::Dimensions _containerDimensions;
            glm::vec3 _position;
            glm::float32 _packagesCapacity;
        };
    }
}

#endif /* CONTAINERLOADER_LAYER */