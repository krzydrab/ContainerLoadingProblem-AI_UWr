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
            virtual unsigned countUnloadedPackages() const;

            glm::float32 getBestLoadingCapacity() const;
            unsigned getBestLoadingNbOfPackages() const;

        protected:
            Utils::Container& _container;
            std::vector<Utils::Package>& _packages;
            glm::float32 _bestLoadingCapacity;
            unsigned _bestLoadingNbOfPackages;
        };
    }
}

#endif /* CONTAINERLOADING_ALGORITHM_IALGORITHM */