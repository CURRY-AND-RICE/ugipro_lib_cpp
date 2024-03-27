---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy: []
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
  bundledCode: "#line 2 \"ugilib/iteration/combinations.hpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(int i =\
    \ 0; i < (int)(n); i++)  // rep macro\n#define all(v) begin(v), end(v)  // all\
    \ iterator\n#line 4 \"ugilib/iteration/combinations.hpp\"\n\nusing namespace std;\n\
    \nnamespace ugilib {\n/**\n * @brief \u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\
    \u3092\u751F\u6210\u3059\u308B\n * @param indices \u73FE\u5728\u306E\u7D44\u307F\
    \u5408\u308F\u305B\n * @param num_items \u5168\u4F53\u306E\u8981\u7D20\u6570\n\
    \ * @return bool \u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u304C\u5B58\u5728\u3059\
    \u308B\u304B\u3069\u3046\u304B\n * @details \u4F8B\u3048\u3070, indices = {0,\
    \ 1, 2}, num_items = 5\u306E\u5834\u5408, \u6B21\u306E\u7D44\u307F\u5408\u308F\
    \u305B\u306F{0, 1, 3}\u3068\u306A\u308B\n * @details \u3053\u308C\u3092\u30E9\u30C3\
    \u30D7\u3057\u305F\u3082\u306E\u304Cexec_all_combination\n*/\nbool next_combination(vector<size_t>\
    \ &indices, const size_t &num_items) {\n    const int num_pick = indices.size();\n\
    \    for (signed i = num_pick - 1; i >= 0; i--) {\n        if (indices[i] < num_items\
    \ - num_pick + i) {\n            indices[i]++;\n            for (size_t j = i\
    \ + 1; j < num_pick; j++) {\n                indices[j] = indices[j - 1] + 1;\n\
    \            }\n            return true;\n        }\n    }\n    return false;\n\
    }\n\n/**\n * @brief num_items\u500B\u306E\u4E2D\u304B\u3089num_pick\u500B\u9078\
    \u3076\u7D44\u307F\u5408\u308F\u305B\u3092\u5168\u63A2\u7D22\u3057, \u305D\u308C\
    \u305E\u308C\u306B\u5BFE\u3057\u3066\u95A2\u6570f\u3092\u5B9F\u884C\u3059\u308B\
    \n * @tparam Func \u30E9\u30E0\u30C0\u5F0F\n * @param num_items \u9078\u629E\u5BFE\
    \u8C61\u5168\u4F53\u306E\u8981\u7D20\u6570\n * @param num_pick \u9078\u629E\u3059\
    \u308B\u8981\u7D20\u6570\n * @param f \u5B9F\u884C\u3059\u308B\u95A2\u6570. true\u3092\
    \u8FD4\u3059\u3068\u63A2\u7D22\u3092\u6253\u3061\u5207\u308B\n * @details \u30E9\
    \u30E0\u30C0\u5F0F\u306B\u306F\u9078\u629E\u3057\u305F\u8981\u7D20\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u304C\u6607\u9806\u3067\u6E21\u3055\u308C\u308B\
    \n * @example\n * auto f = [&](const vector<size_t> &indices) {\n *    for (const\
    \ auto &i : indices) {\n *       cout << i << \" \";\n *   }\n *  cout << endl;\n\
    \ * return false;\n * };\n * exec_all_combination(5, 3, f);\n*/\ntemplate <typename\
    \ Func>\nvoid exec_all_combinations(const size_t &num_items, const size_t &num_pick,\
    \ Func f) {\n    vector<size_t> indices(num_pick);\n    iota(indices.begin(),\
    \ indices.end(), 0);\n    do {\n        bool will_break = f(indices);\n      \
    \  if (will_break) break;\n    } while (next_combination(indices, num_items));\n\
    }\n}  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/definitions.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n/**\n * @brief \u6B21\u306E\u7D44\
    \u307F\u5408\u308F\u305B\u3092\u751F\u6210\u3059\u308B\n * @param indices \u73FE\
    \u5728\u306E\u7D44\u307F\u5408\u308F\u305B\n * @param num_items \u5168\u4F53\u306E\
    \u8981\u7D20\u6570\n * @return bool \u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\
    \u304C\u5B58\u5728\u3059\u308B\u304B\u3069\u3046\u304B\n * @details \u4F8B\u3048\
    \u3070, indices = {0, 1, 2}, num_items = 5\u306E\u5834\u5408, \u6B21\u306E\u7D44\
    \u307F\u5408\u308F\u305B\u306F{0, 1, 3}\u3068\u306A\u308B\n * @details \u3053\u308C\
    \u3092\u30E9\u30C3\u30D7\u3057\u305F\u3082\u306E\u304Cexec_all_combination\n*/\n\
    bool next_combination(vector<size_t> &indices, const size_t &num_items) {\n  \
    \  const int num_pick = indices.size();\n    for (signed i = num_pick - 1; i >=\
    \ 0; i--) {\n        if (indices[i] < num_items - num_pick + i) {\n          \
    \  indices[i]++;\n            for (size_t j = i + 1; j < num_pick; j++) {\n  \
    \              indices[j] = indices[j - 1] + 1;\n            }\n            return\
    \ true;\n        }\n    }\n    return false;\n}\n\n/**\n * @brief num_items\u500B\
    \u306E\u4E2D\u304B\u3089num_pick\u500B\u9078\u3076\u7D44\u307F\u5408\u308F\u305B\
    \u3092\u5168\u63A2\u7D22\u3057, \u305D\u308C\u305E\u308C\u306B\u5BFE\u3057\u3066\
    \u95A2\u6570f\u3092\u5B9F\u884C\u3059\u308B\n * @tparam Func \u30E9\u30E0\u30C0\
    \u5F0F\n * @param num_items \u9078\u629E\u5BFE\u8C61\u5168\u4F53\u306E\u8981\u7D20\
    \u6570\n * @param num_pick \u9078\u629E\u3059\u308B\u8981\u7D20\u6570\n * @param\
    \ f \u5B9F\u884C\u3059\u308B\u95A2\u6570. true\u3092\u8FD4\u3059\u3068\u63A2\u7D22\
    \u3092\u6253\u3061\u5207\u308B\n * @details \u30E9\u30E0\u30C0\u5F0F\u306B\u306F\
    \u9078\u629E\u3057\u305F\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u304C\u6607\u9806\u3067\u6E21\u3055\u308C\u308B\n * @example\n * auto f = [&](const\
    \ vector<size_t> &indices) {\n *    for (const auto &i : indices) {\n *      \
    \ cout << i << \" \";\n *   }\n *  cout << endl;\n * return false;\n * };\n *\
    \ exec_all_combination(5, 3, f);\n*/\ntemplate <typename Func>\nvoid exec_all_combinations(const\
    \ size_t &num_items, const size_t &num_pick, Func f) {\n    vector<size_t> indices(num_pick);\n\
    \    iota(indices.begin(), indices.end(), 0);\n    do {\n        bool will_break\
    \ = f(indices);\n        if (will_break) break;\n    } while (next_combination(indices,\
    \ num_items));\n}\n}  // namespace ugilib\n"
  dependsOn:
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/iteration/combinations.hpp
  requiredBy: []
  timestamp: '2024-03-27 18:24:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/iteration/combinations.test.cpp
documentation_of: ugilib/iteration/combinations.hpp
layout: document
redirect_from:
- /library/ugilib/iteration/combinations.hpp
- /library/ugilib/iteration/combinations.hpp.html
title: "\u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u751F\u6210\u3059\u308B"
---
