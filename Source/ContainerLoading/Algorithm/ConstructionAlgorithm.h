#ifndef CONTAINERLOADING_ALGORITHM_CONSTRUCTIONALGORITHM
#define CONTAINERLOADING_ALGORITHM_CONSTRUCTIONALGORITHM

#include "IAlgorithm.h"

namespace ContainerLoading
{
    namespace Algorithm
    {
        class ConstructionAlgorithm : public IAlgorithm
        {
        public:
            ConstructionAlgorithm(Utils::Container& container, std::vector<Utils::Package>& packages);

            virtual bool run(int steps);

        private:
            bool tryPutPackageInAnyLayer(std::vector<Utils::Layer>& layers);
        };
    }
}

#endif /* CONTAINERLOADING_ALGORITHM_CONSTRUCTIONALGORITHM */