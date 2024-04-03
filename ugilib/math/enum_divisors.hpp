#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace ugilib {
    /**
     * @brief 約数列挙. 結果はソート済み
     * @tparam T 整数型
     * @param n 約数列挙する数
     * @return vector<T> 約数リスト
     * @note O(sqrt(n))
    */
    template <typename T>
    vector<T> enum_divisors(T n) {
        vector<T> divisors_front;
        deque<T> divisors_back;
        for (T i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors_front.push_back(i);
                if (i * i != n) divisors_back.push_front(n / i);
            }
        }
        divisors_front.insert(divisors_front.end(), divisors_back.begin(), divisors_back.end());
        return divisors_front;
    }

    /**
     * @brief 約数列挙. 素因数分解の結果を用いる. 結果はソートされていない
     * @tparam T 整数型
     * @param n 約数列挙する数
     * @param factors 素因数分解の結果
     * @return vector<T> 約数リスト
     * @note O(Πc_i) (c_iは素因数分解の指数)
     * @note 結果がソートされていないことに注意
     */
    template <typename T>
    vector<T> enum_divisors_with_prime_factors(T n, const vector<pair<T, int>>& factors) {
        vector<T> divisors = {1};
        for (const auto& [p, c] : factors) {
            vector<T> new_divisors;
            for (T d : divisors) {
                T mul = 1;
                for (int i = 0; i < c; i++) {
                    mul *= p;
                    new_divisors.push_back(d * mul);
                }
            }
            divisors.insert(divisors.end(), new_divisors.begin(), new_divisors.end());
        }
        return divisors;
    }
} // namespace ugilib
