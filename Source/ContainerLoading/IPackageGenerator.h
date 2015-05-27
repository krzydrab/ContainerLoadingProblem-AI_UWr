#ifndef CONTAINERLOADING_IPACKAGEGENERATOR
#define CONTAINERLOADING_IPACKAGEGENERATOR

#include <vector>
#include "Utils/Dimensions.h"
#include "Utils/Package.h"

namespace ContainerLoading
{
    class IPackageGenerator
    {
    public:
        IPackageGenerator(const Utils::Dimensions containerDim)
        {
            _containerDim = containerDim;
        }

        virtual std::vector<Utils::Package> generatePackages() = 0;

    protected:
        Utils::Dimensions _containerDim;
    };
}

#endif /* CONTAINERLOADING_IPACKAGEGENERATOR */