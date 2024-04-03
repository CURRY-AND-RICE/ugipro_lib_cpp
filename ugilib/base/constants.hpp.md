---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ugilib/bit/bit_exhaustive_search.hpp
    title: "\u30D3\u30C3\u30C8\u5168\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: ugilib/bit/bit_util.hpp
    title: "\u6570\u5024 -> \u30D3\u30C3\u30C8\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: ugilib/dp/edit_distance.hpp
    title: "\u7DE8\u96C6\u8DDD\u96E2\u3092\u6C42\u3081\u308B"
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/bfs.hpp
    title: "0or1\u5E45\u512A\u5148\u63A2\u7D22. 01BFS"
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/tsp.hpp
    title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\u3092\u89E3\
      \u304FDP"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bit/bit_exhaustive_search.test.cpp
    title: tests/bit/bit_exhaustive_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dp/edit_distance.test.cpp
    title: tests/dp/edit_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/geometry/rectangle_overlap.test.cpp
    title: tests/geometry/rectangle_overlap.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/bfs.test.cpp
    title: tests/graph/bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: tests/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/tsp.test.cpp
    title: tests/graph/tsp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/iteration/combinations.test.cpp
    title: tests/iteration/combinations.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/iteration/counter.test.cpp
    title: tests/iteration/counter.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/enum_divisors.test.cpp
    title: tests/math/enum_divisors.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/math/pow.test.cpp
    title: tests/math/pow.test.cpp
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
  - ugilib/dp/edit_distance.hpp
  - ugilib/bit/bit_exhaustive_search.hpp
  - ugilib/bit/bit_util.hpp
  - ugilib/graph/tsp.hpp
  - ugilib/graph/bfs.hpp
  - ugilib/graph/dijkstra.hpp
  timestamp: '2024-03-04 19:44:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/iteration/counter.test.cpp
  - tests/iteration/combinations.test.cpp
  - tests/dp/edit_distance.test.cpp
  - tests/geometry/rectangle_overlap.test.cpp
  - tests/bit/bit_exhaustive_search.test.cpp
  - tests/math/prime_enumerate.test.cpp
  - tests/math/pow.test.cpp
  - tests/math/prime_fuctorization.test.cpp
  - tests/math/enum_divisors.test.cpp
  - tests/graph/tsp.test.cpp
  - tests/graph/dijkstra.test.cpp
  - tests/graph/bfs.test.cpp
documentation_of: ugilib/base/constants.hpp
layout: document
redirect_from:
- /library/ugilib/base/constants.hpp
- /library/ugilib/base/constants.hpp.html
title: ugilib/base/constants.hpp
---
