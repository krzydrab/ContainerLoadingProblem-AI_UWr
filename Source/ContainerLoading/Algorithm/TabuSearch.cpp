#include "TabuSearch.h"

namespace ContainerLoading
{
    namespace Algorithm
    {    
        TabuSearch::TabuSearch(
            Utils::Container& container, 
            std::vector<Utils::Package>& packages
        )
            : IAlgorithm(container, packages)
        {

        }

        bool TabuSearch::run(int steps)
        {
            std::vector<Utils::Layer>& layers = _container.getLayers();

            while(steps--)
            {
                if(_packages.empty()) 
                {
                    if(_tabuList.empty())
                        return false;

                    _packages.push_back(_tabuList.front());
                    _tabuList.pop_front();
                }

                if(!tryPutPackageInAnyLayer(layers))
                    takePackage(layers);
                else
                    updateBestScores();
            }

            return true;
        }

        bool TabuSearch::tryPutPackageInAnyLayer(std::vector<Utils::Layer>& layers)
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

        void TabuSearch::takePackage(std::vector<Utils::Layer>& layers)
        {
            glm::float32 best = _container.getDimensions().capacity();
            int id = -1;

            for(unsigned i = 0 ; i < layers.size() ; i++)
            {
                Utils::Package& p = layers[i].takeTopPackage();
                if(p.getDimensions().capacity() < best)
                {
                    best = p.getDimensions().capacity();
                    id = i;
                }
                layers[i].tryPut(p);
            }

            _tabuList.push_back(layers[id].takeTopPackage());
        }

        unsigned TabuSearch::countUnloadedPackages() const
        {
            return _packages.size() + _tabuList.size();
        }

        void TabuSearch::updateBestScores()
        {
            glm::float32 capacity = _container.getFilledSpace();
            unsigned nbOfPackages = _container.countContainingPackages();

            _bestLoadingCapacity = std::max(_bestLoadingCapacity, capacity);
            _bestLoadingNbOfPackages = std::max(_bestLoadingNbOfPackages, nbOfPackages);
        }
    }
}