#include <bits/stdc++.h>
using namespace std;

// 約数列挙
template <typename T>
unordered_set<T> enum_divisors(T n) {
    unordered_set<T> divisors;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    return divisors;
}

