#include <iostream>

#include "Visalisation\Visualisation.h"

#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    std::cout << "Initial hello world" << std::endl;

    Visualisation::Visualisation visualisation;

    visualisation.start();


    return 0;
}