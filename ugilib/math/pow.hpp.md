---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/math/pow.test.cpp
    title: tests/math/pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
    links: []
  bundledCode: "#line 2 \"ugilib/math/pow.hpp\"\n#include <bits/stdc++.h>\n#line 3\
    \ \"ugilib/base/definitions.hpp\"\n\n// old (compat)\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\n\n// new\nusing u8 =\
    \ uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    using u128 = __uint128_t;\nusing i8 = int8_t;\nusing i16 = int16_t;\nusing i32\
    \ = int32_t;\nusing i64 = int64_t;\nusing i128 = __int128_t;\nusing f32 = float;\n\
    using f64 = double;\nusing f128 = long double;\n\n#define rep(i, n) for(size_t\
    \ i = 0; i < n; i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n\
    #line 4 \"ugilib/math/pow.hpp\"\n\nnamespace ugilib {\n    /**\n     * @brief\
    \ \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n     * @param x \u57FA\u6570\n \
    \    * @param n \u6307\u6570\n     * @param mod mod\n     * @return x^n % mod\n\
    \     * @note O(log n)\n    */\n    template <typename T>\n    T fast_pow(T x,\
    \ ll n, T mod = ugilib::constants::INF<T>) {\n        assert(n >= 0);\n      \
    \  T res = 1;\n        while (n) {\n            if (n & 1) res = res*x % mod;\n\
    \            x = x*x % mod;\n            n >>= 1;\n        }\n        return res;\n\
    \    }\n}  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/definitions.hpp\"\
    \n\nnamespace ugilib {\n    /**\n     * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\
    \u6CD5\n     * @param x \u57FA\u6570\n     * @param n \u6307\u6570\n     * @param\
    \ mod mod\n     * @return x^n % mod\n     * @note O(log n)\n    */\n    template\
    \ <typename T>\n    T fast_pow(T x, ll n, T mod = ugilib::constants::INF<T>) {\n\
    \        assert(n >= 0);\n        T res = 1;\n        while (n) {\n          \
    \  if (n & 1) res = res*x % mod;\n            x = x*x % mod;\n            n >>=\
    \ 1;\n        }\n        return res;\n    }\n}  // namespace ugilib\n"
  dependsOn:
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/math/pow.hpp
  requiredBy: []
  timestamp: '2025-09-23 20:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/math/pow.test.cpp
documentation_of: ugilib/math/pow.hpp
layout: document
redirect_from:
- /library/ugilib/math/pow.hpp
- /library/ugilib/math/pow.hpp.html
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
---
