#ifndef CONTAINERLOADING_ALGORITHM_SIMULATEDANNEALING
#define CONTAINERLOADING_ALGORITHM_SIMULATEDANNEALING

#include "IAlgorithm.h"
#include "CoolingSchedule.h"

namespace ContainerLoading
{
    namespace Algorithm
    {
        class SimulatedAnnealing : public IAlgorithm
        {
        public:
            SimulatedAnnealing(Utils::Container& container, std::vector<Utils::Package>& packages);

            virtual bool run(int steps);

            void setCoolingSchedule(CoolingSchedule func);

        private:
            void makeMove(const double temperature);

            CoolingSchedule _coolingSchedule;
            int _currentStep;
        };
    }
}

#endif /* CONTAINERLOADING_ALGORITHM_SIMULATEDANNEALING */
