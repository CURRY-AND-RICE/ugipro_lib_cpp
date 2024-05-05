---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  - icon: ':heavy_check_mark:'
    path: ugilib/iteration/next_combination.hpp
    title: "\u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u751F\u6210\u3059\u308B"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/iteration/combinations.test.cpp
    title: tests/iteration/combinations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5168\u3066\u306E\u9806\u5217/\u7D44\u307F\u5408\u308F\u305B\
      \u306B\u5BFE\u3059\u308B\u51E6\u7406\u3092\u7C21\u7565\u5316\u3059\u308B\u95A2\
      \u6570"
    links: []
  bundledCode: "#line 2 \"ugilib/iteration/all_combinations.hpp\"\n\n/**\n * @file\
    \ all_combinations.hpp\n * @brief \u5168\u3066\u306E\u9806\u5217/\u7D44\u307F\u5408\
    \u308F\u305B\u306B\u5BFE\u3059\u308B\u51E6\u7406\u3092\u7C21\u7565\u5316\u3059\
    \u308B\u95A2\u6570\n *\n * ## \u95A2\u6570\u4E00\u89A7\n * - `exec_all_combinations(num_items,\
    \ num_pick, f)` : \u5168\u3066\u306E\u7D44\u307F\u5408\u308F\u305B\u306B\u5BFE\
    \u3057\u3066\u6307\u5B9A\u3055\u308C\u305F\u95A2\u6570\u3092\u5B9F\u884C\u3057\
    \u307E\u3059.\n * - `exec_all_permutations(num_items, num_pick, f)` : \u5168\u3066\
    \u306E\u9806\u5217\u306B\u5BFE\u3057\u3066\u6307\u5B9A\u3055\u308C\u305F\u95A2\
    \u6570\u3092\u5B9F\u884C\u3057\u307E\u3059.\n */\n\n#include <bits/stdc++.h>\n\
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
    \    return false;\n    }\n} // namespace ugilib\n#line 15 \"ugilib/iteration/all_combinations.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u5168\u3066\
    \u306ECombination\u306B\u5BFE\u3057\u3066\u95A2\u6570\u3092\u5B9F\u884C\u3059\u308B\
    \n     * @tparam Func \u5B9F\u884C\u64CD\u4F5C\u306E\u30E9\u30E0\u30C0\u5F0F\n\
    \     * @param num_items \u9078\u629E\u5BFE\u8C61\u5168\u4F53\u306E\u8981\u7D20\
    \u6570\n     * @param num_pick \u9078\u629E\u3059\u308B\u8981\u7D20\u6570\n  \
    \   * @param f \u5B9F\u884C\u3059\u308B\u95A2\u6570. true\u3092\u8FD4\u3059\u3068\
    \u63A2\u7D22\u3092\u6253\u3061\u5207\u308B\n     * @return \u9014\u4E2D\u3067\u63A2\
    \u7D22\u3092\u6253\u3061\u5207\u3063\u305F\u5834\u5408\u306Ftrue, \u305D\u308C\
    \u4EE5\u5916\u306Ffalse\n     * @details \u30E9\u30E0\u30C0\u5F0F\u306B\u306F\u9078\
    \u629E\u3057\u305F\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304C\
    \u6607\u9806\u3067\u6E21\u3055\u308C\u308B\n     * @details num_items\u500B\u306E\
    \u4E2D\u304B\u3089num_pick\u500B\u9078\u3076\u7D44\u307F\u5408\u308F\u305B\u3092\
    \u5168\u63A2\u7D22\u3057, \u305D\u308C\u305E\u308C\u306B\u5BFE\u3057\u3066\u95A2\
    \u6570f\u3092\u5B9F\u884C\u3059\u308B\n     * @example\n     * auto f = [&](const\
    \ vector<size_t> &indices) {\n     *    for (const auto &i : indices) {\n    \
    \ *       cout << i << \" \";\n     *    }\n     *    cout << endl;\n     *  \
    \  return false;\n     * };\n     * exec_all_combination(5, 3, f);\n    */\n \
    \   template <typename Func>\n    bool exec_all_combinations(const size_t &num_items,\
    \ const size_t &num_pick, Func f) {\n        vector<size_t> indices(num_pick);\n\
    \        iota(indices.begin(), indices.end(), 0);\n        do {\n            bool\
    \ will_break = f(indices);\n            if (will_break) return true;\n       \
    \ } while (next_combination(indices, num_items));\n        return false;\n   \
    \ }\n\n    /**\n     * @brief \u5168\u3066\u306EPermutation\u306B\u5BFE\u3057\u3066\
    \u95A2\u6570\u3092\u5B9F\u884C\u3059\u308B. \u9806\u5217\u306B\u5B58\u5728\u3057\
    \u3046\u308B\u8981\u7D20\u6570\u3088\u308A, \u5B9F\u969B\u306E\u8981\u7D20\u6570\
    \u304C\u5C0F\u3055\u304F\u3066\u3082\u5B9F\u884C\u53EF\u80FD\n     * @tparam Func\
    \ \u5B9F\u884C\u64CD\u4F5C\u306E\u30E9\u30E0\u30C0\u5F0F\n     * @param num_items\
    \ \u9078\u629E\u5BFE\u8C61\u5168\u4F53\u306E\u8981\u7D20\u6570\n     * @param\
    \ num_pick \u9078\u629E\u3059\u308B\u8981\u7D20\u6570\n     * @param f \u5B9F\u884C\
    \u3059\u308B\u95A2\u6570. true\u3092\u8FD4\u3059\u3068\u63A2\u7D22\u3092\u6253\
    \u3061\u5207\u308B\n     * @return \u9014\u4E2D\u3067\u63A2\u7D22\u3092\u6253\u3061\
    \u5207\u3063\u305F\u5834\u5408\u306Ftrue, \u305D\u308C\u4EE5\u5916\u306Ffalse\n\
    \     * @details \u30E9\u30E0\u30C0\u5F0F\u306B\u306F\u9078\u629E\u3057\u305F\u8981\
    \u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306E\u9806\u5217\u304C\u6E21\
    \u3055\u308C\u308B\n     * @details num_items\u500B\u306E\u4E2D\u304B\u3089num_pick\u500B\
    \u9078\u3076\u9806\u5217\u3092\u5168\u63A2\u7D22\u3057, \u305D\u308C\u305E\u308C\
    \u306B\u5BFE\u3057\u3066\u95A2\u6570f\u3092\u5B9F\u884C\u3059\u308B\n     * @details\
    \ next_permutation \u3068\u306E\u9055\u3044\u306F, \u9078\u629E\u5BFE\u8C61\u5168\
    \u4F53\u306E\u8981\u7D20\u6570\u3088\u308A\u3082\u5B9F\u969B\u306B\u9078\u629E\
    \u3059\u308B\u8981\u7D20\u6570\u304C\u5C11\u306A\u3044\u5834\u5408\u3067\u3082\
    \u5B9F\u884C\u53EF\u80FD\u306A\u70B9\n     * @details num_items choose num_pick\
    \ \u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u5168\u63A2\u7D22\u3059\u308B\n \
    \    * @example\n     * auto f = [&](const vector<size_t> &indices) {\n     *\
    \   for (const auto &i : indices) {\n     *      cout << i << \" \";\n     * \
    \  }\n     *   cout << endl;\n     *   return false;\n     * };\n     * exec_all_permutations(5,\
    \ 3, f);\n    */\n    template <typename Func>\n    bool exec_all_permutations(const\
    \ size_t &num_items, const size_t &num_pick, Func f) {\n        // \u5168\u8981\
    \u7D20\u304B\u3089num_pick\u500B\u3060\u3051\u9078\u3070\u308C\u308B\n       \
    \ vector<bool> mask(num_items, false);\n        fill(mask.begin(), mask.begin()\
    \ + num_pick, true);  // \u9078\u3070\u308C\u308B\u8981\u7D20\u306E\u30DE\u30B9\
    \u30AF\n\n        // \u9014\u4E2D\u7D42\u4E86\u30D5\u30E9\u30B0\n        bool\
    \ will_break = false;\n        do {\n            // mask\u3059\u308B\n       \
    \     vector<size_t> permutation;\n            for (int i = 0; i < mask.size();\
    \ i++) {\n                if (mask[i]) permutation.push_back(i);\n           \
    \ }\n\n            // mask\u8981\u7D20\u3067\u9806\u5217\u5168\u3066\u306B\u5BFE\
    \u3057\u3066\u64CD\u4F5C\u3092\u884C\u3046\n            do {\n               \
    \ will_break = f(permutation);\n                if (will_break) return true; \
    \ // \u9014\u4E2D\u7D42\u4E86\n            } while (next_permutation(permutation.begin(),\
    \ permutation.end()));\n        } while (prev_permutation(mask.begin(), mask.end()));\n\
    \n        return false;  // \u5168\u63A2\u7D22\u7D42\u4E86\n    }\n}  // namespace\
    \ ugilib\n"
  code: "#pragma once\n\n/**\n * @file all_combinations.hpp\n * @brief \u5168\u3066\
    \u306E\u9806\u5217/\u7D44\u307F\u5408\u308F\u305B\u306B\u5BFE\u3059\u308B\u51E6\
    \u7406\u3092\u7C21\u7565\u5316\u3059\u308B\u95A2\u6570\n *\n * ## \u95A2\u6570\
    \u4E00\u89A7\n * - `exec_all_combinations(num_items, num_pick, f)` : \u5168\u3066\
    \u306E\u7D44\u307F\u5408\u308F\u305B\u306B\u5BFE\u3057\u3066\u6307\u5B9A\u3055\
    \u308C\u305F\u95A2\u6570\u3092\u5B9F\u884C\u3057\u307E\u3059.\n * - `exec_all_permutations(num_items,\
    \ num_pick, f)` : \u5168\u3066\u306E\u9806\u5217\u306B\u5BFE\u3057\u3066\u6307\
    \u5B9A\u3055\u308C\u305F\u95A2\u6570\u3092\u5B9F\u884C\u3057\u307E\u3059.\n */\n\
    \n#include <bits/stdc++.h>\n#include \"ugilib/base/definitions.hpp\"\n#include\
    \ \"ugilib/iteration/next_combination.hpp\"\n\nusing namespace std;\n\nnamespace\
    \ ugilib {\n    /**\n     * @brief \u5168\u3066\u306ECombination\u306B\u5BFE\u3057\
    \u3066\u95A2\u6570\u3092\u5B9F\u884C\u3059\u308B\n     * @tparam Func \u5B9F\u884C\
    \u64CD\u4F5C\u306E\u30E9\u30E0\u30C0\u5F0F\n     * @param num_items \u9078\u629E\
    \u5BFE\u8C61\u5168\u4F53\u306E\u8981\u7D20\u6570\n     * @param num_pick \u9078\
    \u629E\u3059\u308B\u8981\u7D20\u6570\n     * @param f \u5B9F\u884C\u3059\u308B\
    \u95A2\u6570. true\u3092\u8FD4\u3059\u3068\u63A2\u7D22\u3092\u6253\u3061\u5207\
    \u308B\n     * @return \u9014\u4E2D\u3067\u63A2\u7D22\u3092\u6253\u3061\u5207\u3063\
    \u305F\u5834\u5408\u306Ftrue, \u305D\u308C\u4EE5\u5916\u306Ffalse\n     * @details\
    \ \u30E9\u30E0\u30C0\u5F0F\u306B\u306F\u9078\u629E\u3057\u305F\u8981\u7D20\u306E\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304C\u6607\u9806\u3067\u6E21\u3055\u308C\
    \u308B\n     * @details num_items\u500B\u306E\u4E2D\u304B\u3089num_pick\u500B\u9078\
    \u3076\u7D44\u307F\u5408\u308F\u305B\u3092\u5168\u63A2\u7D22\u3057, \u305D\u308C\
    \u305E\u308C\u306B\u5BFE\u3057\u3066\u95A2\u6570f\u3092\u5B9F\u884C\u3059\u308B\
    \n     * @example\n     * auto f = [&](const vector<size_t> &indices) {\n    \
    \ *    for (const auto &i : indices) {\n     *       cout << i << \" \";\n   \
    \  *    }\n     *    cout << endl;\n     *    return false;\n     * };\n     *\
    \ exec_all_combination(5, 3, f);\n    */\n    template <typename Func>\n    bool\
    \ exec_all_combinations(const size_t &num_items, const size_t &num_pick, Func\
    \ f) {\n        vector<size_t> indices(num_pick);\n        iota(indices.begin(),\
    \ indices.end(), 0);\n        do {\n            bool will_break = f(indices);\n\
    \            if (will_break) return true;\n        } while (next_combination(indices,\
    \ num_items));\n        return false;\n    }\n\n    /**\n     * @brief \u5168\u3066\
    \u306EPermutation\u306B\u5BFE\u3057\u3066\u95A2\u6570\u3092\u5B9F\u884C\u3059\u308B\
    . \u9806\u5217\u306B\u5B58\u5728\u3057\u3046\u308B\u8981\u7D20\u6570\u3088\u308A\
    , \u5B9F\u969B\u306E\u8981\u7D20\u6570\u304C\u5C0F\u3055\u304F\u3066\u3082\u5B9F\
    \u884C\u53EF\u80FD\n     * @tparam Func \u5B9F\u884C\u64CD\u4F5C\u306E\u30E9\u30E0\
    \u30C0\u5F0F\n     * @param num_items \u9078\u629E\u5BFE\u8C61\u5168\u4F53\u306E\
    \u8981\u7D20\u6570\n     * @param num_pick \u9078\u629E\u3059\u308B\u8981\u7D20\
    \u6570\n     * @param f \u5B9F\u884C\u3059\u308B\u95A2\u6570. true\u3092\u8FD4\
    \u3059\u3068\u63A2\u7D22\u3092\u6253\u3061\u5207\u308B\n     * @return \u9014\u4E2D\
    \u3067\u63A2\u7D22\u3092\u6253\u3061\u5207\u3063\u305F\u5834\u5408\u306Ftrue,\
    \ \u305D\u308C\u4EE5\u5916\u306Ffalse\n     * @details \u30E9\u30E0\u30C0\u5F0F\
    \u306B\u306F\u9078\u629E\u3057\u305F\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u306E\u9806\u5217\u304C\u6E21\u3055\u308C\u308B\n     * @details\
    \ num_items\u500B\u306E\u4E2D\u304B\u3089num_pick\u500B\u9078\u3076\u9806\u5217\
    \u3092\u5168\u63A2\u7D22\u3057, \u305D\u308C\u305E\u308C\u306B\u5BFE\u3057\u3066\
    \u95A2\u6570f\u3092\u5B9F\u884C\u3059\u308B\n     * @details next_permutation\
    \ \u3068\u306E\u9055\u3044\u306F, \u9078\u629E\u5BFE\u8C61\u5168\u4F53\u306E\u8981\
    \u7D20\u6570\u3088\u308A\u3082\u5B9F\u969B\u306B\u9078\u629E\u3059\u308B\u8981\
    \u7D20\u6570\u304C\u5C11\u306A\u3044\u5834\u5408\u3067\u3082\u5B9F\u884C\u53EF\
    \u80FD\u306A\u70B9\n     * @details num_items choose num_pick \u306E\u7D44\u307F\
    \u5408\u308F\u305B\u3092\u5168\u63A2\u7D22\u3059\u308B\n     * @example\n    \
    \ * auto f = [&](const vector<size_t> &indices) {\n     *   for (const auto &i\
    \ : indices) {\n     *      cout << i << \" \";\n     *   }\n     *   cout <<\
    \ endl;\n     *   return false;\n     * };\n     * exec_all_permutations(5, 3,\
    \ f);\n    */\n    template <typename Func>\n    bool exec_all_permutations(const\
    \ size_t &num_items, const size_t &num_pick, Func f) {\n        // \u5168\u8981\
    \u7D20\u304B\u3089num_pick\u500B\u3060\u3051\u9078\u3070\u308C\u308B\n       \
    \ vector<bool> mask(num_items, false);\n        fill(mask.begin(), mask.begin()\
    \ + num_pick, true);  // \u9078\u3070\u308C\u308B\u8981\u7D20\u306E\u30DE\u30B9\
    \u30AF\n\n        // \u9014\u4E2D\u7D42\u4E86\u30D5\u30E9\u30B0\n        bool\
    \ will_break = false;\n        do {\n            // mask\u3059\u308B\n       \
    \     vector<size_t> permutation;\n            for (int i = 0; i < mask.size();\
    \ i++) {\n                if (mask[i]) permutation.push_back(i);\n           \
    \ }\n\n            // mask\u8981\u7D20\u3067\u9806\u5217\u5168\u3066\u306B\u5BFE\
    \u3057\u3066\u64CD\u4F5C\u3092\u884C\u3046\n            do {\n               \
    \ will_break = f(permutation);\n                if (will_break) return true; \
    \ // \u9014\u4E2D\u7D42\u4E86\n            } while (next_permutation(permutation.begin(),\
    \ permutation.end()));\n        } while (prev_permutation(mask.begin(), mask.end()));\n\
    \n        return false;  // \u5168\u63A2\u7D22\u7D42\u4E86\n    }\n}  // namespace\
    \ ugilib\n"
  dependsOn:
  - ugilib/base/definitions.hpp
  - ugilib/iteration/next_combination.hpp
  isVerificationFile: false
  path: ugilib/iteration/all_combinations.hpp
  requiredBy: []
  timestamp: '2024-05-03 21:18:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/iteration/combinations.test.cpp
documentation_of: ugilib/iteration/all_combinations.hpp
layout: document
redirect_from:
- /library/ugilib/iteration/all_combinations.hpp
- /library/ugilib/iteration/all_combinations.hpp.html
title: "\u5168\u3066\u306E\u9806\u5217/\u7D44\u307F\u5408\u308F\u305B\u306B\u5BFE\u3059\
  \u308B\u51E6\u7406\u3092\u7C21\u7565\u5316\u3059\u308B\u95A2\u6570"
---
