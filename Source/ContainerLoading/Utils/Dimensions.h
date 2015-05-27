#ifndef CONTAINERLOADING_UTILS_DIMENSIONS
#define CONTAINERLOADING_UTILS_DIMENSIONS

#include <vector>
#include <glm/glm.hpp>

namespace ContainerLoading
{
    namespace Utils
    {
        class Dimensions
        {
        public:
            Dimensions();
            Dimensions(const glm::float32 width, const glm::float32 height, const glm::float32 length);
        
            glm::vec3 asVec3();

        public:
            glm::float32 width;
            glm::float32 height;
            glm::float32 length;
        };
    }
}

#endif /* CONTAINERLOADING_UTILS_DIMENSIONS */