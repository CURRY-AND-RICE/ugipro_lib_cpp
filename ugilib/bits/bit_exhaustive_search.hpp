#pragma once
#include <bits/stdc++.h>
#include "ugilib/bits/bit_util.hpp"

namespace ugilib {
/**
 * @brief bit_exhaustive_search
 * @param digit the number of bits
 * @param f a function to be called with bits
 * @details exhaustive search for bits
 *
 * @example
 * vector<int> ans;
 * auto f = [&](const auto &&bits) {
 *    if (count(bits.begin(), bits.end(), true) == 2) {
 *        ans.push_back(bits_to_num(bits));
 *    }
 *    return false;
 * };
 * bit_exhaustive_search(4, f);
 * // ans = {3, 5, 6, 9, 10, 12}
 *
*/
template <typename Func>
void bit_exhaustive_search(const size_t &digit, Func f) {
    for (ll i = 0; i < (1 << digit); i++) {
        bool will_break = f(num_to_bits(i, digit));
        if (will_break) break;
    }
}
}  // namespace ugilib
