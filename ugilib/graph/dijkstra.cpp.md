---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 1 \"ugilib/graph/dijkstra.cpp\"\n#include <bits/stdc++.h>\n\n\
    using namespace std;\nusing ll = long long;\n\nconst ll INF = 1LL << 60;  // infinity\n\
    \n/// cut begin\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n *\
    \ @param n \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\n * @param start \u59CB\u70B9\
    \n * @param graph \u30B0\u30E9\u30D5. vector<pair<int, ll>> \u3067\u96A3\u63A5\
    \u9802\u70B9\u3068\u30B3\u30B9\u30C8\u3092\u8868\u3059\n * @return \u59CB\u70B9\
    \u304B\u3089\u5404\u9802\u70B9\u307E\u3067\u306E\u6700\u77ED\u8DDD\u96E2\n * @note\
    \ O((E+V)logV)\n*/\ntemplate<typename weight_type>\nvector<weight_type> dijkstra(int\
    \ n, int start, const vector<vector<pair<int, weight_type>>>& graph) {\n    vector<weight_type>\
    \ costs(n, INF);\n    costs[start] = 0;\n\n    priority_queue<pair<weight_type,\
    \ int>, vector<pair<weight_type, int>>, greater<>> next_nodes;\n    next_nodes.push({0,\
    \ start});\n\n    while (!next_nodes.empty()) {\n        auto [cost, node] = next_nodes.top();\
    \ next_nodes.pop();\n        if (cost > costs[node]) continue;\n\n        for\
    \ (auto [next_node, next_cost] : graph[node]) {\n            auto new_cost = cost\
    \ + next_cost;\n            if (new_cost < costs[next_node]) {\n             \
    \   costs[next_node] = cost + next_cost;\n                next_nodes.push({costs[next_node],\
    \ next_node});\n            }\n        }\n    }\n\n    return costs;\n}\n/// cut\
    \ end\n\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\nusing ll = long long;\n\
    \nconst ll INF = 1LL << 60;  // infinity\n\n/// cut begin\n/**\n * @brief \u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @param n \u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u6570\n * @param start \u59CB\u70B9\n * @param graph \u30B0\u30E9\u30D5\
    . vector<pair<int, ll>> \u3067\u96A3\u63A5\u9802\u70B9\u3068\u30B3\u30B9\u30C8\
    \u3092\u8868\u3059\n * @return \u59CB\u70B9\u304B\u3089\u5404\u9802\u70B9\u307E\
    \u3067\u306E\u6700\u77ED\u8DDD\u96E2\n * @note O((E+V)logV)\n*/\ntemplate<typename\
    \ weight_type>\nvector<weight_type> dijkstra(int n, int start, const vector<vector<pair<int,\
    \ weight_type>>>& graph) {\n    vector<weight_type> costs(n, INF);\n    costs[start]\
    \ = 0;\n\n    priority_queue<pair<weight_type, int>, vector<pair<weight_type,\
    \ int>>, greater<>> next_nodes;\n    next_nodes.push({0, start});\n\n    while\
    \ (!next_nodes.empty()) {\n        auto [cost, node] = next_nodes.top(); next_nodes.pop();\n\
    \        if (cost > costs[node]) continue;\n\n        for (auto [next_node, next_cost]\
    \ : graph[node]) {\n            auto new_cost = cost + next_cost;\n          \
    \  if (new_cost < costs[next_node]) {\n                costs[next_node] = cost\
    \ + next_cost;\n                next_nodes.push({costs[next_node], next_node});\n\
    \            }\n        }\n    }\n\n    return costs;\n}\n/// cut end\n\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2024-03-01 15:38:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/graph/dijkstra.cpp
layout: document
redirect_from:
- /library/ugilib/graph/dijkstra.cpp
- /library/ugilib/graph/dijkstra.cpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
