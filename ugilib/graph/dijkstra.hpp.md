---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/constants.hpp
    title: ugilib/base/constants.hpp
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: tests/graph/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 2 \"ugilib/graph/dijkstra.hpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(int i =\
    \ 0; i < (int)(n); i++)  // rep macro\n#define all(v) begin(v), end(v)  // all\
    \ iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants\
    \ {\n    template<typename T>\n    inline constexpr T INF = std::numeric_limits<T>::max()\
    \ / 4;\n} // namespace ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n\
    #line 4 \"ugilib/graph/dijkstra.hpp\"\n\nusing namespace std;\n\n\n/// cut begin\n\
    namespace ugilib {\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n\
    \ * @param n \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\n * @param start \u59CB\
    \u70B9\n * @param graph \u30B0\u30E9\u30D5. vector<pair<int, weight_t>> \u3067\
    \u96A3\u63A5\u9802\u70B9\u3068\u30B3\u30B9\u30C8\u3092\u8868\u3059\n * @param\
    \ weight_inf \u7121\u9650\u5927\u306E\u5024. \u30D1\u30B9\u304C\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\u30C8\n * @return \u59CB\u70B9\u304B\
    \u3089\u5404\u9802\u70B9\u307E\u3067\u306E\u6700\u77ED\u8DDD\u96E2\n * @note O((E+V)logV)\n\
    */\ntemplate<typename weight_t>\nvector<weight_t> dijkstra(int n, int start, const\
    \ vector<vector<pair<int, weight_t>>>& graph, const weight_t weight_inf = ugilib::constants::INF<weight_t>)\
    \ {\n    vector<weight_t> costs(n, weight_inf);\n    costs[start] = 0;\n\n   \
    \ priority_queue<pair<weight_t, int>, vector<pair<weight_t, int>>, greater<>>\
    \ next_nodes;\n    next_nodes.push({0, start});\n\n    while (!next_nodes.empty())\
    \ {\n        auto [cost, node] = next_nodes.top(); next_nodes.pop();\n       \
    \ if (cost > costs[node]) continue;\n\n        for (const auto [next_node, next_cost]\
    \ : graph[node]) {\n            auto new_cost = cost + next_cost;\n          \
    \  if (new_cost < costs[next_node]) {\n                costs[next_node] = new_cost;\n\
    \                next_nodes.push({costs[next_node], next_node});\n           \
    \ }\n        }\n    }\n\n    return costs;\n}\n} // namespace ugilib\n/// cut\
    \ end\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\
    \n\nusing namespace std;\n\n\n/// cut begin\nnamespace ugilib {\n/**\n * @brief\
    \ \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @param n \u30B0\u30E9\u30D5\u306E\
    \u9802\u70B9\u6570\n * @param start \u59CB\u70B9\n * @param graph \u30B0\u30E9\
    \u30D5. vector<pair<int, weight_t>> \u3067\u96A3\u63A5\u9802\u70B9\u3068\u30B3\
    \u30B9\u30C8\u3092\u8868\u3059\n * @param weight_inf \u7121\u9650\u5927\u306E\u5024\
    . \u30D1\u30B9\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\
    \u30C8\n * @return \u59CB\u70B9\u304B\u3089\u5404\u9802\u70B9\u307E\u3067\u306E\
    \u6700\u77ED\u8DDD\u96E2\n * @note O((E+V)logV)\n*/\ntemplate<typename weight_t>\n\
    vector<weight_t> dijkstra(int n, int start, const vector<vector<pair<int, weight_t>>>&\
    \ graph, const weight_t weight_inf = ugilib::constants::INF<weight_t>) {\n   \
    \ vector<weight_t> costs(n, weight_inf);\n    costs[start] = 0;\n\n    priority_queue<pair<weight_t,\
    \ int>, vector<pair<weight_t, int>>, greater<>> next_nodes;\n    next_nodes.push({0,\
    \ start});\n\n    while (!next_nodes.empty()) {\n        auto [cost, node] = next_nodes.top();\
    \ next_nodes.pop();\n        if (cost > costs[node]) continue;\n\n        for\
    \ (const auto [next_node, next_cost] : graph[node]) {\n            auto new_cost\
    \ = cost + next_cost;\n            if (new_cost < costs[next_node]) {\n      \
    \          costs[next_node] = new_cost;\n                next_nodes.push({costs[next_node],\
    \ next_node});\n            }\n        }\n    }\n\n    return costs;\n}\n} //\
    \ namespace ugilib\n/// cut end\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-03-11 22:33:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/dijkstra.test.cpp
documentation_of: ugilib/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/ugilib/graph/dijkstra.hpp
- /library/ugilib/graph/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
