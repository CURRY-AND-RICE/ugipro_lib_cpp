---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ugilib/bits/bit_exhaustive_search.hpp
    title: bit_exhaustive_search
  - icon: ':heavy_check_mark:'
    path: ugilib/bits/bit_util.hpp
    title: num_to_bits
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bits/bit_exhaustive_search.test.cpp
    title: tests/bits/bit_exhaustive_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: tests/graph/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(int\
    \ i = 0; i < (int)(n); i++)  // rep macro\n#define all(v) begin(v), end(v)  //\
    \ all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants\
    \ {\n    template<typename T>\n    inline constexpr T INF = std::numeric_limits<T>::max()\
    \ / 4;\n} // namespace ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n"
  code: "#pragma once\n#include \"ugilib/base/definitions.hpp\"\n\nnamespace ugilib::constants\
    \ {\n    template<typename T>\n    inline constexpr T INF = std::numeric_limits<T>::max()\
    \ / 4;\n} // namespace ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n"
  dependsOn:
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/base/constants.hpp
  requiredBy:
  - ugilib/graph/dijkstra.hpp
  - ugilib/bits/bit_exhaustive_search.hpp
  - ugilib/bits/bit_util.hpp
  timestamp: '2024-03-04 19:44:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/dijkstra.test.cpp
  - tests/bits/bit_exhaustive_search.test.cpp
documentation_of: ugilib/base/constants.hpp
layout: document
redirect_from:
- /library/ugilib/base/constants.hpp
- /library/ugilib/base/constants.hpp.html
title: ugilib/base/constants.hpp
---
