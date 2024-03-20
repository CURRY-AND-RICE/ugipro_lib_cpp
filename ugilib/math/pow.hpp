#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/definitions.hpp"

namespace ugilib {
/**
 * @brief 繰り返し二乗法
 * @param x 基数
 * @param n 指数
 * @param mod mod
 * @return x^n % mod
 * @note O(log n)
*/
template <typename T>
T fast_pow(T x, ll n, ll mod = ugilib::constants::INF<ll>) {
    assert(n >= 0);
    T res = 1;
    while (n) {
        if (n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}
}  // namespace ugilib
