#ifndef CONTAINERLOADING_ALGORITHM_COOLINGSCHEDULE
#define CONTAINERLOADING_ALGORITHM_COOLINGSCHEDULE

#include <functional>
#include <glm/glm.hpp>

namespace ContainerLoading
{
    namespace Algorithm
    {
        namespace
        {
            typedef std::function< double (int) > CoolingSchedule;

            CoolingSchedule LinearCooling = [](int k) -> double { return 1.0 / k; };
            CoolingSchedule GeometricCooling = [](int k) -> double { return glm::pow(0.3, k); };
            CoolingSchedule LogarithmicCooling = [](int k) -> double { return 1.0/(1 + glm::log(k)); };
        }
    }
}

#endif /* CONTAINERLOADING_ALGORITHM_COOLINGSCHEDULE */
