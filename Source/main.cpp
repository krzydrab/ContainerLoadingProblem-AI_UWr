#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Visalisation/Visualisation.h"

using namespace ContainerLoading;

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    Visualisation::Visualisation visualisation;
    visualisation.start();

    return 0;
}