#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Visualisation
{
    namespace Engine
    {
        class Camera
        {
        public:
            Camera(GLuint n_programID);
            void init();
            const GLfloat* get_model_matrix();
            GLuint get_model_location();
            const GLfloat* get_view_matrix();
            GLuint get_view_location();
            const GLfloat* get_projection_matrix();
            GLuint get_projection_location();

            void compute_orientation(double x_pos, double y_pos);
            void zoom_in(GLfloat delta_time);
            void zoom_out(GLfloat delta_time);
            void rotate_left(GLfloat delta_time);
            void rotate_right(GLfloat delta_time);
            glm::vec3 get_position();
            void uniform_position();
            glm::mat4& getModelMatrix();

        private:
            glm::mat4 Projection;
            glm::mat4 View;
            glm::mat4 Model;
            glm::mat4 MVP;

            GLuint programID;
            GLuint view_location;
            GLuint projection_location;
            GLuint model_location;
            GLuint camera_position_location;

            glm::vec3 right;
            glm::vec3 up;
            glm::vec3 direction;

            glm::vec3 position;
            float horizontalAngle;
            float verticalAngle;
            float FoV;

            //float speed;
            //float mouseSpeed;
            GLfloat zoom_per_second;
        };
    }
}




#endif