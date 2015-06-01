#include "Container.h"

namespace ContainerLoading
{
    namespace Utils
    {
        Container::Container(const Dimensions dimensions, const glm::float32 layerWidth, const glm::vec3 position)
        {
            _dimensions = dimensions;
            _position = position;

            glm::float32 x = 0;
            while(x < _dimensions.width)
            {
                _layers.push_back(Layer(_dimensions, _position + glm::vec3(x, .0f, .0f)));
                x += layerWidth;
            }
        }

        std::vector<Layer>& Container::getLayers()
        {
            return _layers;
        }

        Dimensions Container::getDimensions() const
        {
            return _dimensions;
        }

        glm::vec3 Container::getPosition() const
        {
            return _position;
        }

        glm::float32 Container::getFreeSpace() const
        {
            return _dimensions.capacity() - getFilledSpace();
        }

        glm::float32 Container::getFilledSpace() const
        {
            glm::float32 filledSpace = .0f;

            for(auto& layer : _layers)
            {
                filledSpace += layer.spaceFilledByPackages();
            }

            return filledSpace;
        }

        unsigned Container::countContainingPackages() const
        {
            unsigned packages = 0;

            for(auto& layer : _layers)
            {
                packages += layer.getPackages().size();
            }

            return packages;
        }
    }
}