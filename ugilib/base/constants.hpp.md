---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy:
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

    #line 3 "ugilib/base/constants.hpp"


    const ll INF = 1LL << 60;  // infinity

    '
  code: '#pragma once

    #include "ugilib/base/definitions.hpp"


    const ll INF = 1LL << 60;  // infinity

    '
  dependsOn:
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/base/constants.hpp
  requiredBy:
  - ugilib/graph/dijkstra.hpp
  timestamp: '2024-03-01 23:25:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/dijkstra.test.cpp
documentation_of: ugilib/base/constants.hpp
layout: document
redirect_from:
- /library/ugilib/base/constants.hpp
- /library/ugilib/base/constants.hpp.html
title: ugilib/base/constants.hpp
---
