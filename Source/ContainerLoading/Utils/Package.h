#ifndef CONTAINERLOADING_UTILS_PACKAGE
#define CONTAINERLOADING_UTILS_PACKAGE

#include <vector>
#include <glm/glm.hpp>

#include "Dimensions.h"

namespace ContainerLoading
{
    namespace Utils
    {
        class Package
        {
        public:
            Package(const Dimensions dimensions, const glm::vec3 position = glm::vec3(.0f, .0f, .0f));

            bool intersect(const Package& package) const;
            bool layAbove(const Package& package) const;

        public:
            glm::vec3 getPosition() const;
            const Dimensions& getDimensions() const;
            glm::vec3 getColor() const;

            void setPosition(const glm::vec3 pos);
            void setDimensions(const Dimensions dimensions);

        private:
            glm::vec3 _position;
            glm::vec3 _color;
            Dimensions _dimensions;
        };
    }
}

#endif /* CONTAINERLOADING_UTILS_PACKAGE */