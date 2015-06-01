#ifndef CONTAINERLOADING_ALGORITHM_TABUSEARCH
#define CONTAINERLOADING_ALGORITHM_TABUSEARCH

#include "IAlgorithm.h"

namespace ContainerLoading
{
    namespace Algorithm
    {
        class TabuSearch : public IAlgorithm
        {
        public:
            TabuSearch(Utils::Container& container, std::vector<Utils::Package>& packages);

            virtual bool run(int steps);

        private:

        };
    }
}

#endif /* CONTAINERLOADING_ALGORITHM_TABUSEARCH */