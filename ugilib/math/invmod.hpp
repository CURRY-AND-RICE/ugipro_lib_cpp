#pragma once

/**
 * @file invmod.hpp
 * @brief 逆元計算の関数の定義. invmod().
*/

#include <bits/stdc++.h>
#include "ugilib/base/definitions.hpp"
#include "ugilib/base/constants.hpp"

using namespace std;

namespace ugilib {
    /**
     * @brief 拡張ユークリッドの互除法
     * @tparam T 整数型
     * @param a a
     * @param b b
     * @param x x
     * @param y y
     * @return T gcd(a, b)
     * @note O(log^2(max(a, b)))
     * @note ax + by = gcd(a, b)を満たすx, yを求める
    */
    template <typename T>
    T extended_gcd(T a, T b, T& x, T& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        T gcd = extended_gcd(b, a % b, x, y);
        T tmp = x;
        x = y;
        y = tmp - a / b * y;
        return gcd;
    }

    /**
     * @brief aのmodにおける逆元を求める
     * @tparam T 整数型
     * @param a a
     * @param mod mod
     * @return T aのmodにおける逆元
     * @note O(log^2(mod))
     * @note modが素数であり、互いに素であることが前提
    */
    template <typename T>
    T invmod(T a, T mod) {
        T x, y;
        T gcd = extended_gcd(a, mod, x, y);
        assert(gcd == 1);
        return (x % mod + mod) % mod;
    }
}
