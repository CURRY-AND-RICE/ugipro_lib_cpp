#include <bits/stdc++.h>
using namespace std;

// エラトステネスの篩。n以下の素数を列挙
template <typename T>
vector<T> shieve(T n) {
    vector<bool> is_prime(n + 1, true);
    vector<T> primes;
    is_prime[0] = is_prime[1] = false;
    for (T i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (T j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return primes;
}

// 素因数分解。エラトステネスの篩で得られた素数リストを引数に取る
template <typename T>
vector< pair<T, int> > prime_factorization(T n, const vector<T>& primes) {
    vector< pair<T, int> > factors;
    for (T p : primes) {
        if (p * p > n) break;
        if (n % p != 0) continue;
        int count = 0;
        while (n % p == 0) {
            n /= p;
            count++;
        }
        factors.push_back({p, count});
    }
    if (n != 1) factors.push_back({n, 1});
    return factors;
}
