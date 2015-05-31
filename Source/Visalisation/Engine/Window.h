#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <glm/glm.hpp>
#include <string>

namespace Visualisation
{
    namespace Engine
    {
        class Window
        {
        public:
            Window(int width, int height, std::string title);
            ~Window();
            void create();
            void swapBuffers();
            bool shouldClose();
            //void close();

            std::pair<double, double> checkMouse();

            int check1Key();
            int check2Key();
            int check3Key();

        private:
            int _width;
            int _height;
            std::string _title;
            GLFWwindow *_window;
            bool _closed;
        };
    }
}




#endif