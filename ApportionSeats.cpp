#include "ApportionSeats.h"
#include <cmath>
#include <algorithm>
#include <utility>
#include "ConstexprFunctions.h"

constexpr auto ApportionSeats::GenerateInitialPriorityValues(PopulationEstimateYear year) const
{
    Priorities initialPriority;
    auto currentStateId{ StateId::ALABAMA };
    const auto estimateIndex{ GetPopulationArrayIndexFromYear(year) };
    constexpr auto divisor{ 1.0 / SquareRoot(2) };

    array_transform(c_statePopulationEstimates, initialPriority, [&, estimateIndex, divisor](PopulationEstimate populationEstimate)
    {
        return std::make_pair(currentStateId++, populationEstimate.m_data[estimateIndex] * divisor);
    });

    return initialPriority;
}

RepresentativeSeats ApportionSeats::apportion(PopulationEstimateYear year) const
{
    RepresentativeSeats currentSeatCount;
    array_fill(currentSeatCount, 1);

    Priorities currentPriority{ GenerateInitialPriorityValues(year) };

    const auto priorityPredicate{ [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; } };
    std::make_heap(begin(currentPriority), end(currentPriority), priorityPredicate);
    auto seatsFilled{ 50ui16 };

    constexpr auto totalSeats{ 435ui16 };
    const auto populationEstimateIndex{ GetPopulationArrayIndexFromYear(year) };

    while (seatsFilled < totalSeats)
    {
        std::pop_heap(begin(currentPriority), end(currentPriority), priorityPredicate);

        auto& nextSeat{ currentPriority.back() };
        const auto stateIndex{ static_cast<std::size_t>(nextSeat.first) };
        auto& stateSeatCount{ currentSeatCount[stateIndex] };
        ++stateSeatCount;
        nextSeat.second = c_statePopulationEstimates[stateIndex].m_data[populationEstimateIndex] / std::sqrt(stateSeatCount * (stateSeatCount + 1));

        std::push_heap(begin(currentPriority), end(currentPriority), priorityPredicate);

        ++seatsFilled;
    }

    return currentSeatCount;
}
