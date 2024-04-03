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
    path: tests/graph/bfs.test.cpp
    title: tests/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "0or1\u5E45\u512A\u5148\u63A2\u7D22. 01BFS"
    links: []
  bundledCode: "#line 2 \"ugilib/graph/bfs.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\n#define rep(i, n) for(int i = 0; i < (int)(n);\
    \ i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n#line\
    \ 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants {\n    template<typename\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / 2;\n} // namespace\
    \ ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"\
    ugilib/graph/bfs.hpp\"\n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n\
    \     * @brief 0or1\u5E45\u512A\u5148\u63A2\u7D22. 01BFS\n     * @param n \u30B0\
    \u30E9\u30D5\u306E\u9802\u70B9\u6570\n     * @param start \u59CB\u70B9\n     *\
    \ @param graph \u30B0\u30E9\u30D5. vector<pair<int, weight_type>> \u3067\u96A3\
    \u63A5\u9802\u70B9\u3068\u30B3\u30B9\u30C8\u3092\u8868\u3059. \u30B3\u30B9\u30C8\
    \u306F0 or 1\n     * @param weight_inf \u7121\u9650\u5927\u306E\u5024. \u30D1\u30B9\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\u30C8\n   \
    \  * @return \u59CB\u70B9\u304B\u3089\u5404\u9802\u70B9\u307E\u3067\u306E\u6700\
    \u77ED\u8DDD\u96E2\n     * @note O(E+V)\n     * @todo 01BFS\u554F\u984C\u3067\u306E\
    \u30C6\u30B9\u30C8\u3092\u66F8\u304F\n    */\n    template <typename weight_type>\n\
    \    vector<weight_type> bfs01(int n, int start, const vector<vector<pair<int,\
    \ weight_type>>> &graph, weight_type weight_inf = ugilib::constants::INF<weight_type>)\
    \ {\n        vector<weight_type> costs(n, weight_inf);\n        costs[start] =\
    \ 0;\n\n        deque<int> next_nodes;\n        next_nodes.push_back(start);\n\
    \n        while (!next_nodes.empty()) {\n            auto node = next_nodes.front();\
    \ next_nodes.pop_front();\n            auto cost = costs[node];\n\n          \
    \  for (const auto [next_node, next_cost] : graph[node]) {\n                auto\
    \ new_cost = cost + next_cost;\n                if (new_cost < costs[next_node])\
    \ {\n                    costs[next_node] = new_cost;\n                    //\
    \ 0or1\u5E45\u512A\u5148\u63A2\u7D22\u306E\u5834\u5408, \u30B3\u30B9\u30C8\u304C\
    0\u306E\u5834\u5408\u306F\u524D\u304B\u3089\u5165\u308C, 1\u306E\u5834\u5408\u306F\
    \u5F8C\u308D\u306B\u5165\u308C\u308B\n                    if (next_cost == 0)\
    \ next_nodes.push_front(next_node);\n                    else next_nodes.push_back(next_node);\n\
    \                }\n            }\n        }\n\n        return costs;\n    }\n\
    }  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief 0or1\u5E45\
    \u512A\u5148\u63A2\u7D22. 01BFS\n     * @param n \u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u6570\n     * @param start \u59CB\u70B9\n     * @param graph \u30B0\u30E9\
    \u30D5. vector<pair<int, weight_type>> \u3067\u96A3\u63A5\u9802\u70B9\u3068\u30B3\
    \u30B9\u30C8\u3092\u8868\u3059. \u30B3\u30B9\u30C8\u306F0 or 1\n     * @param\
    \ weight_inf \u7121\u9650\u5927\u306E\u5024. \u30D1\u30B9\u304C\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\u30C8\n     * @return \u59CB\u70B9\u304B\
    \u3089\u5404\u9802\u70B9\u307E\u3067\u306E\u6700\u77ED\u8DDD\u96E2\n     * @note\
    \ O(E+V)\n     * @todo 01BFS\u554F\u984C\u3067\u306E\u30C6\u30B9\u30C8\u3092\u66F8\
    \u304F\n    */\n    template <typename weight_type>\n    vector<weight_type> bfs01(int\
    \ n, int start, const vector<vector<pair<int, weight_type>>> &graph, weight_type\
    \ weight_inf = ugilib::constants::INF<weight_type>) {\n        vector<weight_type>\
    \ costs(n, weight_inf);\n        costs[start] = 0;\n\n        deque<int> next_nodes;\n\
    \        next_nodes.push_back(start);\n\n        while (!next_nodes.empty()) {\n\
    \            auto node = next_nodes.front(); next_nodes.pop_front();\n       \
    \     auto cost = costs[node];\n\n            for (const auto [next_node, next_cost]\
    \ : graph[node]) {\n                auto new_cost = cost + next_cost;\n      \
    \          if (new_cost < costs[next_node]) {\n                    costs[next_node]\
    \ = new_cost;\n                    // 0or1\u5E45\u512A\u5148\u63A2\u7D22\u306E\
    \u5834\u5408, \u30B3\u30B9\u30C8\u304C0\u306E\u5834\u5408\u306F\u524D\u304B\u3089\
    \u5165\u308C, 1\u306E\u5834\u5408\u306F\u5F8C\u308D\u306B\u5165\u308C\u308B\n\
    \                    if (next_cost == 0) next_nodes.push_front(next_node);\n \
    \                   else next_nodes.push_back(next_node);\n                }\n\
    \            }\n        }\n\n        return costs;\n    }\n}  // namespace ugilib\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/graph/bfs.hpp
  requiredBy: []
  timestamp: '2024-04-03 22:40:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/bfs.test.cpp
documentation_of: ugilib/graph/bfs.hpp
layout: document
redirect_from:
- /library/ugilib/graph/bfs.hpp
- /library/ugilib/graph/bfs.hpp.html
title: "0or1\u5E45\u512A\u5148\u63A2\u7D22. 01BFS"
---
