#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Visalisation/Visualisation.h"
using namespace ContainerLoading;
#include "ContainerLoading/Algorithm/SimulatedAnnealing.h"
int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    
    /*Container container(Dimensions(5, 4, 5), 1);
    IPackageGenerator* generator = new PackageGenerator(container.getDimensions(), 5, 5);
    ContainerLoader *loader = new ContainerLoader(container, generator);
    Algorithm::IAlgorithm* alg = new Algorithm::SimulatedAnnealing(loader->getContainer(), loader->getPackages());
    loader->applyAlgorithm(alg);
    loader->run(10000);*/
    Visualisation::Visualisation visualisation;
    visualisation.start();

    return 0;
}