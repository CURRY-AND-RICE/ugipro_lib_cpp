---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ugilib/iteration/all_combinations.hpp
    title: "\u5168\u3066\u306ECombination\u306B\u5BFE\u3057\u3066\u95A2\u6570\u3092\
      \u5B9F\u884C\u3059\u308B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/iteration/combinations.test.cpp
    title: tests/iteration/combinations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u751F\u6210\u3059\
      \u308B"
    links: []
  bundledCode: "#line 2 \"ugilib/iteration/next_combination.hpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(size_t i\
    \ = 0; i < n; i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n\
    #line 4 \"ugilib/iteration/next_combination.hpp\"\n\nusing namespace std;\n\n\
    namespace ugilib {\n    /**\n     * @brief \u6B21\u306E\u7D44\u307F\u5408\u308F\
    \u305B\u3092\u751F\u6210\u3059\u308B\n     * @param indices \u73FE\u5728\u306E\
    \u7D44\u307F\u5408\u308F\u305B\n     * @param num_items \u5168\u4F53\u306E\u8981\
    \u7D20\u6570\n     * @return bool \u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u304C\
    \u5B58\u5728\u3059\u308B\u304B\u3069\u3046\u304B\n     * @details \u4F8B\u3048\
    \u3070, indices = {0, 1, 2}, num_items = 5\u306E\u5834\u5408, \u6B21\u306E\u7D44\
    \u307F\u5408\u308F\u305B\u306F{0, 1, 3}\u3068\u306A\u308B\n     * @details \u3053\
    \u308C\u3092\u30E9\u30C3\u30D7\u3057\u305F\u3082\u306E\u304Cexec_all_combination\n\
    \    */\n    bool next_combination(vector<size_t> &indices, const size_t &num_items)\
    \ {\n        const int num_pick = indices.size();\n        for (signed i = num_pick\
    \ - 1; i >= 0; i--) {\n            if (indices[i] < num_items - num_pick + i)\
    \ {\n                indices[i]++;\n                for (size_t j = i + 1; j <\
    \ num_pick; j++) {\n                    indices[j] = indices[j - 1] + 1;\n   \
    \             }\n                return true;\n            }\n        }\n    \
    \    return false;\n    }\n} // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/definitions.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u6B21\u306E\
    \u7D44\u307F\u5408\u308F\u305B\u3092\u751F\u6210\u3059\u308B\n     * @param indices\
    \ \u73FE\u5728\u306E\u7D44\u307F\u5408\u308F\u305B\n     * @param num_items \u5168\
    \u4F53\u306E\u8981\u7D20\u6570\n     * @return bool \u6B21\u306E\u7D44\u307F\u5408\
    \u308F\u305B\u304C\u5B58\u5728\u3059\u308B\u304B\u3069\u3046\u304B\n     * @details\
    \ \u4F8B\u3048\u3070, indices = {0, 1, 2}, num_items = 5\u306E\u5834\u5408, \u6B21\
    \u306E\u7D44\u307F\u5408\u308F\u305B\u306F{0, 1, 3}\u3068\u306A\u308B\n     *\
    \ @details \u3053\u308C\u3092\u30E9\u30C3\u30D7\u3057\u305F\u3082\u306E\u304C\
    exec_all_combination\n    */\n    bool next_combination(vector<size_t> &indices,\
    \ const size_t &num_items) {\n        const int num_pick = indices.size();\n \
    \       for (signed i = num_pick - 1; i >= 0; i--) {\n            if (indices[i]\
    \ < num_items - num_pick + i) {\n                indices[i]++;\n             \
    \   for (size_t j = i + 1; j < num_pick; j++) {\n                    indices[j]\
    \ = indices[j - 1] + 1;\n                }\n                return true;\n   \
    \         }\n        }\n        return false;\n    }\n} // namespace ugilib"
  dependsOn:
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/iteration/next_combination.hpp
  requiredBy:
  - ugilib/iteration/all_combinations.hpp
  timestamp: '2024-04-03 22:46:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/iteration/combinations.test.cpp
documentation_of: ugilib/iteration/next_combination.hpp
layout: document
redirect_from:
- /library/ugilib/iteration/next_combination.hpp
- /library/ugilib/iteration/next_combination.hpp.html
title: "\u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u751F\u6210\u3059\u308B"
---
