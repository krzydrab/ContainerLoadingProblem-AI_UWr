#include "Dimensions.h"

namespace ContainerLoading
{
    namespace Utils
    {
        Dimensions::Dimensions(const glm::float32 w, const glm::float32 h, const glm::float32 l)
        {
            width = w;
            height = h;
            length = l;
        }

        Dimensions::Dimensions()
        {
            width = height = length = 0;
        }

        glm::vec3 Dimensions::asVec3()
        {
            return glm::vec3(width, height, length);
        }

        glm::float32 Dimensions::capacity() const
        {
            return width*height*length;
        }
    }
}