#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Visualisation
{
    namespace Model
    {
        class Cube
        {
        public:
            Cube();

            int getNumberOfVertices();
            std::vector<glm::vec3>& getVertices();
            std::vector<glm::vec3>& getNormals();
            GLuint getRenderingMode() const;

        private:
            void initVertices();
            void initNormals();

            std::vector<glm::vec3> vertices;
            std::vector<glm::vec3> normals;
            GLuint renderingMode;
        };
    }
}


#endif