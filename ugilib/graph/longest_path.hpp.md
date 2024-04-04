---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "DAG\u306E\u6700\u9577\u30D1\u30B9\u9577\u3092\u6C42\u3081\u308B\
      \u95A2\u6570\u306E\u5B9A\u7FA9"
    links: []
  bundledCode: "#line 2 \"ugilib/graph/longest_path.hpp\"\n\n/**\n * @file longest_path.hpp\n\
    \ * @brief DAG\u306E\u6700\u9577\u30D1\u30B9\u9577\u3092\u6C42\u3081\u308B\u95A2\
    \u6570\u306E\u5B9A\u7FA9\n * @note \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
    \u30C8\u7D50\u679C\u3092\u4F7F\u3046\u304C\uFF0Cuginilib/graph/topological_sort.hpp\
    \ \u306B topological_sort() \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\n\
    */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace ugilib {\n \
    \   /**\n     * @brief DAG\u306E\u6700\u9577\u30D1\u30B9\u9577\u3092\u6C42\u3081\
    \u308B\n     * @tparam T \u6574\u6570\u578B\n     * @param g DAG\n     * @param\
    \ topology \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u7D50\u679C\
    . ugilib/graph/topological_sort.hpp \u306E topological_sort() \u3092\u4F7F\u3046\
    \n     * @return T \u6700\u9577\u30D1\u30B9\u9577\n     * @note O(V + E)\n   \
    \  * @note \u30B0\u30E9\u30D5dp\u306E\u4E00\u7A2E\n    */\n    template <typename\
    \ T>\n    T longest_path_length(const vector<vector<T>> &g, const vector<T> &topology)\
    \ {\n        static_assert(is_integral<T>::value, \"T must be integral type\"\
    );\n        // \u30CE\u30FC\u30C9\u306B\u5165\u308B\u8FBA\u306E\u5143\u306E\u30CE\
    \u30FC\u30C9\u3092\u8A18\u9332\u3059\u308B\n        vector<vector<T>> sources(g.size());\n\
    \        for (size_t i = 0; i < g.size(); i++) {\n            for (const T &next\
    \ : g[i]) {\n                sources[next].push_back(i);\n            }\n    \
    \    }\n\n        // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u3067\u51E6\
    \u7406\u3059\u308B\n        vector<T> lengths(g.size(), 0);  // \u305D\u306E\u9802\
    \u70B9\u306B\u5230\u9054\u3059\u308B\u307E\u3067\u306E\u6700\u9577\u30D1\u30B9\
    \u306E\u9577\u3055\n        for (const T &node : topology) {\n            for\
    \ (const T &source : sources[node]) {\n                lengths[node] = max(lengths[node],\
    \ lengths[source] + 1);\n            }\n        }\n\n        return *max_element(lengths.begin(),\
    \ lengths.end());\n    }\n}  // namespace ugilib\n"
  code: "#pragma once\n\n/**\n * @file longest_path.hpp\n * @brief DAG\u306E\u6700\
    \u9577\u30D1\u30B9\u9577\u3092\u6C42\u3081\u308B\u95A2\u6570\u306E\u5B9A\u7FA9\
    \n * @note \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u7D50\u679C\u3092\
    \u4F7F\u3046\u304C\uFF0Cuginilib/graph/topological_sort.hpp \u306B topological_sort()\
    \ \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\n*/\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief DAG\u306E\u6700\
    \u9577\u30D1\u30B9\u9577\u3092\u6C42\u3081\u308B\n     * @tparam T \u6574\u6570\
    \u578B\n     * @param g DAG\n     * @param topology \u30C8\u30DD\u30ED\u30B8\u30AB\
    \u30EB\u30BD\u30FC\u30C8\u7D50\u679C. ugilib/graph/topological_sort.hpp \u306E\
    \ topological_sort() \u3092\u4F7F\u3046\n     * @return T \u6700\u9577\u30D1\u30B9\
    \u9577\n     * @note O(V + E)\n     * @note \u30B0\u30E9\u30D5dp\u306E\u4E00\u7A2E\
    \n    */\n    template <typename T>\n    T longest_path_length(const vector<vector<T>>\
    \ &g, const vector<T> &topology) {\n        static_assert(is_integral<T>::value,\
    \ \"T must be integral type\");\n        // \u30CE\u30FC\u30C9\u306B\u5165\u308B\
    \u8FBA\u306E\u5143\u306E\u30CE\u30FC\u30C9\u3092\u8A18\u9332\u3059\u308B\n   \
    \     vector<vector<T>> sources(g.size());\n        for (size_t i = 0; i < g.size();\
    \ i++) {\n            for (const T &next : g[i]) {\n                sources[next].push_back(i);\n\
    \            }\n        }\n\n        // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\
    \u5E8F\u3067\u51E6\u7406\u3059\u308B\n        vector<T> lengths(g.size(), 0);\
    \  // \u305D\u306E\u9802\u70B9\u306B\u5230\u9054\u3059\u308B\u307E\u3067\u306E\
    \u6700\u9577\u30D1\u30B9\u306E\u9577\u3055\n        for (const T &node : topology)\
    \ {\n            for (const T &source : sources[node]) {\n                lengths[node]\
    \ = max(lengths[node], lengths[source] + 1);\n            }\n        }\n\n   \
    \     return *max_element(lengths.begin(), lengths.end());\n    }\n}  // namespace\
    \ ugilib"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/graph/longest_path.hpp
  requiredBy: []
  timestamp: '2024-04-04 16:03:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/graph/longest_path.hpp
layout: document
redirect_from:
- /library/ugilib/graph/longest_path.hpp
- /library/ugilib/graph/longest_path.hpp.html
title: "DAG\u306E\u6700\u9577\u30D1\u30B9\u9577\u3092\u6C42\u3081\u308B\u95A2\u6570\
  \u306E\u5B9A\u7FA9"
---
