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

#include <array>
#include <cstdint>
#include <tuple>
#include <utility>

constexpr double InRangeOpenHigh(double x, const std::pair<double, double>& range) noexcept
{
    return x >= range.first && x < range.second;
}

constexpr double TenToTheNth(std::uint32_t exponent) noexcept
{
    if (exponent == 0)
    {
        return 1.0;
    }

    double result = 10.0;
    while (exponent > 1)
    {
        result *= 10.0;
        --exponent;
    }

    return result;
}

constexpr double SquareRootEstimate(std::uint32_t x, double guess) noexcept
{
    return 0.5 * (guess + (x / guess));
}

constexpr double SquareRoot(std::uint32_t x) noexcept
{
    if (x == 0)
    {
        return 0.0;
    }

    std::uint32_t exponent = 0;
    double seed = x;
    constexpr auto seedRange(std::make_pair(1.0, 100.0));
    while (!InRangeOpenHigh(seed, seedRange))
    {
        seed /= 10.0;
        ++exponent;
    }

    auto guess(TenToTheNth(exponent));

    if (seed < 10.0)
    {
        guess *= 2.0;
    }
    else
    {
        guess *= 6.0;
    }

    auto maxIterations = exponent + 5;

    for (auto i = 0u; i < maxIterations; ++i)
    {
        guess = SquareRootEstimate(x, guess);
    }

    return guess;
}

template <typename sourceType, typename destType, size_t size, typename Func>
constexpr void array_transform(const std::array<sourceType, size>& source, std::array<destType, size>& dest, Func op) noexcept(noexcept(op(*cbegin(source))))
{
    auto destIter(begin(dest));
    for (auto sourceIter = cbegin(source), sourceEnd = cend(source); sourceIter != sourceEnd; ++sourceIter, ++destIter)
    {
        *destIter = op(*sourceIter);
    }
}

template <typename source1Type, typename source2Type, typename destType, size_t size, typename Func>
constexpr void array_transform(const std::array<source1Type, size>& left, const std::array<source2Type, size>& right, std::array<destType, size>& dest, Func op) noexcept(noexcept(op(*cbegin(left), *cbegin(right))))
{
    auto leftIter(cbegin(left)), leftEnd(cend(left));
    auto rightIter(cbegin(right));
    auto destIter(begin(dest));

    for (; leftIter != leftEnd; ++leftIter, ++rightIter, ++destIter)
    {
        *destIter = op(*leftIter, *rightIter);
    }
}

template <typename T, size_t size>
constexpr void array_fill(std::array<T, size>& dest, T element)
{
    for (size_t index = 0; index < size; ++index)
    {
        dest[index] = element;
    }
}

/*
    https://godbolt.org/g/6h7BYR - Compiler example for clang 4.0, gcc 7, and MSVC 2017 RTM
    http://stackoverflow.com/q/37029886/1181561 - How to convert an array to a tuple
    http://stackoverflow.com/a/10621270/1181561 - How to convert a tuple to an array
*/

template<typename T, typename... U>
using Array = std::array<T, 1 + sizeof...(U)>;

template<typename T, typename... U, size_t... I>
constexpr auto tuple_to_array_internal(const std::tuple<T, U...>& t, std::index_sequence<I...>)
{
    return Array<T, U...>{ std::get<I>(t)... };
}

template<typename... T>
constexpr auto tuple_to_array(const std::tuple<T...>& t)
{
    using IndexTuple = std::index_sequence_for<T...>;
    return tuple_to_array_internal(t, IndexTuple());
}

template <typename T, size_t size, size_t... Indices>
constexpr auto array_to_tuple(const std::array<T, size>& source, std::index_sequence<Indices...>)
{
    return std::make_tuple(source[Indices]...);
}

template <typename T, size_t Size>
constexpr auto array_append(const std::array<T, Size>& source, T nextElement)
{
    using ArrayIndices = std::make_index_sequence<Size>;
    return tuple_to_array(tuple_cat(array_to_tuple(source, ArrayIndices()), std::make_tuple(std::move(nextElement))));
}
