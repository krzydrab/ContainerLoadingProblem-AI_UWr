#ifndef CONTAINERLOADING_CONTAINERLOADER
#define CONTAINERLOADING_CONTAINERLOADER

#include "Algorithm/IAlgorithm.h"
#include "PackageGenerator.h"

namespace ContainerLoading
{
    class ContainerLoader
    {
    public:
        ContainerLoader(const Utils::Container container, IPackageGenerator* packageGenerator);
        ~ContainerLoader();

        Utils::Container& getContainer();
        std::vector<Utils::Package>& getPackages();
        void applyAlgorithm(Algorithm::IAlgorithm* algorithm);

        bool run(int steps);
        bool singleStep();

        unsigned countUnloadedPackages() const;
        unsigned countLadedPackages() const;

        glm::float32 getBestLoadingCapacity() const;
        unsigned getBestLoadingNbOfPackages() const;

    private:
        Utils::Container _container;
        std::vector<Utils::Package> _packages;
        Algorithm::IAlgorithm* _algorithm;
    };
}

#endif /* CONTAINERLOADING_CONTAINERLOADER */