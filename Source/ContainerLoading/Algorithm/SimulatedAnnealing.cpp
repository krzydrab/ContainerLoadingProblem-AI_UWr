#include "SimulatedAnnealing.h"
#include <GL/glew.h>
#include <iostream>

namespace ContainerLoading
{
    namespace Algorithm
    {
        SimulatedAnnealing::SimulatedAnnealing(Utils::Container& container, std::vector<Utils::Package>& packages, CoolingSchedule func)
            : IAlgorithm(container, packages)
        {
            _currentStep = 0;
            _coolingSchedule = func;
        }

        bool SimulatedAnnealing::run(int steps)
        {
            double temperature = _coolingSchedule(_currentStep);

            while(steps--)
            {
                makeMove(temperature);
                temperature = _coolingSchedule(++_currentStep);
            }

            return true;
        }

        void SimulatedAnnealing::makeMove(const double temperature)
        {
            float f1 = _container.getFilledSpace();

            std::vector<Utils::Layer>& layers = _container.getLayers();
            Utils::Layer& layer = layers[rand() % layers.size()];

            unsigned nbOfPackages = layer.getPackages().size() + _packages.size();

            if(layer.getPackages().size() == 0 || rand() % 2)
            {
                putPackage(layer);
            }
            else
            {
                takePakage(temperature, f1, layer);
            }
        }

        void SimulatedAnnealing::putPackage(Utils::Layer& layer)
        {
            Utils::Package& p = _packages[rand() % _packages.size()];
            std::swap(p, _packages[_packages.size()-1]);

            if(layer.tryPut(_packages.back()))
                _packages.pop_back();
        }

        void SimulatedAnnealing::takePakage(const double temperature, const float f1, Utils::Layer& layer)
        {
            _packages.push_back(layer.takeTopPackage());
            float random = (GLfloat)rand() / (RAND_MAX);
            float f2 = f1 - _packages.back().getDimensions().capacity();

            if(random > acceptanceFunc(temperature, f1, f2))
            {
                layer.tryPut(_packages.back());
                _packages.pop_back();
            }
        }

        double SimulatedAnnealing::acceptanceFunc(const double temperature, const double f1, const double f2)
        {
            return glm::exp(-(glm::abs(f1 - f2)/temperature));
        }

        void SimulatedAnnealing::setCoolingSchedule(CoolingSchedule func)
        {
            _coolingSchedule = func;
        }
    }
}
