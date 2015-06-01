#ifndef VISUALISATION_H
#define VISUALISATION_H

#include "Engine/Window.h"
#include "Engine/Render.h"
#include "Engine/Camera.h"
#include "../ContainerLoading/ContainerLoader.h"


namespace Visualisation
{
    class Visualisation
    {
    public:
        Visualisation();
        ~Visualisation();
        void start();
        void printResulst();

    private:
        void check_input(GLfloat delta_time);
        void initContainer();

        Engine::Window *main_window;
        Engine::Camera *camera;
        Engine::Render *render;
        ContainerLoading::ContainerLoader *loader;
        bool pressed;
    };
}




#endif