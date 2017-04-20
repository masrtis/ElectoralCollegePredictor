/*

MIT License

Copyright(c) 2017 Michael Sharpe

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

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
