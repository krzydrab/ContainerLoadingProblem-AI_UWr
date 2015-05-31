#include "ConstructionAlgorithm.h"

namespace ContainerLoading
{
    namespace Algorithm
    {    
        ConstructionAlgorithm::ConstructionAlgorithm(
            Utils::Container& container, 
            std::vector<Utils::Package>& packages
        )
            : IAlgorithm(container, packages)
        {

        }

        bool ConstructionAlgorithm::run(int steps)
        {
            std::vector<Utils::Layer>& layers = _container.getLayers();

            while(steps--)
            {
                if(_packages.empty() || !tryPutPackageInAnyLayer(layers))
                {
                    return false;
                }
            }

            return true;
        }

        bool ConstructionAlgorithm::tryPutPackageInAnyLayer(std::vector<Utils::Layer>& layers)
        {
            for(unsigned i = 0 ; i < layers.size() ; i++)
            {
                if(layers[i].tryPut(_packages.back()))
                {
                    _packages.pop_back();
                    return true;
                }
            }
            return false;
        }
    }
}