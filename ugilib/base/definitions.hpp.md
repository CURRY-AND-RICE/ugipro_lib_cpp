---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/constants.hpp
    title: ugilib/base/constants.hpp
  - icon: ':warning:'
    path: ugilib/bits/bit_exhaustive_search.hpp
    title: bit_exhaustive_search
  - icon: ':warning:'
    path: ugilib/bits/bit_util.hpp
    title: num_to_bits
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: tests/graph/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "ugilib/base/definitions.hpp"


    using ll = long long;

    using ull = unsigned long long;

    using ld = long double;

    #define rep(i, n) for(int i = 0; i < (int)(n); i++)  // rep macro

    #define all(v) begin(v), end(v)  // all iterator

    '
  code: '#pragma once


    using ll = long long;

    using ull = unsigned long long;

    using ld = long double;

    #define rep(i, n) for(int i = 0; i < (int)(n); i++)  // rep macro

    #define all(v) begin(v), end(v)  // all iterator

    '
  dependsOn: []
  isVerificationFile: false
  path: ugilib/base/definitions.hpp
  requiredBy:
  - ugilib/graph/dijkstra.hpp
  - ugilib/base/constants.hpp
  - ugilib/bits/bit_exhaustive_search.hpp
  - ugilib/bits/bit_util.hpp
  timestamp: '2024-03-01 16:27:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/dijkstra.test.cpp
documentation_of: ugilib/base/definitions.hpp
layout: document
redirect_from:
- /library/ugilib/base/definitions.hpp
- /library/ugilib/base/definitions.hpp.html
title: ugilib/base/definitions.hpp
---
