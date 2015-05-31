#ifndef CONTAINERLOADING_ALGORITHM_IALGORITHM
#define CONTAINERLOADING_ALGORITHM_IALGORITHM

#include "../Utils/Layer.h"
#include "../Utils/Container.h"

namespace ContainerLoading
{
    namespace Algorithm
    {
        class IAlgorithm
        {
        public:
            IAlgorithm(Utils::Container& container, std::vector<Utils::Package>& packages);

            virtual bool run(int steps) = 0;

        private:
            Utils::Container& _container;
            std::vector<Utils::Package>& _packages;
        };
    }
}

#endif /* CONTAINERLOADING_ALGORITHM_IALGORITHM */