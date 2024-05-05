---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\uFF0C\u5165\
      \u6B21\u6570\u8A08\u7B97\u95A2\u6570\u306E\u5B9A\u7FA9"
    links: []
  bundledCode: "#line 2 \"ugilib/graph/topological_sort.hpp\"\n\n/**\n * @file topological_sort.hpp\n\
    \ * @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\uFF0C\u5165\u6B21\
    \u6570\u8A08\u7B97\u95A2\u6570\u306E\u5B9A\u7FA9\n*/\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief DAG\u306E\u5404\
    \u9802\u70B9\u306E\u5165\u6B21\u6570\u3092\u8A08\u7B97\u3059\u308B\n     * @tparam\
    \ T \u6574\u6570\u578B\n     * @param g \u6709\u5411\u30B0\u30E9\u30D5\n     *\
    \ @return vector<T> \u5165\u6B21\u6570\u30EA\u30B9\u30C8\n     * @note O(V + E)\n\
    \     */\n    template <typename T>\n    vector<T> calc_indegrees(const vector<vector<T>>\
    \ &g) {\n        static_assert(is_integral<T>::value, \"T must be integral type\"\
    );\n        vector<T> indeg(g.size(), 0);\n        for (const vector<T> &edges_from_u\
    \ : g) {\n            for (const T &v : edges_from_u) {\n                indeg[v]++;\n\
    \            }\n        }\n        return indeg;\n    }\n\n    /**\n     * @brief\
    \ DAG\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n     * @tparam\
    \ T \u6574\u6570\u578B\n     * @param g DAG\n     * @return vector<T> \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u7D50\u679C\n     * @note O(V + E)\n\
    \    */\n    template <typename T>\n    vector<T> topological_sort(const vector<vector<T>>\
    \ &g) {\n        static_assert(is_integral<T>::value, \"T must be integral type\"\
    );\n        // \u5165\u6B21\u6570\u306E\u8A08\u7B97\n        vector<T> indegs\
    \ = ugilib::calc_indegrees(g);\n\n        // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u9806\u5E8F\u3092\u6C7A\u5B9A\u3059\u308B\n        vector<T> topology;\n    \
    \    queue<T> start_nodes;\n        for (size_t i = 0; i < indegs.size(); i++)\
    \ {\n            if (indegs[i] == 0) start_nodes.push(i);\n        }\n       \
    \ while (!start_nodes.empty()) {\n            // \u5165\u6B21\u65700\u306E\u9802\
    \u70B9\u306E\u9806\u5E8F\u3092\u78BA\u5B9A\n            T node = start_nodes.front();\
    \ start_nodes.pop();\n            topology.push_back(node);\n\n            //\
    \ \u9802\u70B9\u30FB\u8FBA\u3092\u524A\u9664\u3059\u308B\n            for (const\
    \ T &next : g[node]) {  // \u3053\u306E\u9802\u70B9\u304B\u3089\u51FA\u308B\u5168\
    \u3066\u306E\u8FBA\u3092\u524A\u9664\n                if (--indegs[next] == 0)\
    \ {  // \u305D\u308C\u306B\u3088\u3063\u3066\u5165\u6B21\u6570\u304C0\u306B\u306A\
    \u3063\u305F\u3089\n                    start_nodes.push(next);  // \u9806\u5E8F\
    \u3092\u78BA\u5B9A\u3067\u304D\u308B\n                }\n            }\n     \
    \   }\n\n        assert(topology.size() == g.size());  // DAG\u3067\u306A\u3044\
    \u5834\u5408\u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3067\
    \u304D\u306A\u3044\n        return topology;\n    }\n}  // namespace ugilib\n"
  code: "#pragma once\n\n/**\n * @file topological_sort.hpp\n * @brief \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\uFF0C\u5165\u6B21\u6570\u8A08\u7B97\
    \u95A2\u6570\u306E\u5B9A\u7FA9\n*/\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nnamespace ugilib {\n    /**\n     * @brief DAG\u306E\u5404\u9802\u70B9\
    \u306E\u5165\u6B21\u6570\u3092\u8A08\u7B97\u3059\u308B\n     * @tparam T \u6574\
    \u6570\u578B\n     * @param g \u6709\u5411\u30B0\u30E9\u30D5\n     * @return vector<T>\
    \ \u5165\u6B21\u6570\u30EA\u30B9\u30C8\n     * @note O(V + E)\n     */\n    template\
    \ <typename T>\n    vector<T> calc_indegrees(const vector<vector<T>> &g) {\n \
    \       static_assert(is_integral<T>::value, \"T must be integral type\");\n \
    \       vector<T> indeg(g.size(), 0);\n        for (const vector<T> &edges_from_u\
    \ : g) {\n            for (const T &v : edges_from_u) {\n                indeg[v]++;\n\
    \            }\n        }\n        return indeg;\n    }\n\n    /**\n     * @brief\
    \ DAG\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n     * @tparam\
    \ T \u6574\u6570\u578B\n     * @param g DAG\n     * @return vector<T> \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u7D50\u679C\n     * @note O(V + E)\n\
    \    */\n    template <typename T>\n    vector<T> topological_sort(const vector<vector<T>>\
    \ &g) {\n        static_assert(is_integral<T>::value, \"T must be integral type\"\
    );\n        // \u5165\u6B21\u6570\u306E\u8A08\u7B97\n        vector<T> indegs\
    \ = ugilib::calc_indegrees(g);\n\n        // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u9806\u5E8F\u3092\u6C7A\u5B9A\u3059\u308B\n        vector<T> topology;\n    \
    \    queue<T> start_nodes;\n        for (size_t i = 0; i < indegs.size(); i++)\
    \ {\n            if (indegs[i] == 0) start_nodes.push(i);\n        }\n       \
    \ while (!start_nodes.empty()) {\n            // \u5165\u6B21\u65700\u306E\u9802\
    \u70B9\u306E\u9806\u5E8F\u3092\u78BA\u5B9A\n            T node = start_nodes.front();\
    \ start_nodes.pop();\n            topology.push_back(node);\n\n            //\
    \ \u9802\u70B9\u30FB\u8FBA\u3092\u524A\u9664\u3059\u308B\n            for (const\
    \ T &next : g[node]) {  // \u3053\u306E\u9802\u70B9\u304B\u3089\u51FA\u308B\u5168\
    \u3066\u306E\u8FBA\u3092\u524A\u9664\n                if (--indegs[next] == 0)\
    \ {  // \u305D\u308C\u306B\u3088\u3063\u3066\u5165\u6B21\u6570\u304C0\u306B\u306A\
    \u3063\u305F\u3089\n                    start_nodes.push(next);  // \u9806\u5E8F\
    \u3092\u78BA\u5B9A\u3067\u304D\u308B\n                }\n            }\n     \
    \   }\n\n        assert(topology.size() == g.size());  // DAG\u3067\u306A\u3044\
    \u5834\u5408\u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3067\
    \u304D\u306A\u3044\n        return topology;\n    }\n}  // namespace ugilib"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-04-04 16:03:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/ugilib/graph/topological_sort.hpp
- /library/ugilib/graph/topological_sort.hpp.html
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\uFF0C\u5165\u6B21\u6570\
  \u8A08\u7B97\u95A2\u6570\u306E\u5B9A\u7FA9"
---
