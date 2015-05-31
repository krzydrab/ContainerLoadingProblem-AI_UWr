#include "IAlgorithm.h"

namespace ContainerLoading
{
    namespace Algorithm
    {
        IAlgorithm::IAlgorithm(Utils::Container& container, std::vector<Utils::Package>& packages)
            : _container(container), _packages(packages)
        {
            
        }
    }
}