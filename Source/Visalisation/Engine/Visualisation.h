#ifndef VISUALISATION_H
#define VISUALISATION_H

#include "Window.h"
#include "Render.h"
#include "Camera.h"

namespace Visualisation
{
    class Visualisation
    {
    public:
        Visualisation();
        ~Visualisation();
        void init();
        void start();
        //bool loadData(const char * path);
        void check_input(GLfloat delta_time);

    private:
        Engine::Window *main_window;
        Engine::Camera *camera;
        Engine::Render *board;

    };





}








#endif