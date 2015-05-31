#include "SimulatedAnnealing.h"

namespace ContainerLoading
{
    namespace Algorithm
    {
        SimulatedAnnealing::SimulatedAnnealing(Utils::Container& container, std::vector<Utils::Package>& packages)
            : IAlgorithm(container, packages)
        {
            _currentStep = 0;
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
            ;
        }

        void SimulatedAnnealing::setCoolingSchedule(CoolingSchedule func)
        {
            _coolingSchedule = func;
        }
    }
}
