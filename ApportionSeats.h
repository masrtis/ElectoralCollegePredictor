#pragma once

#include "PopulationData.h"

using RepresentativeSeats = std::array<std::int32_t, MaxStateId>;

class ApportionSeats
{
public:
    RepresentativeSeats apportion(PopulationEstimateYear year) const;
private:
    using Priorities = std::array<std::pair<StateId, double>, MaxStateId>;
    constexpr auto GenerateInitialPriorityValues(PopulationEstimateYear year) const;
};
