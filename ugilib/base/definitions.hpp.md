---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/constants.hpp
    title: ugilib/base/constants.hpp
  - icon: ':warning:'
    path: ugilib/bit/bit_util.hpp
    title: "\u6570\u5024 -> \u30D3\u30C3\u30C8\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/bfs.hpp
    title: "0or1\u5E45\u512A\u5148\u63A2\u7D22. 01BFS"
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/bfs.test.cpp
    title: tests/graph/bfs.test.cpp
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
  - ugilib/graph/bfs.hpp
  - ugilib/graph/dijkstra.hpp
  - ugilib/base/constants.hpp
  - ugilib/bit/bit_util.hpp
  timestamp: '2024-03-01 16:27:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/bfs.test.cpp
  - tests/graph/dijkstra.test.cpp
documentation_of: ugilib/base/definitions.hpp
layout: document
redirect_from:
- /library/ugilib/base/definitions.hpp
- /library/ugilib/base/definitions.hpp.html
title: ugilib/base/definitions.hpp
---
