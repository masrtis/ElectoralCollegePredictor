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
