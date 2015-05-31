#include "Visualisation.h"

#include "../ContainerLoading/PackageGenerator.h"
#include "../ContainerLoading/Algorithm/ConstructionAlgorithm.h"

#include <iostream>

using namespace ContainerLoading;

namespace Visualisation
{

    Visualisation::Visualisation()
    {
        try
        {
            main_window = new Engine::Window(1024, 768, "Container loading");
            main_window->create();

            render = new Engine::Render();

            camera = new Engine::Camera(render->getProgramID());
            camera->init();

            Container container(Dimensions(5, 4, 5), 1);
            IPackageGenerator* generator = new PackageGenerator(container.getDimensions(), 5, 5);
            loader = new ContainerLoader(container, generator);
            Algorithm::IAlgorithm* alg = new Algorithm::ConstructionAlgorithm(loader->getContainer(), loader->getPackages());
            loader->applyAlgorithm(alg);
            loader->run(5000);
        }
        catch (std::string s)
        {
            std::cout << s << std::endl;
        }
    }

    Visualisation::~Visualisation()
    {
        delete(main_window);
        delete(render);
        delete(camera);
        delete(loader);
    }


    void Visualisation::start()
    {
        GLfloat current_time;
        GLfloat last_time = GLfloat(glfwGetTime());

        printf("Start\n");
        while (!main_window->shouldClose())
        {
            current_time = GLfloat(glfwGetTime());
            GLfloat delta_time = GLfloat(current_time - last_time);

            //std::pair<double, double> mouse_pos = main_window->check_mouse();
            //camera->compute_orientation(mouse_pos.first, mouse_pos.second);

            check_input(delta_time);
            camera->uniform_position();

            render->draw(camera, loader->getContainer());

            main_window->swapBuffers();
            last_time = current_time;
        }
    }

    void Visualisation::check_input(GLfloat delta_time)
    {
        if (main_window->check1Key())
        {
            //algo 1
        }

        if (main_window->check2Key())
        {
            //algo 2
        }

        if (main_window->check3Key())
        {
            //algo 3
        }

        if (main_window->checkLeftKey())
        {
            camera->rotate_left(delta_time);
        }

        if (main_window->checkRightKey())
        {
            camera->rotate_right(delta_time);
        }
    }
}