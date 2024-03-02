---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/constants.hpp
    title: ugilib/base/constants.hpp
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  - icon: ':warning:'
    path: ugilib/bits/bit_util.hpp
    title: num_to_bits
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: bit_exhaustive_search
    links: []
  bundledCode: "#line 2 \"ugilib/bits/bit_exhaustive_search.hpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(int i =\
    \ 0; i < (int)(n); i++)  // rep macro\n#define all(v) begin(v), end(v)  // all\
    \ iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\nconst ll INF = 1LL << 60;\
    \  // infinity\n#line 4 \"ugilib/bits/bit_util.hpp\"\n\nusing namespace std;\n\
    \nnamespace ugilib {\n/**\n * @brief num_to_bits\n * @param num an integer to\
    \ be converted to bits\n * @param digit the number of bits\n * @return vector<bool>\
    \ bits of num\n * @details convert an integer to bits\n*/\nvector<bool> num_to_bits(const\
    \ ll num, const size_t &digit) {\n    vector<bool> bits(digit);\n    for (int\
    \ i = 0; i < digit; i++) {\n        bits[i] = (num >> i) & 1U;\n    }\n    return\
    \ bits;\n}\n\n/**\n * @brief bits_to_num\n * @param bits a vector of bits\n *\
    \ @return ll an integer of bits\n * @details convert bits to an integer\n*/\n\
    ll bits_to_num(const vector<bool> &bits) {\n    ll num = 0;\n    for (int i =\
    \ 0; i < bits.size(); i++) {\n        num += bits[i] << i;\n    }\n    return\
    \ num;\n}\n}  // namespace ugilib\n#line 4 \"ugilib/bits/bit_exhaustive_search.hpp\"\
    \n\nnamespace ugilib {\n/**\n * @brief bit_exhaustive_search\n * @param digit\
    \ the number of bits\n * @param f a function to be called with bits\n * @details\
    \ exhaustive search for bits\n *\n * @example\n * vector<int> ans;\n * auto f\
    \ = [&](const auto &&bits) {\n *    if (count(bits.begin(), bits.end(), true)\
    \ == 2) {\n *        ans.push_back(bits_to_num(bits));\n *   }\n * };\n * bit_exhaustive_search(4,\
    \ f);\n * // ans = {3, 5, 6, 9, 10, 12}\n *\n*/\ntemplate <typename Func>\nvoid\
    \ bit_exhaustive_search(const size_t &digit, Func f) {\n    for (ll i = 0; i <\
    \ (1 << digit); i++) {\n        f(num_to_bits(i, digit));\n    }\n}\n}  // namespace\
    \ ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/bits/bit_util.hpp\"\
    \n\nnamespace ugilib {\n/**\n * @brief bit_exhaustive_search\n * @param digit\
    \ the number of bits\n * @param f a function to be called with bits\n * @details\
    \ exhaustive search for bits\n *\n * @example\n * vector<int> ans;\n * auto f\
    \ = [&](const auto &&bits) {\n *    if (count(bits.begin(), bits.end(), true)\
    \ == 2) {\n *        ans.push_back(bits_to_num(bits));\n *   }\n * };\n * bit_exhaustive_search(4,\
    \ f);\n * // ans = {3, 5, 6, 9, 10, 12}\n *\n*/\ntemplate <typename Func>\nvoid\
    \ bit_exhaustive_search(const size_t &digit, Func f) {\n    for (ll i = 0; i <\
    \ (1 << digit); i++) {\n        f(num_to_bits(i, digit));\n    }\n}\n}  // namespace\
    \ ugilib\n"
  dependsOn:
  - ugilib/bits/bit_util.hpp
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/bits/bit_exhaustive_search.hpp
  requiredBy: []
  timestamp: '2024-03-02 16:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/bits/bit_exhaustive_search.hpp
layout: document
redirect_from:
- /library/ugilib/bits/bit_exhaustive_search.hpp
- /library/ugilib/bits/bit_exhaustive_search.hpp.html
title: bit_exhaustive_search
---
