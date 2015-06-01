#include "Camera.h"

//#include <iostream>

namespace Visualisation
{
    namespace Engine
    {
        Camera::Camera(GLuint n_programID)
        {
            programID = n_programID;
            position = glm::vec3(0.0f, 5.0f, 20.0f);
            direction = glm::vec3(0, 0, -1);
            up = glm::vec3(0, 1, 0);
            right = glm::vec3(1, 0, 0);
            horizontalAngle = 3.14f;
            verticalAngle = 0.0f;
            FoV = 45.0f;
            zoom_per_second = 1.0f;
            //speed = 5.0f;
            //speed = FoV * 0.25f;// / 2;
            //mouseSpeed = 0.0025f;
        }

        void Camera::init()
        {
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);

            view_location = glGetUniformLocation(programID, "View");
            if (view_location == -1) throw std::string("Uniform View variable not found.\n");

            projection_location = glGetUniformLocation(programID, "Projection");
            if (projection_location == -1) throw std::string("Uniform Projection variable not found.\n");

            model_location = glGetUniformLocation(programID, "Model");
            if (model_location == -1) throw std::string("Uniform Model variable not found.\n");

            camera_position_location = glGetUniformLocation(programID, "cameraPosition");
            if (camera_position_location == -1) throw std::string("Uniform cameraPosition variable not found.\n");


            Projection = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 300.0f);
            View = glm::lookAt
                (
                position,
                direction,
                up
                );

            Model = glm::mat4(1.0f);

            MVP = Projection * View * Model;
        }

        glm::mat4& Camera::getModelMatrix()
        {
            return Model;
        }

        const GLfloat* Camera::get_model_matrix()
        {
            return &Model[0][0];
        }

        GLuint Camera::get_model_location()
        {
            return model_location;
        }

        const GLfloat* Camera::get_view_matrix()
        {
            return &View[0][0];
        }

        GLuint Camera::get_view_location()
        {
            return view_location;
        }

        const GLfloat* Camera::get_projection_matrix()
        {
            return &Projection[0][0];
        }

        GLuint Camera::get_projection_location()
        {
            return projection_location;
        }
        /*
        void Camera::compute_orientation(double x_pos, double y_pos)
        {
            horizontalAngle += mouseSpeed * float(1024 / 2 - x_pos);
            verticalAngle += mouseSpeed * float(768 / 2 - y_pos);

            direction = glm::vec3(
                cos(verticalAngle) * sin(horizontalAngle),
                sin(verticalAngle),
                cos(verticalAngle) * cos(horizontalAngle)
                );

            right = glm::vec3(
                sin(horizontalAngle - 3.14f / 2.0f),
                0,
                cos(horizontalAngle - 3.14f / 2.0f)
                );

            up = glm::cross(right, direction);

            View = glm::lookAt(
                position,
                position + direction,
                up
                );
        }
        */
        void Camera::zoom_in(GLfloat delta_time)
        {
            FoV -= delta_time * zoom_per_second;

            if (FoV < 5.0f) FoV = 5.0f;

            //speed = FoV * 0.5f;
            Projection = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100000.0f);
        }

        void Camera::zoom_out(GLfloat delta_time)
        {
            FoV += delta_time * zoom_per_second;

            if (FoV > 80.0f) FoV = 80.0f;

            //speed = FoV * 0.5f;
            Projection = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100000.0f);
        }

        void Camera::rotate_left(GLfloat delta_time)
        {
            glm::vec3 upY = glm::vec3(0.0f, 1.0f, 0.0f);
            Model = glm::rotate(Model, -1.5f * delta_time, upY);
        }

        void Camera::rotate_right(GLfloat delta_time)
        {
            //glm::mat4 Correct = glm::rotate(Model, -90 * delta_time, up);
            glm::vec3 upY = glm::vec3(0.0f, 1.0f, 0.0f);
            Model = glm::rotate(Model, 1.5f * delta_time, upY);
            //up = glm::vec3(Correct * glm::vec4(up, 1));
        }

        glm::vec3 Camera::get_position()
        {
            glUniform3f(camera_position_location, position.x, position.y, position.z);

            return position;
        }

        void Camera::uniform_position()
        {
            glUniform3f(camera_position_location, position.x, position.y, position.z);
        }
    }
}