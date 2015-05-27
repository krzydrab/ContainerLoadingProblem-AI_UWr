#include "PackageGenerator.h"

namespace ContainerLoading
{
        PackageGenerator::PackageGenerator(const Utils::Dimensions containerDim, const int layers, const int slicesPerPackage)
            : IPackageGenerator(containerDim)
        {
            _layers = layers;
            _slicesPerLayer = slicesPerPackage;

            _layerWidth = _containerDim.width / (glm::float32)_layers;
        }

        std::vector<Utils::Package> PackageGenerator::generatePackages()
        {
            std::vector<Utils::Package> res;

            for(int i = 0 ; i < _layers ; i++)
            {
                std::vector<Utils::Package> p = generateLayerOfPackages(i);

                res.insert(res.begin(), p.begin(), p.end());
            }

            return std::move(res);
        }

        std::vector<Utils::Package> PackageGenerator::generateLayerOfPackages(const int currentLayer)
        {
            std::vector<Utils::Package> res;
            
            res.push_back(Utils::Package(
                Utils::Dimensions(_layerWidth, _containerDim.height, _containerDim.length),
                glm::vec3(currentLayer * _layerWidth, .0f, .0f)
            ));

            for(int i = 0 ; i < _slicesPerLayer ; i++)
            {
                Utils::Package& p = res[rand() % res.size()];
                auto sliced = slicePackage(p);

                p = sliced.first;
                res.push_back(sliced.second);
            }

            return std::move(res);
        }

        std::pair<Utils::Package, Utils::Package> PackageGenerator::slicePackage(const Utils::Package package)
        {
            if(rand()% 2)
            {
                return std::move(slicePackageHeight(package));
            }
            else
            {
                return std::move(slicePackageLength(package));
            }
        }

        std::pair<Utils::Package, Utils::Package> PackageGenerator::slicePackageHeight(const Utils::Package package)
        {
            // slice between 20%-80% of package height
            float s = .2f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(.6f)));

            const Utils::Dimensions dim = package.getDimensions();
            const glm::vec3 pos = package.getPosition();

            return std::make_pair(
                Utils::Package(
                    Utils::Dimensions(dim.width, dim.height * s, dim.length), pos
                ),
                Utils::Package(
                    Utils::Dimensions(dim.width, dim.height - dim.height * s, dim.length),
                    glm::vec3(pos.x, pos.y + dim.height * s, pos.z)                
                )
            );
        }

        std::pair<Utils::Package, Utils::Package> PackageGenerator::slicePackageLength(const Utils::Package package)
        {
            // slice between 20%-80% of package length
            float s = .2f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(.6f)));

            const Utils::Dimensions dim = package.getDimensions();
            const glm::vec3 pos = package.getPosition();

            return std::make_pair(
                Utils::Package(
                    Utils::Dimensions(dim.width, dim.height, dim.length * s), pos
                ),
                Utils::Package(
                    Utils::Dimensions(dim.width, dim.height, dim.length - dim.length * s),
                    glm::vec3(pos.x, pos.y, pos.z + dim.length * s)
                )
            );
        }
}