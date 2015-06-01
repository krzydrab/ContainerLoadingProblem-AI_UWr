#include "IAlgorithm.h"

namespace ContainerLoading
{
    namespace Algorithm
    {
        IAlgorithm::IAlgorithm(Utils::Container& container, std::vector<Utils::Package>& packages)
            : _container(container), _packages(packages)
        {
            _bestLoadingCapacity = .0f;
            _bestLoadingNbOfPackages = 0;
        }

        unsigned IAlgorithm::countUnloadedPackages() const
        {
            return _packages.size();
        }

        glm::float32 IAlgorithm::getBestLoadingCapacity() const
        {
            return _bestLoadingCapacity;
        }

        unsigned IAlgorithm::getBestLoadingNbOfPackages() const
        {
            return _bestLoadingNbOfPackages;
        }
    }
}