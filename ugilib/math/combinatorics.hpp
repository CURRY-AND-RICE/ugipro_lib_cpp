#pragma once

/**
 * @file combinatorics.hpp
 * @brief 組み合わせ計算の関数の定義. perm(), comb(), fact().
*/

#include <bits/stdc++.h>
#include "ugilib/base/definitions.hpp"
#include "ugilib/base/constants.hpp"
#include "ugilib/math/invmod.hpp"

using namespace std;

namespace ugilib {
    /**
     * @brief nPrを求める
     * @tparam T 整数型
     * @param n n
     * @param r r
     * @param mod mod
     * @return T nPr
     * @note O(r)
    */
    template <typename T>
    T perm(T n, T r, T mod = ugilib::constants::INF<T>) {
        assert(n >= 0 && r >= 0);
        if (r > n) return 0;
        if (r == 0) return 1;

        T res = 1;
        for (T i = 0; i < r; i++) {
            res = res * (n - i) % mod;
        }
        return res;
    }

    /**
     * @brief n!を求める
     * @tparam T 整数型
     * @param n n
     * @param mod mod
     * @return T n!
     * @note O(n)
     */
    template <typename T>
    T fact(T n, T mod = ugilib::constants::INF<T>) {
        assert(n >= 0);
        return perm(n, n-1, mod);
    }

    /**
     * @brief nCrを求める
     * @tparam T 整数型
     * @param n n
     * @param r r
     * @param mod mod
     * @return T nCr
     * @note O(r)
     */
    template <typename T>
    T comb(T n, T r, T mod = ugilib::constants::INF<T>) {
        assert(n >= 0 && r >= 0);
        if (r > n) return 0;

        r = min(r, n-r);
        if (r == 0) return 1;

        T numer = perm(n, r, mod);
        T denom = fact(r, mod);

        assert(denom != 0);

        return (numer * invmod(denom, mod)) % mod;
    }
}