#include "Render.h"

#include "../Model/Cube.h"

namespace Visualisation
{
    namespace Engine
    {
        Render::Render()
        {
            glGenVertexArrays(1, &VertexArrayID);
            glBindVertexArray(VertexArrayID);

            glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

            shader = new Shader("TransformVertexShader.vertexshader",
                                "TextureFragmentShader.fragmentshader");

            color_location = glGetUniformLocation(shader->getProgramID(), "color");
            if (color_location == -1) throw std::string("Uniform color variable not found.\n");

            fillBuffers();
            bindBuffers();
        }

        Render::~Render()
        {
            glDeleteBuffers(1, &vertexbuffer);
            glDeleteBuffers(1, &normalbuffer);
            glDeleteVertexArrays(1, &VertexArrayID);
        }

        void Render::draw(Camera *camera, Container& container)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glUseProgram(shader->getProgramID());

            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

            //glEnableVertexAttribArray(1);
            //glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
            //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

            glEnableVertexAttribArray(2);
            glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

            glUniformMatrix4fv(camera->get_projection_location(), 1, GL_FALSE, camera->get_projection_matrix());
            glUniformMatrix4fv(camera->get_view_location(), 1, GL_FALSE, camera->get_view_matrix());
            glUniformMatrix4fv(camera->get_model_location(), 1, GL_FALSE, camera->get_model_matrix());

            drawGrid();
            drawContainer(container, camera);
            drawLayers(container.getLayers(), camera);

            glDisableVertexAttribArray(0);
            glDisableVertexAttribArray(1);
            glDisableVertexAttribArray(2);
        }

        void Render::fillBuffers()
        {
            addGrid();
            addContainer();

            Model::Cube cube = Model::Cube();
            std::vector <glm::vec3> cubeVertices = cube.getVertices();
            std::vector <glm::vec3> cubeNormals = cube.getNormals();

            vertices.insert(vertices.end(), cubeVertices.begin(), cubeVertices.end());
            normals.insert(normals.end(), cubeNormals.begin(), cubeNormals.end());
        }

        GLuint Render::getProgramID()
        {
            return shader->getProgramID();
        }

        void Render::bindBuffers()
        {
            glGenBuffers(1, &vertexbuffer);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

            glGenBuffers(1, &normalbuffer);
            glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
            glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

            //glGenBuffers(1, &colorbuffer);
            //glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
            //glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), &colors[0], GL_STATIC_DRAW);
        }


        void Render::addGrid()
        {     
            for (int i = -10; i <= 10; i++)
            {
                vertices.push_back(glm::vec3(i*1.0f, 0.0f, -10.0f));
                normals.push_back(glm::vec3(0.0f, 0.0f, 0.0f));

                vertices.push_back(glm::vec3(i*1.0f, 0.0f, 10.0f));
                normals.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
            }

            for (int i = -10; i <= 10; i++)
            {
                vertices.push_back(glm::vec3(10.0f, 0.0f, i*1.0f));
                normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

                vertices.push_back(glm::vec3(-10.0f, 0.0f, i*1.0f));
                normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
            }
        }

        void Render::addContainer()
        {
            glm::vec3 A1(0.0f, 0.0f, 0.0f);
            glm::vec3 B1(1.0f, 0.0f, 0.0f);
            glm::vec3 C1(1.0f, 0.0f, 1.0f);
            glm::vec3 D1(0.0f, 0.0f, 1.0f);
            glm::vec3 A2(0.0f, 1.0f, 0.0f);
            glm::vec3 B2(1.0f, 1.0f, 0.0f);
            glm::vec3 C2(1.0f, 1.0f, 1.0f);
            glm::vec3 D2(0.0f, 1.0f, 1.0f);
            glm::vec3 normal(0.0f, 0.0f, 0.0f);

            vertices.push_back(A1);
            normals.push_back(normal);
            vertices.push_back(B1);
            normals.push_back(normal);
            vertices.push_back(A1);
            normals.push_back(normal);
            vertices.push_back(D1);
            normals.push_back(normal);
            vertices.push_back(B1);
            normals.push_back(normal);
            vertices.push_back(C1);
            normals.push_back(normal);
            vertices.push_back(D1);
            normals.push_back(normal);
            vertices.push_back(C1);
            normals.push_back(normal);

            vertices.push_back(A2);
            normals.push_back(normal);
            vertices.push_back(B2);
            normals.push_back(normal);
            vertices.push_back(A2);
            normals.push_back(normal);
            vertices.push_back(D2);
            normals.push_back(normal);
            vertices.push_back(B2);
            normals.push_back(normal);
            vertices.push_back(C2);
            normals.push_back(normal);
            vertices.push_back(D2);
            normals.push_back(normal);
            vertices.push_back(C2);
            normals.push_back(normal);

            vertices.push_back(A1);
            normals.push_back(normal);
            vertices.push_back(A2);
            normals.push_back(normal);
            vertices.push_back(B1);
            normals.push_back(normal);
            vertices.push_back(B2);
            normals.push_back(normal);
            vertices.push_back(C1);
            normals.push_back(normal);
            vertices.push_back(C2);
            normals.push_back(normal);
            vertices.push_back(D1);
            normals.push_back(normal);
            vertices.push_back(D2);
            normals.push_back(normal);
        }

        void Render::drawGrid()
        {
            glUniform3f(color_location, 0.0f, 0.0f, 0.0f);
            glDrawArrays(GL_LINES, 0, 84);
        }

        void Render::drawContainer(Container& container, Camera *camera)
        {
            glm::vec3 position = container.getPosition();
            glm::vec3 scale = container.getDimensions().asVec3();
            glm::mat4 currentModel = camera->getModelMatrix();

            glm::mat4 model = glm::translate(currentModel, position) * glm::scale(glm::mat4(1), scale);

            glm::vec3 color(0.0f, 0.0f, 1.0f);

            glUniformMatrix4fv(camera->get_model_location(), 1, GL_FALSE, &model[0][0]);
            glUniform3f(color_location, color.x, color.y, color.z);
            glDrawArrays(GL_LINES, 84, 24);
        }


        void Render::drawLayers(std::vector<Layer>& layers, Camera *camera)
        {
            for (auto &layer : layers)
            {
                std::vector <Package>& packages = layer.getPackages();

                for (auto &package : packages)
                {
                    glm::vec3 position = package.getPosition();
                    glm::vec3 scale = package.getDimensions().asVec3();
                    glm::vec3 color = package.getColor();
                    glm::mat4 currentModel = camera->getModelMatrix();

                    glm::mat4 model =  glm::translate(currentModel, position) * glm::scale(glm::mat4(1), scale);

                    //glm::vec3 color((GLfloat)rand() / (RAND_MAX), (GLfloat)rand() / (RAND_MAX), (GLfloat)rand() / (RAND_MAX));
                    
                    glUniformMatrix4fv(camera->get_model_location(), 1, GL_FALSE, &model[0][0]);
                    glUniform3f(color_location, color.x, color.y, color.z);
                    glDrawArrays(GL_TRIANGLES, 84 + 24, vertices.size() - (84 + 24));
                }
            }
        }



    }
    
}