---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/enum_divisors.test.cpp
    title: tests/math/enum_divisors.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D04\u6570\u5217\u6319. \u7D50\u679C\u306F\u30BD\u30FC\u30C8\
      \u6E08\u307F"
    links: []
  bundledCode: "#line 2 \"ugilib/math/enum_divisors.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u7D04\u6570\
    \u5217\u6319. \u7D50\u679C\u306F\u30BD\u30FC\u30C8\u6E08\u307F\n     * @tparam\
    \ T \u6574\u6570\u578B\n     * @param n \u7D04\u6570\u5217\u6319\u3059\u308B\u6570\
    \n     * @return vector<T> \u7D04\u6570\u30EA\u30B9\u30C8\n     * @note O(sqrt(n))\n\
    \    */\n    template <typename T>\n    vector<T> enum_divisors(T n) {\n     \
    \   vector<T> divisors_front;\n        deque<T> divisors_back;\n        for (T\
    \ i = 1; i * i <= n; i++) {\n            if (n % i == 0) {\n                divisors_front.push_back(i);\n\
    \                if (i * i != n) divisors_back.push_front(n / i);\n          \
    \  }\n        }\n        divisors_front.insert(divisors_front.end(), divisors_back.begin(),\
    \ divisors_back.end());\n        return divisors_front;\n    }\n\n    /**\n  \
    \   * @brief \u7D04\u6570\u5217\u6319. \u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\
    \u679C\u3092\u7528\u3044\u308B. \u7D50\u679C\u306F\u30BD\u30FC\u30C8\u3055\u308C\
    \u3066\u3044\u306A\u3044\n     * @tparam T \u6574\u6570\u578B\n     * @param n\
    \ \u7D04\u6570\u5217\u6319\u3059\u308B\u6570\n     * @param factors \u7D20\u56E0\
    \u6570\u5206\u89E3\u306E\u7D50\u679C\n     * @return vector<T> \u7D04\u6570\u30EA\
    \u30B9\u30C8\n     * @note O(k) k\u306F\u7D20\u56E0\u6570\u306E\u500B\u6570\n\
    \     * @note \u7D50\u679C\u304C\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u306A\
    \u3044\u3053\u3068\u306B\u6CE8\u610F\n     */\n    template <typename T>\n   \
    \ vector<T> enum_divisors_with_prime_factors(T n, const vector<pair<T, int>>&\
    \ factors) {\n        vector<T> divisors = {1};\n        for (const auto& [p,\
    \ c] : factors) {\n            vector<T> new_divisors;\n            for (T d :\
    \ divisors) {\n                T mul = 1;\n                for (int i = 0; i <\
    \ c; i++) {\n                    mul *= p;\n                    new_divisors.push_back(d\
    \ * mul);\n                }\n            }\n            divisors.insert(divisors.end(),\
    \ new_divisors.begin(), new_divisors.end());\n        }\n        return divisors;\n\
    \    }\n} // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ ugilib {\n    /**\n     * @brief \u7D04\u6570\u5217\u6319. \u7D50\u679C\u306F\
    \u30BD\u30FC\u30C8\u6E08\u307F\n     * @tparam T \u6574\u6570\u578B\n     * @param\
    \ n \u7D04\u6570\u5217\u6319\u3059\u308B\u6570\n     * @return vector<T> \u7D04\
    \u6570\u30EA\u30B9\u30C8\n     * @note O(sqrt(n))\n    */\n    template <typename\
    \ T>\n    vector<T> enum_divisors(T n) {\n        vector<T> divisors_front;\n\
    \        deque<T> divisors_back;\n        for (T i = 1; i * i <= n; i++) {\n \
    \           if (n % i == 0) {\n                divisors_front.push_back(i);\n\
    \                if (i * i != n) divisors_back.push_front(n / i);\n          \
    \  }\n        }\n        divisors_front.insert(divisors_front.end(), divisors_back.begin(),\
    \ divisors_back.end());\n        return divisors_front;\n    }\n\n    /**\n  \
    \   * @brief \u7D04\u6570\u5217\u6319. \u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\
    \u679C\u3092\u7528\u3044\u308B. \u7D50\u679C\u306F\u30BD\u30FC\u30C8\u3055\u308C\
    \u3066\u3044\u306A\u3044\n     * @tparam T \u6574\u6570\u578B\n     * @param n\
    \ \u7D04\u6570\u5217\u6319\u3059\u308B\u6570\n     * @param factors \u7D20\u56E0\
    \u6570\u5206\u89E3\u306E\u7D50\u679C\n     * @return vector<T> \u7D04\u6570\u30EA\
    \u30B9\u30C8\n     * @note O(k) k\u306F\u7D20\u56E0\u6570\u306E\u500B\u6570\n\
    \     * @note \u7D50\u679C\u304C\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u306A\
    \u3044\u3053\u3068\u306B\u6CE8\u610F\n     */\n    template <typename T>\n   \
    \ vector<T> enum_divisors_with_prime_factors(T n, const vector<pair<T, int>>&\
    \ factors) {\n        vector<T> divisors = {1};\n        for (const auto& [p,\
    \ c] : factors) {\n            vector<T> new_divisors;\n            for (T d :\
    \ divisors) {\n                T mul = 1;\n                for (int i = 0; i <\
    \ c; i++) {\n                    mul *= p;\n                    new_divisors.push_back(d\
    \ * mul);\n                }\n            }\n            divisors.insert(divisors.end(),\
    \ new_divisors.begin(), new_divisors.end());\n        }\n        return divisors;\n\
    \    }\n} // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/math/enum_divisors.hpp
  requiredBy: []
  timestamp: '2024-03-31 15:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/math/enum_divisors.test.cpp
documentation_of: ugilib/math/enum_divisors.hpp
layout: document
redirect_from:
- /library/ugilib/math/enum_divisors.hpp
- /library/ugilib/math/enum_divisors.hpp.html
title: "\u7D04\u6570\u5217\u6319. \u7D50\u679C\u306F\u30BD\u30FC\u30C8\u6E08\u307F"
---
