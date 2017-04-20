#include "PopulationData.h"
#include "ApportionSeats.h"
#include <iostream>
#include <ios>
#include <functional>
#include "ConstexprFunctions.h"

int main()
{
    const ApportionSeats seatApportioner;
    
    const auto previousCensus{ seatApportioner.apportion(c_lastCensusYear) };

    for (auto year = c_lastCensusYear; year <= c_endEstimateYear; ++year)
    {
        std::cout << "House seats for " << year << ":\n";

        auto results{ seatApportioner.apportion(year) };
        decltype(results) changeInSeats;
        array_transform(results, previousCensus, changeInSeats, std::minus<std::int32_t>());

        for (auto state = StateId::ALABAMA; state < StateId::MAX_STATE_ID; ++state)
        {
            auto stateAsIndex{ static_cast<std::size_t>(state) };
            std::cout << "Seats in " << GetStateName(state) << ": " << results[stateAsIndex];
            if (changeInSeats[stateAsIndex] != 0)
            {
                std::cout << " (" << std::showpos << changeInSeats[stateAsIndex] << std::noshowpos << ')';
            }

            std::cout << '\n';
        }

        std::cout << std::endl;
    }

    return 0;
}
