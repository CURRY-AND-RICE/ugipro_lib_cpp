---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/enum_divisors.test.cpp
    title: tests/math/enum_divisors.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/prime_enumerate.test.cpp
    title: tests/math/prime_enumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/prime_fuctorization.test.cpp
    title: tests/math/prime_fuctorization.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
    links: []
  bundledCode: "#line 2 \"ugilib/math/primes.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nnamespace ugilib {\n/**\n * @brief \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\n * @tparam T \u6574\u6570\u578B\n * @param n \u7D20\
    \u6570\u306E\u4E0A\u9650. n\u3092\u542B\u3080\n * @return vector<T> \u7D20\u6570\
    \u30EA\u30B9\u30C8\n * @note O(n log log n)\n * @note j\u306B\u4EE3\u5165\u3055\
    \u308C\u308B\u6570\u306E\u6700\u5927\u5024\u306FN^2\u306A\u306E\u3067\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n*/\ntemplate <typename T>\n\
    vector<T> shieve(const T &n) {\n    vector<bool> is_prime(n + 1, true);\n    vector<T>\
    \ primes;\n    is_prime[0] = is_prime[1] = false;\n    for (T i = 2; i <= n; i++)\
    \ {\n        if (!is_prime[i]) continue;\n        primes.push_back(i);\n     \
    \   for (T j = i * i; 0 <= j && j <= n; j += i) {  // \u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n            is_prime[j] = false;\n     \
    \   }\n    }\n    return primes;\n}\n\n/**\n * @brief \u7D20\u56E0\u6570\u5206\
    \u89E3. \u7D20\u6570\u30EA\u30B9\u30C8\u3092\u7528\u3044\u308B\n * @tparam T \u6574\
    \u6570\u578B\n * @param n \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u6570\n *\
    \ @param primes \u7D20\u6570\u30EA\u30B9\u30C8. shieve\u3067\u53D6\u5F97\u3057\
    \u305F\u3082\u306E\u3092\u4F7F\u3046\n * @return vector<pair<T, int>> \u7D20\u56E0\
    \u6570\u3068\u305D\u306E\u500B\u6570\n * @note O(sqrt(n)) \u3088\u308A\u9AD8\u901F\
    . shieve\u306B\u6642\u9593\u304C\u304B\u304B\u308A\uFF0C\u30E1\u30E2\u30EA\u3092\
    \u3088\u308A\u6D88\u8CBB\u3059\u308B\n*/\ntemplate <typename T>\nvector<pair<T,\
    \ int>> prime_factorization_with_shieve(T n, const vector<T>& primes) {\n    vector<pair<T,\
    \ int>> factors;  // \u7D20\u56E0\u6570\u3068\u305D\u306E\u500B\u6570\n    for\
    \ (const T &p : primes) {\n        if (p * p > n) break;\n        if (n % p !=\
    \ 0) continue;\n        int count = 0;\n        while (n % p == 0) {\n       \
    \     n /= p;\n            count++;\n        }\n        factors.push_back({p,\
    \ count});\n    }\n    if (n != 1) factors.push_back({n, 1});  // n\u304C\u7D20\
    \u6570\u306E\u5834\u5408\n    return factors;\n}\n\n/**\n * @brief \u7D20\u56E0\
    \u6570\u5206\u89E3\n * @tparam T \u6574\u6570\u578B\n * @param n \u7D20\u56E0\u6570\
    \u5206\u89E3\u3059\u308B\u6570\n * @return vector<pair<T, int>> \u7D20\u56E0\u6570\
    \u3068\u305D\u306E\u500B\u6570\n * @note O(sqrt(n))\n*/\ntemplate <typename T>\n\
    vector<pair<T, int>> prime_factorization(T n) {\n    vector<pair<T, int>> factors;\n\
    \    for (T i = 2; i * i <= n; i++) {\n        if (n % i != 0) continue;\n   \
    \     int count = 0;\n        while (n % i == 0) {\n            n /= i;\n    \
    \        count++;\n        }\n        factors.push_back({i, count});\n    }\n\
    \    if (n != 1) factors.push_back({n, 1});  // n\u304C\u7D20\u6570\u306E\u5834\
    \u5408\n    return factors;\n}\n} // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ ugilib {\n/**\n * @brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
    \n * @tparam T \u6574\u6570\u578B\n * @param n \u7D20\u6570\u306E\u4E0A\u9650\
    . n\u3092\u542B\u3080\n * @return vector<T> \u7D20\u6570\u30EA\u30B9\u30C8\n *\
    \ @note O(n log log n)\n * @note j\u306B\u4EE3\u5165\u3055\u308C\u308B\u6570\u306E\
    \u6700\u5927\u5024\u306FN^2\u306A\u306E\u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u306B\u6CE8\u610F\n*/\ntemplate <typename T>\nvector<T> shieve(const T\
    \ &n) {\n    vector<bool> is_prime(n + 1, true);\n    vector<T> primes;\n    is_prime[0]\
    \ = is_prime[1] = false;\n    for (T i = 2; i <= n; i++) {\n        if (!is_prime[i])\
    \ continue;\n        primes.push_back(i);\n        for (T j = i * i; 0 <= j &&\
    \ j <= n; j += i) {  // \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\
    \u610F\n            is_prime[j] = false;\n        }\n    }\n    return primes;\n\
    }\n\n/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3. \u7D20\u6570\u30EA\u30B9\u30C8\
    \u3092\u7528\u3044\u308B\n * @tparam T \u6574\u6570\u578B\n * @param n \u7D20\u56E0\
    \u6570\u5206\u89E3\u3059\u308B\u6570\n * @param primes \u7D20\u6570\u30EA\u30B9\
    \u30C8. shieve\u3067\u53D6\u5F97\u3057\u305F\u3082\u306E\u3092\u4F7F\u3046\n *\
    \ @return vector<pair<T, int>> \u7D20\u56E0\u6570\u3068\u305D\u306E\u500B\u6570\
    \n * @note O(sqrt(n)) \u3088\u308A\u9AD8\u901F. shieve\u306B\u6642\u9593\u304C\
    \u304B\u304B\u308A\uFF0C\u30E1\u30E2\u30EA\u3092\u3088\u308A\u6D88\u8CBB\u3059\
    \u308B\n*/\ntemplate <typename T>\nvector<pair<T, int>> prime_factorization_with_shieve(T\
    \ n, const vector<T>& primes) {\n    vector<pair<T, int>> factors;  // \u7D20\u56E0\
    \u6570\u3068\u305D\u306E\u500B\u6570\n    for (const T &p : primes) {\n      \
    \  if (p * p > n) break;\n        if (n % p != 0) continue;\n        int count\
    \ = 0;\n        while (n % p == 0) {\n            n /= p;\n            count++;\n\
    \        }\n        factors.push_back({p, count});\n    }\n    if (n != 1) factors.push_back({n,\
    \ 1});  // n\u304C\u7D20\u6570\u306E\u5834\u5408\n    return factors;\n}\n\n/**\n\
    \ * @brief \u7D20\u56E0\u6570\u5206\u89E3\n * @tparam T \u6574\u6570\u578B\n *\
    \ @param n \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u6570\n * @return vector<pair<T,\
    \ int>> \u7D20\u56E0\u6570\u3068\u305D\u306E\u500B\u6570\n * @note O(sqrt(n))\n\
    */\ntemplate <typename T>\nvector<pair<T, int>> prime_factorization(T n) {\n \
    \   vector<pair<T, int>> factors;\n    for (T i = 2; i * i <= n; i++) {\n    \
    \    if (n % i != 0) continue;\n        int count = 0;\n        while (n % i ==\
    \ 0) {\n            n /= i;\n            count++;\n        }\n        factors.push_back({i,\
    \ count});\n    }\n    if (n != 1) factors.push_back({n, 1});  // n\u304C\u7D20\
    \u6570\u306E\u5834\u5408\n    return factors;\n}\n} // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/math/primes.hpp
  requiredBy: []
  timestamp: '2024-03-27 18:24:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/math/enum_divisors.test.cpp
  - tests/math/prime_fuctorization.test.cpp
  - tests/math/prime_enumerate.test.cpp
documentation_of: ugilib/math/primes.hpp
layout: document
redirect_from:
- /library/ugilib/math/primes.hpp
- /library/ugilib/math/primes.hpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
