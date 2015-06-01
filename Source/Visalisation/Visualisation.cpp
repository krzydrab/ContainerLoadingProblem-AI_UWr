#include "Visualisation.h"

#include "../ContainerLoading/PackageGenerator.h"
#include "../ContainerLoading/Algorithm/ConstructionAlgorithm.h"
#include "../ContainerLoading/Algorithm/SimulatedAnnealing.h"
#include "../ContainerLoading/Algorithm/CoolingSchedule.h"
#include "../ContainerLoading/Algorithm/TabuSearch.h"

#include <iostream>

using namespace ContainerLoading;

namespace Visualisation
{

    Visualisation::Visualisation()
    {
        pressed = false;
        loader = nullptr;

        try
        {
            main_window = new Engine::Window(1024, 768, "Container loading");
            main_window->create();

            render = new Engine::Render();

            camera = new Engine::Camera(render->getProgramID());
            camera->init();

            initContainer();
            loader->applyAlgorithm(new Algorithm::ConstructionAlgorithm(loader->getContainer(), loader->getPackages()));
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

    void Visualisation::initContainer()
    {
        Container container(Dimensions(5, 4, 5), 1);
        IPackageGenerator* generator = new PackageGenerator(container.getDimensions(), 5, 5);

        if(loader != nullptr)
            delete loader;
            
        loader = new ContainerLoader(container, generator);

        delete generator;
    }

    void Visualisation::printResulst() const
    {
        std::cout << "Space filled: " << loader->getContainer().getFilledSpace() 
                  << "/" 
                  << loader->getContainer().getDimensions().capacity() 
                  << std::endl;

        int packages = loader->getContainer().countContainingPackages();
        std::cout << "Packages loaded: " << packages
                  << "/"
                  << loader->getPackages().size() + packages
                  << std::endl;
    }

    void Visualisation::check_input(GLfloat delta_time)
    {
        if (main_window->check1Key())
        {
            initContainer();
            loader->applyAlgorithm(new Algorithm::ConstructionAlgorithm(loader->getContainer(), loader->getPackages()));
        }

        if (main_window->check2Key())
        {
            initContainer();
            loader->applyAlgorithm(new Algorithm::SimulatedAnnealing(loader->getContainer(), loader->getPackages()));
        }

        if (main_window->check3Key())
        {
            initContainer();
            loader->applyAlgorithm(new Algorithm::TabuSearch(loader->getContainer(), loader->getPackages()));
        }

        if (main_window->checkUpKey() && !pressed)
        {
            pressed = true;
            loader->singleStep();
            printResulst();
        }

        if (main_window->checkDownKey() && !pressed)
        {
            pressed = true;
            loader->run(5000);
            printResulst();
        }

        if (main_window->checkLeftKey())
        {
            camera->rotate_left(delta_time);
        }

        if (main_window->checkRightKey())
        {
            camera->rotate_right(delta_time);
        }

        if (main_window->check_add_key())
        {
            camera->zoom_in(delta_time);
        }

        if (main_window->check_subtract_key())
        {
            camera->zoom_out(delta_time);
        }

        if (!main_window->checkUpKey() && !main_window->checkDownKey())
            pressed = false;
    }
}