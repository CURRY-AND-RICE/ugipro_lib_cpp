---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: ugilib/base/constants.hpp
    title: ugilib/base/constants.hpp
  - icon: ':heavy_check_mark:'
    path: ugilib/bit/bit_exhaustive_search.hpp
    title: "\u30D3\u30C3\u30C8\u5168\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: ugilib/bit/bit_util.hpp
    title: "\u6570\u5024 -> \u30D3\u30C3\u30C8\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: ugilib/dp/edit_distance.hpp
    title: "\u7DE8\u96C6\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: ugilib/dp/lis.hpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
  - icon: ':heavy_check_mark:'
    path: ugilib/geometry/rectangle_overlap.hpp
    title: "\u4E8C\u3064\u306E\u9577\u65B9\u5F62\u306E\u91CD\u306A\u308A\u3092\u5224\
      \u5B9A"
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
  - icon: ':heavy_check_mark:'
    path: ugilib/iteration/all_combinations.hpp
    title: "\u5168\u3066\u306ECombination\u306B\u5BFE\u3057\u3066\u95A2\u6570\u3092\
      \u5B9F\u884C\u3059\u308B"
  - icon: ':heavy_check_mark:'
    path: ugilib/iteration/counter.hpp
    title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u7BC4\u56F2\u306B\u542B\u307E\u308C\
      \u308B\u8981\u7D20\u306E\u51FA\u73FE\u56DE\u6570\u3092\u30AB\u30A6\u30F3\u30C8\
      \u3059\u308B"
  - icon: ':heavy_check_mark:'
    path: ugilib/iteration/next_combination.hpp
    title: "\u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u751F\u6210\u3059\u308B"
  - icon: ':heavy_check_mark:'
    path: ugilib/math/pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bit/bit_exhaustive_search.test.cpp
    title: tests/bit/bit_exhaustive_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dp/edit_distance.test.cpp
    title: tests/dp/edit_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dp/lis.test.cpp
    title: tests/dp/lis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/geometry/rectangle_overlap.test.cpp
    title: tests/geometry/rectangle_overlap.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/bfs.test.cpp
    title: tests/graph/bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: tests/graph/dijkstra.test.cpp
  - icon: ':x:'
    path: tests/graph/topological_sort.test.cpp
    title: tests/graph/topological_sort.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "ugilib/base/definitions.hpp"


    using ll = long long;

    using ull = unsigned long long;

    using ld = long double;

    #define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro

    #define all(v) begin(v), end(v)  // all iterator

    '
  code: '#pragma once


    using ll = long long;

    using ull = unsigned long long;

    using ld = long double;

    #define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro

    #define all(v) begin(v), end(v)  // all iterator

    '
  dependsOn: []
  isVerificationFile: false
  path: ugilib/base/definitions.hpp
  requiredBy:
  - ugilib/iteration/counter.hpp
  - ugilib/iteration/all_combinations.hpp
  - ugilib/iteration/next_combination.hpp
  - ugilib/math/pow.hpp
  - ugilib/base/constants.hpp
  - ugilib/bit/bit_util.hpp
  - ugilib/bit/bit_exhaustive_search.hpp
  - ugilib/geometry/rectangle_overlap.hpp
  - ugilib/dp/edit_distance.hpp
  - ugilib/dp/lis.hpp
  - ugilib/graph/bfs.hpp
  - ugilib/graph/tsp.hpp
  - ugilib/graph/dijkstra.hpp
  timestamp: '2024-04-03 22:46:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/iteration/combinations.test.cpp
  - tests/iteration/counter.test.cpp
  - tests/math/enum_divisors.test.cpp
  - tests/math/prime_fuctorization.test.cpp
  - tests/math/pow.test.cpp
  - tests/math/prime_enumerate.test.cpp
  - tests/bit/bit_exhaustive_search.test.cpp
  - tests/geometry/rectangle_overlap.test.cpp
  - tests/dp/edit_distance.test.cpp
  - tests/dp/lis.test.cpp
  - tests/graph/tsp.test.cpp
  - tests/graph/dijkstra.test.cpp
  - tests/graph/topological_sort.test.cpp
  - tests/graph/bfs.test.cpp
documentation_of: ugilib/base/definitions.hpp
layout: document
redirect_from:
- /library/ugilib/base/definitions.hpp
- /library/ugilib/base/definitions.hpp.html
title: ugilib/base/definitions.hpp
---
