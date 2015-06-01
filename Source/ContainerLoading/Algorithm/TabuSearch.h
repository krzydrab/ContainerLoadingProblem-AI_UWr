#ifndef CONTAINERLOADING_ALGORITHM_TABUSEARCH
#define CONTAINERLOADING_ALGORITHM_TABUSEARCH

#include "IAlgorithm.h"

#include <list>

namespace ContainerLoading
{
    namespace Algorithm
    {
        class TabuSearch : public IAlgorithm
        {
        public:
            TabuSearch(Utils::Container& container, std::vector<Utils::Package>& packages);

            virtual bool run(int steps);
            unsigned countUnloadedPackages() const;

        private:
            bool tryPutPackageInAnyLayer(std::vector<Utils::Layer>& layers);
            void takePackage(std::vector<Utils::Layer>& layers);
            void updateBestScores();

            std::list<Utils::Package> _tabuList;
        };
    }
}

#endif /* CONTAINERLOADING_ALGORITHM_TABUSEARCH */