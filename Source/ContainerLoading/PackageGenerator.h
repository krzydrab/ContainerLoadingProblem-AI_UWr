#ifndef CONTAINERLOADING_PACKAGEGENERATOR
#define CONTAINERLOADING_PACKAGEGENERATOR

#include <vector>
#include "Utils/Dimensions.h"
#include "Utils/Package.h"
#include "IPackageGenerator.h"

namespace ContainerLoading
{
    class PackageGenerator : public IPackageGenerator
    {
    public:
        PackageGenerator(const Utils::Dimensions containerDim, const int layers, const int slicesPerPackage);

        virtual std::vector<Utils::Package> generatePackages();

    protected:
        std::vector<Utils::Package> generateLayerOfPackages(const int currentLayer);
        std::pair<Utils::Package, Utils::Package> slicePackage(const Utils::Package package);
        std::pair<Utils::Package, Utils::Package> slicePackageHeight(const Utils::Package package);
        std::pair<Utils::Package, Utils::Package> slicePackageLength(const Utils::Package package);

    protected:
        int _layers;
        int _slicesPerLayer;
        glm::float32 _layerWidth;
    };
}

#endif /* CONTAINERLOADING_PACKAGEGENERATOR */