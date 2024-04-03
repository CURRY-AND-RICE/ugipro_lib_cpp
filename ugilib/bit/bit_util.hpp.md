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
  - icon: ':heavy_check_mark:'
    path: ugilib/bit/bit_exhaustive_search.hpp
    title: "\u30D3\u30C3\u30C8\u5168\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/tsp.hpp
    title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\u3092\u89E3\
      \u304FDP"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bit/bit_exhaustive_search.test.cpp
    title: tests/bit/bit_exhaustive_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/graph/tsp.test.cpp
    title: tests/graph/tsp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6570\u5024 -> \u30D3\u30C3\u30C8\u914D\u5217"
    links: []
  bundledCode: "#line 2 \"ugilib/bit/bit_util.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\n#define rep(i, n) for(int i = 0; i < (int)(n);\
    \ i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n#line\
    \ 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants {\n    template<typename\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / 2;\n} // namespace\
    \ ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"\
    ugilib/bit/bit_util.hpp\"\n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n\
    \     * @brief \u6570\u5024 -> \u30D3\u30C3\u30C8\u914D\u5217\n     * @param num\
    \ \u30D3\u30C3\u30C8\u914D\u5217\u306B\u3059\u308B\u305F\u3081\u306E\u6570\u5024\
    \n     * @param digit \u30D3\u30C3\u30C8\u6570\n     * @return vector<bool> \u5909\
    \u63DB\u3055\u308C\u305F\u30D3\u30C3\u30C8\u914D\u5217. 0\u756A\u76EE\u304C\u4E00\
    \u756A\u4E0B\u306E\u6841\n     * @details \u6570\u5024\u3092\u6307\u5B9A\u6841\
    \u306E\u30D3\u30C3\u30C8\u914D\u5217\u306B\u5909\u63DB\u3059\u308B\n    */\n \
    \   vector<bool> num_to_bits(const ll num, const size_t &digit) {\n        vector<bool>\
    \ bits(digit);\n        for (int i = 0; i < digit; i++) {\n            bits[i]\
    \ = (num >> i) & 1U;\n        }\n        return bits;\n    }\n\n    /**\n    \
    \ * @brief \u30D3\u30C3\u30C8\u914D\u5217 -> \u6570\u5024\n     * @param bits\
    \ \u6570\u5024\u306B\u3059\u308B\u305F\u3081\u306E\u30D3\u30C3\u30C8\u914D\u5217\
    . 0\u756A\u76EE\u304C\u4E00\u756A\u4E0B\u306E\u6841\n     * @return ll \u5909\u63DB\
    \u3055\u308C\u305F\u6570\u5024\n     * @details \u30D3\u30C3\u30C8\u914D\u5217\
    \u3092\u6570\u5024\u306B\u623B\u3059. num_to_bits\u306E\u9006\u5909\u63DB\n  \
    \  */\n    ll bits_to_num(const vector<bool> &bits) {\n        ll num = 0;\n \
    \       for (int i = 0; i < bits.size(); i++) {\n            num += bits[i] <<\
    \ i;\n        }\n        return num;\n    }\n}  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u6570\u5024\
    \ -> \u30D3\u30C3\u30C8\u914D\u5217\n     * @param num \u30D3\u30C3\u30C8\u914D\
    \u5217\u306B\u3059\u308B\u305F\u3081\u306E\u6570\u5024\n     * @param digit \u30D3\
    \u30C3\u30C8\u6570\n     * @return vector<bool> \u5909\u63DB\u3055\u308C\u305F\
    \u30D3\u30C3\u30C8\u914D\u5217. 0\u756A\u76EE\u304C\u4E00\u756A\u4E0B\u306E\u6841\
    \n     * @details \u6570\u5024\u3092\u6307\u5B9A\u6841\u306E\u30D3\u30C3\u30C8\
    \u914D\u5217\u306B\u5909\u63DB\u3059\u308B\n    */\n    vector<bool> num_to_bits(const\
    \ ll num, const size_t &digit) {\n        vector<bool> bits(digit);\n        for\
    \ (int i = 0; i < digit; i++) {\n            bits[i] = (num >> i) & 1U;\n    \
    \    }\n        return bits;\n    }\n\n    /**\n     * @brief \u30D3\u30C3\u30C8\
    \u914D\u5217 -> \u6570\u5024\n     * @param bits \u6570\u5024\u306B\u3059\u308B\
    \u305F\u3081\u306E\u30D3\u30C3\u30C8\u914D\u5217. 0\u756A\u76EE\u304C\u4E00\u756A\
    \u4E0B\u306E\u6841\n     * @return ll \u5909\u63DB\u3055\u308C\u305F\u6570\u5024\
    \n     * @details \u30D3\u30C3\u30C8\u914D\u5217\u3092\u6570\u5024\u306B\u623B\
    \u3059. num_to_bits\u306E\u9006\u5909\u63DB\n    */\n    ll bits_to_num(const\
    \ vector<bool> &bits) {\n        ll num = 0;\n        for (int i = 0; i < bits.size();\
    \ i++) {\n            num += bits[i] << i;\n        }\n        return num;\n \
    \   }\n}  // namespace ugilib\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/bit/bit_util.hpp
  requiredBy:
  - ugilib/bit/bit_exhaustive_search.hpp
  - ugilib/graph/tsp.hpp
  timestamp: '2024-04-03 22:40:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bit/bit_exhaustive_search.test.cpp
  - tests/graph/tsp.test.cpp
documentation_of: ugilib/bit/bit_util.hpp
layout: document
redirect_from:
- /library/ugilib/bit/bit_util.hpp
- /library/ugilib/bit/bit_util.hpp.html
title: "\u6570\u5024 -> \u30D3\u30C3\u30C8\u914D\u5217"
---
