#include "Cube.h"


namespace Visualisation
{
    namespace Model
    {
        Cube::Cube()
        {
            renderingMode = GL_TRIANGLES;

            initVertices();
            initNormals();
        }

        int Cube::getNumberOfVertices()
        {
            return vertices.size();
        }

        void Cube::initVertices() 
        {
            glm::vec3 A1(0.0f, 0.0f, 0.0f);
            glm::vec3 B1(1.0f, 0.0f, 0.0f);
            glm::vec3 C1(1.0f, 0.0f, 1.0f);
            glm::vec3 D1(0.0f, 0.0f, 1.0f);
            glm::vec3 A2(0.0f, 1.0f, 0.0f);
            glm::vec3 B2(1.0f, 1.0f, 0.0f);
            glm::vec3 C2(1.0f, 1.0f, 1.0f);
            glm::vec3 D2(0.0f, 1.0f, 1.0f);

            vertices.resize(36);
            // top
            vertices[0] = A2;
            vertices[1] = D2;
            vertices[2] = B2;
            vertices[3] = B2;
            vertices[4] = D2;
            vertices[5] = C2;
            // bottom
            vertices[6] = A1;
            vertices[7] = D1;
            vertices[8] = B1;
            vertices[9] = B1;
            vertices[10] = D1;
            vertices[11] = C1;
            // left
            vertices[12] = A1;
            vertices[13] = D1;
            vertices[14] = D2;
            vertices[15] = A1;
            vertices[16] = D2;
            vertices[17] = A2;
            // right
            vertices[18] = B1;
            vertices[19] = C1;
            vertices[20] = C2;
            vertices[21] = B1;
            vertices[22] = C2;
            vertices[23] = B2;
            // front
            vertices[24] = D1;
            vertices[25] = C1;
            vertices[26] = D2;
            vertices[27] = C1;
            vertices[28] = D2;
            vertices[29] = C2;
            // back
            vertices[30] = A1;
            vertices[31] = B1;
            vertices[32] = B2;
            vertices[33] = A1;
            vertices[34] = B2;
            vertices[35] = A2;
        }

        void Cube::initNormals() 
        {
            glm::vec3 sidesNormals[6] = 
            {
                -glm::vec3(0.0f, 1.0f, 0.0f),
                -glm::vec3(0.0f, -1.0f, 0.0f),
                -glm::vec3(-1.0f, 0.0f, 0.0f),
                -glm::vec3(1.0f, 0.0f, 0.0f),
                -glm::vec3(0.0f, 0.0f, -1.0f),
                -glm::vec3(0.0f, 0.0f, 1.0f)
            };

            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    normals.push_back(sidesNormals[i]);
        }

        std::vector<glm::vec3>& Cube::getVertices()
        {
            return vertices;
        }

        std::vector<glm::vec3>& Cube::getNormals() 
        {
            return normals;
        }

        GLuint Cube::getRenderingMode() const 
        {
            return renderingMode;
        }
    }


}