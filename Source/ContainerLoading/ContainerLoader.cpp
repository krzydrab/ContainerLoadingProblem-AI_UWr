#include "ContainerLoader.h"

namespace ContainerLoading
{
    ContainerLoader::ContainerLoader(const Utils::Container container, IPackageGenerator* packageGenerator)
        : _container(container)
    {
        _packages = packageGenerator->generatePackages();
        _algorithm = nullptr;
    }

    ContainerLoader::~ContainerLoader()
    {
        if(_algorithm != nullptr)
        {
            delete _algorithm;
        }
    }
    
    bool ContainerLoader::run(int steps)
    {
        if(_algorithm != nullptr)
        {
            return _algorithm->run(steps);
        }
        return false;
    }

    bool ContainerLoader::singleStep()
    {
        return run(1);
    }

    Utils::Container& ContainerLoader::getContainer()
    {
        return _container;
    }

    std::vector<Utils::Package>& ContainerLoader::getPackages()
    {
        return _packages;
    }

    void ContainerLoader::applyAlgorithm(Algorithm::IAlgorithm* algorithm)
    {
        if(_algorithm != nullptr)
            delete _algorithm;

        _algorithm = algorithm;
    }
}