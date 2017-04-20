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

#include <cstdint>
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
