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

            return true;
        }
    }
}