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
            SimulatedAnnealing(Utils::Container& container, std::vector<Utils::Package>& packages, CoolingSchedule func = LinearCooling);

            virtual bool run(int steps);

            void setCoolingSchedule(CoolingSchedule func);

        private:
            void makeMove(const double temperature);
            void takePakage(const double temperature, const float f1, Utils::Layer& layer);
            void putPackage(Utils::Layer& layer);
            double acceptanceFunc(const double temperature, const double f1, const double f2);
            void updateBestScores();

            CoolingSchedule _coolingSchedule;
            int _currentStep;
        };
    }
}

#endif /* CONTAINERLOADING_ALGORITHM_SIMULATEDANNEALING */
