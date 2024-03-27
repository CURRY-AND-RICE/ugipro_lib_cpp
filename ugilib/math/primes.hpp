#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace ugilib {
/**
 * @brief エラトステネスの篩
 * @tparam T 整数型
 * @param n 素数の上限. nを含む
 * @return vector<T> 素数リスト
 * @note O(n log log n)
 * @note jに代入される数の最大値はN^2なのでオーバーフローに注意
*/
template <typename T>
vector<T> shieve(const T &n) {
    vector<bool> is_prime(n + 1, true);
    vector<T> primes;
    is_prime[0] = is_prime[1] = false;
    for (T i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (T j = i * i; 0 <= j && j <= n; j += i) {  // オーバーフローに注意
            is_prime[j] = false;
        }
    }
    return primes;
}

/**
 * @brief 素因数分解. 素数リストを用いる
 * @tparam T 整数型
 * @param n 素因数分解する数
 * @param primes 素数リスト. shieveで取得したものを使う
 * @return vector<pair<T, int>> 素因数とその個数
 * @note O(sqrt(n)) より高速. shieveに時間がかかり，メモリをより消費する
*/
template <typename T>
vector<pair<T, int>> prime_factorization_with_shieve(T n, const vector<T>& primes) {
    vector<pair<T, int>> factors;  // 素因数とその個数
    for (const T &p : primes) {
        if (p * p > n) break;
        if (n % p != 0) continue;
        int count = 0;
        while (n % p == 0) {
            n /= p;
            count++;
        }
        factors.push_back({p, count});
    }
    if (n != 1) factors.push_back({n, 1});  // nが素数の場合
    return factors;
}

/**
 * @brief 素因数分解
 * @tparam T 整数型
 * @param n 素因数分解する数
 * @return vector<pair<T, int>> 素因数とその個数
 * @note O(sqrt(n))
*/
template <typename T>
vector<pair<T, int>> prime_factorization(T n) {
    vector<pair<T, int>> factors;
    for (T i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        factors.push_back({i, count});
    }
    if (n != 1) factors.push_back({n, 1});  // nが素数の場合
    return factors;
}
} // namespace ugilib
