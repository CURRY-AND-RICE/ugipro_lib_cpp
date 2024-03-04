---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/constants.hpp
    title: ugilib/base/constants.hpp
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ugilib/bits/bit_exhaustive_search.hpp
    title: bit_exhaustive_search
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: num_to_bits
    links: []
  bundledCode: "#line 2 \"ugilib/bits/bit_util.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\n#define rep(i, n) for(int i = 0; i < (int)(n);\
    \ i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n#line\
    \ 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants {\n    template<typename\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / 4;\n} // namespace\
    \ ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"\
    ugilib/bits/bit_util.hpp\"\n\nusing namespace std;\n\nnamespace ugilib {\n/**\n\
    \ * @brief num_to_bits\n * @param num an integer to be converted to bits\n * @param\
    \ digit the number of bits\n * @return vector<bool> bits of num\n * @details convert\
    \ an integer to bits\n*/\nvector<bool> num_to_bits(const ll num, const size_t\
    \ &digit) {\n    vector<bool> bits(digit);\n    for (int i = 0; i < digit; i++)\
    \ {\n        bits[i] = (num >> i) & 1U;\n    }\n    return bits;\n}\n\n/**\n *\
    \ @brief bits_to_num\n * @param bits a vector of bits\n * @return ll an integer\
    \ of bits\n * @details convert bits to an integer\n*/\nll bits_to_num(const vector<bool>\
    \ &bits) {\n    ll num = 0;\n    for (int i = 0; i < bits.size(); i++) {\n   \
    \     num += bits[i] << i;\n    }\n    return num;\n}\n}  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n/**\n * @brief num_to_bits\n *\
    \ @param num an integer to be converted to bits\n * @param digit the number of\
    \ bits\n * @return vector<bool> bits of num\n * @details convert an integer to\
    \ bits\n*/\nvector<bool> num_to_bits(const ll num, const size_t &digit) {\n  \
    \  vector<bool> bits(digit);\n    for (int i = 0; i < digit; i++) {\n        bits[i]\
    \ = (num >> i) & 1U;\n    }\n    return bits;\n}\n\n/**\n * @brief bits_to_num\n\
    \ * @param bits a vector of bits\n * @return ll an integer of bits\n * @details\
    \ convert bits to an integer\n*/\nll bits_to_num(const vector<bool> &bits) {\n\
    \    ll num = 0;\n    for (int i = 0; i < bits.size(); i++) {\n        num +=\
    \ bits[i] << i;\n    }\n    return num;\n}\n}  // namespace ugilib\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/bits/bit_util.hpp
  requiredBy:
  - ugilib/bits/bit_exhaustive_search.hpp
  timestamp: '2024-03-04 19:44:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/bits/bit_util.hpp
layout: document
redirect_from:
- /library/ugilib/bits/bit_util.hpp
- /library/ugilib/bits/bit_util.hpp.html
title: num_to_bits
---
