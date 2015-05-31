#include "Package.h"

namespace ContainerLoading
{
    namespace Utils
    {
        Package::Package(const Dimensions dimensions, const glm::vec3 position)
        {
            _dimensions = dimensions;
            _position = position;
        }

        bool Package::intersect(const Package& package) const
        {
            return 
                (_position.x + _dimensions.width > package._position.x &&
                _position.x < package._position.x + package._dimensions.width)
            && 
                (_position.y + _dimensions.height > package._position.y &&
                _position.y < package._position.y + package._dimensions.height)
            &&
                (_position.z + _dimensions.length > package._position.z &&
                _position.z < package._position.z + package._dimensions.length);
        }

        bool Package::layAbove(const Package& package) const
        {
            return 
                (_position.x + _dimensions.width > package._position.x &&
                _position.x < package._position.x + package._dimensions.width)
            && 
                (_position.y >= package._position.y + package._dimensions.height)
            &&
                (_position.z + _dimensions.length > package._position.z &&
                _position.z < package._position.z + package._dimensions.length);
        }

        glm::vec3 Package::getPosition() const
        {
            return _position;
        }

        const Dimensions& Package::getDimensions() const
        {
            return _dimensions;
        }

        void Package::setPosition(const glm::vec3 pos)
        {
            _position = pos;
        }

        void Package::setDimensions(const Dimensions dimensions)
        {
            _dimensions = dimensions;
        }
    }
}