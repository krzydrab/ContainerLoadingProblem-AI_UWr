#include "Window.h"

namespace Visualisation
{
    namespace Engine
    {
        Window::Window(int width, int height, std::string title)
        {
            _window = nullptr;
            _width = width;
            _height = height;
            _title = title;
            _closed = false;
        }

        Window::~Window()
        {
            glfwDestroyWindow(_window);
            glfwTerminate();
            _window = nullptr;
        }

        void Window::create()
        {
            if (!glfwInit())
                throw std::string("Failed to initialize GLFW\n");

            glfwWindowHint(GLFW_SAMPLES, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            _window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);

            if (_window == NULL)
            {
                glfwTerminate();
                throw std::string("Failed to open GLFW window\n");
            }

            glfwMakeContextCurrent(_window);
            glewExperimental = GL_TRUE;

            if (glewInit() != GLEW_OK)
                throw std::string("Failed to initialize GLEW\n");

            glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);
            glfwSetCursorPos(_window, 1024 / 2, 768 / 2);
            glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        }

        void Window::swapBuffers()
        {
            glfwSwapBuffers(_window);
            glfwPollEvents();
        }

        bool Window::shouldClose()
        {
            if (_closed) return true;

            if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS
                || glfwWindowShouldClose(_window) == 1) return true;

            return false;
        }

        std::pair<double, double> Window::checkMouse()
        {
            double x_pos, y_pos;
            glfwGetCursorPos(_window, &x_pos, &y_pos);
            glfwSetCursorPos(_window, 1024 / 2, 768 / 2);
            return std::make_pair(x_pos, y_pos);
        }

        int Window::check1Key()
        {
            return glfwGetKey(_window, GLFW_KEY_1);
        }

        int Window::check2Key()
        {
            return glfwGetKey(_window, GLFW_KEY_2);
        }

        int Window::check3Key()
        {
            return glfwGetKey(_window, GLFW_KEY_3);
        }

        int Window::checkUpKey()
        {
            return glfwGetKey(_window, GLFW_KEY_UP);
        }

        int Window::checkDownKey()
        {
            return glfwGetKey(_window, GLFW_KEY_DOWN);
        }

        int Window::checkLeftKey()
        {
            return glfwGetKey(_window, GLFW_KEY_LEFT);
        }

        int Window::checkRightKey()
        {
            return glfwGetKey(_window, GLFW_KEY_RIGHT);
        }

        int Window::check_add_key()
        {
            return glfwGetKey(_window, GLFW_KEY_EQUAL);
        }

        int Window::check_subtract_key()
        {
            return glfwGetKey(_window, GLFW_KEY_MINUS);
        }

    }
}
