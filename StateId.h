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

#pragma once

enum class StateId : std::size_t
{
    ALABAMA = 0,
    ALASKA,
    ARIZONA,
    ARKANSAS,
    CALIFORNIA,
    COLORADO,
    CONNECTICUT,
    DELAWARE,
    FLORIDA,
    GEORGIA,
    HAWAII,
    IDAHO,
    ILLINOIS,
    INDIANA,
    IOWA,
    KANSAS,
    KENTUCKY,
    LOUISIANA,
    MAINE,
    MARYLAND,
    MASSACHUSETTS,
    MICHIGAN,
    MINNESOTA,
    MISSISSIPPI,
    MISSOURI,
    MONTANA,
    NEBRASKA,
    NEVADA,
    NEW_HAMPSHIRE,
    NEW_JERSEY,
    NEW_MEXICO,
    NEW_YORK,
    NORTH_CAROLINA,
    NORTH_DAKOTA,
    OHIO,
    OKLAHOMA,
    OREGON,
    PENNSYLVANIA,
    RHODE_ISLAND,
    SOUTH_CAROLINA,
    SOUTH_DAKOTA,
    TENNESSEE,
    TEXAS,
    UTAH,
    VERMONT,
    VIRGINIA,
    WASHINGTON,
    WEST_VIRGINIA,
    WISCONSIN,
    WYOMING,
    MAX_STATE_ID
};

constexpr auto MaxStateId{ static_cast<std::size_t>(StateId::MAX_STATE_ID) };

constexpr auto operator++(StateId& value) noexcept
{
    if (value != StateId::MAX_STATE_ID)
    {
        value = static_cast<StateId>(static_cast<uint8_t>(value) + 1);
    }
    return value;
}

constexpr auto operator++(StateId& value, int) noexcept
{
    const auto oldValue{ value };
    ++value;
    return oldValue;
}

constexpr auto GetStateName(StateId state) noexcept
{
    switch (state)
    {
    case StateId::ALABAMA:
        return "Alabama";
    case StateId::ALASKA:
        return "Alaska";
    case StateId::ARIZONA:
        return "Arizona";
    case StateId::ARKANSAS:
        return "Arkansas";
    case StateId::CALIFORNIA:
        return "California";
    case StateId::COLORADO:
        return "Colorado";
    case StateId::CONNECTICUT:
        return "Connecticut";
    case StateId::DELAWARE:
        return "Delaware";
    case StateId::FLORIDA:
        return "Florida";
    case StateId::GEORGIA:
        return "Georgia";
    case StateId::HAWAII:
        return "Hawaii";
    case StateId::IDAHO:
        return "Idaho";
    case StateId::ILLINOIS:
        return "Illinois";
    case StateId::INDIANA:
        return "Indiana";
    case StateId::IOWA:
        return "Iowa";
    case StateId::KANSAS:
        return "Kansas";
    case StateId::KENTUCKY:
        return "Kentucky";
    case StateId::LOUISIANA:
        return "Louisiana";
    case StateId::MAINE:
        return "Maine";
    case StateId::MARYLAND:
        return "Maryland";
    case StateId::MASSACHUSETTS:
        return "Massachusetts";
    case StateId::MICHIGAN:
        return "Michigan";
    case StateId::MINNESOTA:
        return "Minnesota";
    case StateId::MISSISSIPPI:
        return "Mississippi";
    case StateId::MISSOURI:
        return "Missouri";
    case StateId::MONTANA:
        return "Montana";
    case StateId::NEBRASKA:
        return "Nebraska";
    case StateId::NEVADA:
        return "Nevada";
    case StateId::NEW_HAMPSHIRE:
        return "New Hampshire";
    case StateId::NEW_JERSEY:
        return "New Jersey";
    case StateId::NEW_MEXICO:
        return "New Mexico";
    case StateId::NEW_YORK:
        return "New York";
    case StateId::NORTH_CAROLINA:
        return "North Carolina";
    case StateId::NORTH_DAKOTA:
        return "North Dakota";
    case StateId::OHIO:
        return "Ohio";
    case StateId::OKLAHOMA:
        return "Oklahoma";
    case StateId::OREGON:
        return "Oregon";
    case StateId::PENNSYLVANIA:
        return "Pennsylvania";
    case StateId::RHODE_ISLAND:
        return "Rhode Island";
    case StateId::SOUTH_CAROLINA:
        return "South Carolina";
    case StateId::SOUTH_DAKOTA:
        return "South Dakota";
    case StateId::TENNESSEE:
        return "Tennessee";
    case StateId::TEXAS:
        return "Texas";
    case StateId::UTAH:
        return "Utah";
    case StateId::VERMONT:
        return "Vermont";
    case StateId::VIRGINIA:
        return "Virginia";
    case StateId::WASHINGTON:
        return "Washington";
    case StateId::WEST_VIRGINIA:
        return "West Virginia";
    case StateId::WISCONSIN:
        return "Wisconsin";
    case StateId::WYOMING:
        return "Wyoming";
    default:
        return "Unknown state";
    }
}
