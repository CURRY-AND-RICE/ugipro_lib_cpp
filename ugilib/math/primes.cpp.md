---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ugilib/math/primes.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u3002\
    n\u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u5217\u6319\ntemplate <typename T>\nvector<T>\
    \ shieve(T n) {\n    vector<bool> is_prime(n + 1, true);\n    vector<T> primes;\n\
    \    is_prime[0] = is_prime[1] = false;\n    for (T i = 2; i <= n; i++) {\n  \
    \      if (!is_prime[i]) continue;\n        primes.push_back(i);\n        for\
    \ (T j = i * i; j <= n; j += i) {\n            is_prime[j] = false;\n        }\n\
    \    }\n    return primes;\n}\n\n// \u7D20\u56E0\u6570\u5206\u89E3\u3002\u30A8\
    \u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u3067\u5F97\u3089\u308C\u305F\
    \u7D20\u6570\u30EA\u30B9\u30C8\u3092\u5F15\u6570\u306B\u53D6\u308B\ntemplate <typename\
    \ T>\nvector< pair<T, int> > prime_factorization(T n, const vector<T>& primes)\
    \ {\n    vector< pair<T, int> > factors;\n    for (T p : primes) {\n        if\
    \ (p * p > n) break;\n        if (n % p != 0) continue;\n        int count = 0;\n\
    \        while (n % p == 0) {\n            n /= p;\n            count++;\n   \
    \     }\n        factors.push_back({p, count});\n    }\n    if (n != 1) factors.push_back({n,\
    \ 1});\n    return factors;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\u3002n\u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u5217\
    \u6319\ntemplate <typename T>\nvector<T> shieve(T n) {\n    vector<bool> is_prime(n\
    \ + 1, true);\n    vector<T> primes;\n    is_prime[0] = is_prime[1] = false;\n\
    \    for (T i = 2; i <= n; i++) {\n        if (!is_prime[i]) continue;\n     \
    \   primes.push_back(i);\n        for (T j = i * i; j <= n; j += i) {\n      \
    \      is_prime[j] = false;\n        }\n    }\n    return primes;\n}\n\n// \u7D20\
    \u56E0\u6570\u5206\u89E3\u3002\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9\u3067\u5F97\u3089\u308C\u305F\u7D20\u6570\u30EA\u30B9\u30C8\u3092\u5F15\
    \u6570\u306B\u53D6\u308B\ntemplate <typename T>\nvector< pair<T, int> > prime_factorization(T\
    \ n, const vector<T>& primes) {\n    vector< pair<T, int> > factors;\n    for\
    \ (T p : primes) {\n        if (p * p > n) break;\n        if (n % p != 0) continue;\n\
    \        int count = 0;\n        while (n % p == 0) {\n            n /= p;\n \
    \           count++;\n        }\n        factors.push_back({p, count});\n    }\n\
    \    if (n != 1) factors.push_back({n, 1});\n    return factors;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/math/primes.cpp
  requiredBy: []
  timestamp: '2024-03-01 15:38:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/math/primes.cpp
layout: document
redirect_from:
- /library/ugilib/math/primes.cpp
- /library/ugilib/math/primes.cpp.html
title: ugilib/math/primes.cpp
---
