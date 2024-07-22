---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\u95A2\u6570\u306E\
      \u5B9A\u7FA9"
    links: []
  bundledCode: "#line 2 \"ugilib/graph/tree_diameter.hpp\"\n\n/**\n * @file tree_diameter.hpp\n\
    \ * @brief \u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\u95A2\u6570\u306E\u5B9A\
    \u7FA9\n */\n\n#include <bits/stdc++.h>\n\nnamespace ugilib {\n    using namespace\
    \ std;\n    /**\n     * @brief \u5404\u9802\u70B9\u306E\u8DDD\u96E2\u3092\u6C42\
    \u3081\u308BDFS. farthest_node_from() \u3067\u4F7F\u7528\n     */\n    template\
    \ <typename node_t>\n    void dfs_dist(node_t node, node_t parent, vector<int>&\
    \ dists, const vector<vector<node_t>>& edges) {\n        if (parent == -1) dists[node]\
    \ = 0;\n        else dists[node] = dists[parent] + 1;\n\n        for (auto next\
    \ : edges[node]) {\n            if (next == parent) continue;\n            dfs_dist(next,\
    \ node, dists, edges);\n        }\n    }\n\n    /**\n     * @brief start \u304B\
    \u3089\u6700\u3082\u9060\u3044\u9802\u70B9\u3068\u305D\u306E\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\n     * @tparam node_t \u9802\u70B9\u306E\u578B\n     * @param\
    \ start \u958B\u59CB\u9802\u70B9\n     * @param edges \u6728\u306E\u96A3\u63A5\
    \u30EA\u30B9\u30C8\n     * @return pair<node_t, int> \u6700\u3082\u9060\u3044\u9802\
    \u70B9\u3068\u305D\u306E\u8DDD\u96E2\n     * @note O(V)\n     */\n    template\
    \ <typename node_t>\n    pair<node_t, int> farthest_node_from(node_t start, vector<vector<node_t>>&\
    \ edges) {\n        vector<int> dists(edges.size(), -1);\n\n        dfs_dist(start,\
    \ -1, dists, edges);\n        auto farthest_node = max_element(dists.begin(),\
    \ dists.end()) - dists.begin();\n        return {farthest_node, dists[farthest_node]};\n\
    \    }\n\n    /**\n     * @brief \u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\
    \n     * @tparam node_t \u9802\u70B9\u306E\u578B\n     * @param edges \u6728\u306E\
    \u96A3\u63A5\u30EA\u30B9\u30C8\n     * @return int \u6728\u306E\u76F4\u5F84\n\
    \     * @note O(V)\n     */\n    template <typename node_t>\n    int tree_diameter(vector<vector<node_t>>&\
    \ edges) {\n        auto [start, _] = farthest_node_from(0, edges);\n        auto\
    \ [end, diameter] = farthest_node_from(start, edges);\n        return diameter;\n\
    \    }\n}  // namespace ugilib\n"
  code: "#pragma once\n\n/**\n * @file tree_diameter.hpp\n * @brief \u6728\u306E\u76F4\
    \u5F84\u3092\u6C42\u3081\u308B\u95A2\u6570\u306E\u5B9A\u7FA9\n */\n\n#include\
    \ <bits/stdc++.h>\n\nnamespace ugilib {\n    using namespace std;\n    /**\n \
    \    * @brief \u5404\u9802\u70B9\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308BDFS.\
    \ farthest_node_from() \u3067\u4F7F\u7528\n     */\n    template <typename node_t>\n\
    \    void dfs_dist(node_t node, node_t parent, vector<int>& dists, const vector<vector<node_t>>&\
    \ edges) {\n        if (parent == -1) dists[node] = 0;\n        else dists[node]\
    \ = dists[parent] + 1;\n\n        for (auto next : edges[node]) {\n          \
    \  if (next == parent) continue;\n            dfs_dist(next, node, dists, edges);\n\
    \        }\n    }\n\n    /**\n     * @brief start \u304B\u3089\u6700\u3082\u9060\
    \u3044\u9802\u70B9\u3068\u305D\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n   \
    \  * @tparam node_t \u9802\u70B9\u306E\u578B\n     * @param start \u958B\u59CB\
    \u9802\u70B9\n     * @param edges \u6728\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\n\
    \     * @return pair<node_t, int> \u6700\u3082\u9060\u3044\u9802\u70B9\u3068\u305D\
    \u306E\u8DDD\u96E2\n     * @note O(V)\n     */\n    template <typename node_t>\n\
    \    pair<node_t, int> farthest_node_from(node_t start, vector<vector<node_t>>&\
    \ edges) {\n        vector<int> dists(edges.size(), -1);\n\n        dfs_dist(start,\
    \ -1, dists, edges);\n        auto farthest_node = max_element(dists.begin(),\
    \ dists.end()) - dists.begin();\n        return {farthest_node, dists[farthest_node]};\n\
    \    }\n\n    /**\n     * @brief \u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\
    \n     * @tparam node_t \u9802\u70B9\u306E\u578B\n     * @param edges \u6728\u306E\
    \u96A3\u63A5\u30EA\u30B9\u30C8\n     * @return int \u6728\u306E\u76F4\u5F84\n\
    \     * @note O(V)\n     */\n    template <typename node_t>\n    int tree_diameter(vector<vector<node_t>>&\
    \ edges) {\n        auto [start, _] = farthest_node_from(0, edges);\n        auto\
    \ [end, diameter] = farthest_node_from(start, edges);\n        return diameter;\n\
    \    }\n}  // namespace ugilib"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-07-22 17:29:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/ugilib/graph/tree_diameter.hpp
- /library/ugilib/graph/tree_diameter.hpp.html
title: "\u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\u95A2\u6570\u306E\u5B9A\u7FA9"
---
