#ifndef CONTAINERLOADING_CONTAINER
#define CONTAINERLOADING_CONTAINER

#include "Layer.h"

namespace ContainerLoading
{
    namespace Utils
    {
        class Container
        {
        public:
            Container(
                const Dimensions dimensions, 
                const glm::float32 layerWidth, 
                const glm::vec3 position = glm::vec3(.0f, .0f, .0f)
            );

            std::vector<Layer>& getLayers();
            Dimensions getDimensions() const;
            glm::vec3 getPosition() const;
            glm::float32 getFreeSpace() const;
            glm::float32 getFilledSpace() const;
            unsigned countContainingPackages() const;

        private:
            std::vector<Layer> _layers;
            Dimensions _dimensions;
            glm::vec3 _position;
        };
    }
}

#endif /* CONTAINERLOADING_CONTAINER */