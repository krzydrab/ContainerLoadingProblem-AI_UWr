#ifndef RENDER_H
#define RENDER_H

#include "Camera.h"
#include "../../ContainerLoading/ContainerLoader.h"
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include <vector>

using namespace ContainerLoading::Utils;

namespace Visualisation
{
    namespace Engine
    {
        class Render
        {
        public:
            Render();
            ~Render();
            void draw(Camera *camera, Container& container);
            GLuint getProgramID();

        private:
            std::vector <glm::vec3> vertices;
            std::vector <glm::vec3> normals;
            Shader *shader;

            GLuint vertexbuffer;
            GLuint normalbuffer;
            GLuint VertexArrayID;
            GLuint color_location;

            void fillBuffers();
            void bindBuffers();
            void addGrid();
            void addContainer();
            void drawGrid();
            void drawContainer(Container& container, Camera *camera);
            void drawLayers(std::vector<Layer>& layers, Camera *camera);

        };
    }
}



#endif