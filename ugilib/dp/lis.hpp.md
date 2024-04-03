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
    path: tests/dp/lis.test.cpp
    title: tests/dp/lis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
    links: []
  bundledCode: "#line 2 \"ugilib/dp/lis.hpp\"\n#include <bits/stdc++.h>\n#line 2 \"\
    ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing ld = long double;\n#define rep(i, n) for(size_t i = 0; i < n; i++)\
    \  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n#line 3 \"\
    ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants {\n    template<typename\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / 2;\n} // namespace\
    \ ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"\
    ugilib/dp/lis.hpp\"\nusing namespace std;\n\nnamespace ugilib {\n    /**\n   \
    \  * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\n     * @tparam T vector\u306E\
    \u8981\u7D20\u306E\u578B\n     * @param A vector\n     * @param inf \u7121\u9650\
    \u5927\n     * @return pair<size_t, vector<T>> (\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\u306E\u9577\u3055, \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217(\u4E00\
    \u610F\u3067\u306F\u306A\u3044))\n     * @note O(n log n). n = A.size()\n    */\n\
    \    template <typename T>\n    pair<size_t, vector<T>> longest_increasing_subsequence(const\
    \ vector<T> &A, const T inf = ugilib::constants::INF<T>) {\n        static_assert(is_signed<T>::value,\
    \ \"T must be signed type.\");  // T\u306F\u7B26\u53F7\u4ED8\u304D\u578B\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n        // dp[i]: \u9577\u3055\u304C\
    i\u3067\u3042\u308B\u3088\u3046\u306A\u5897\u52A0\u90E8\u5206\u5217\u306E\u6700\
    \u5F8C\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024\n        vector<T> dp(A.size()\
    \ + 1, inf);  // 1-indexed\n        vector<size_t> indices(A.size());  // indices[i]:\
    \ A[i]\u304Cdp\u306E\u3069\u3053\u306B\u5165\u308B\u304B\n        dp[0] = -1;\n\
    \        for (size_t i = 0; i < A.size(); i++) {\n            size_t idx = lower_bound(dp.begin(),\
    \ dp.end(), A[i]) - dp.begin();\n            dp[idx] = A[i];\n            indices[i]\
    \ = idx;\n        }\n\n        // inf\u306E\u624B\u524D\u307E\u3067\u90E8\u5206\
    \u5897\u52A0\u5217\u306E\u6700\u7D42\u8981\u7D20\u304C\u5165\u3063\u3066\u3044\
    \u308B\n        const size_t lis_length = find(dp.begin(), dp.end(), inf) - dp.begin()\
    \ - 1;\n        // \u90E8\u5206\u5897\u52A0\u5217\u306E\u5FA9\u5143\n        vector<T>\
    \ lis(lis_length);\n        size_t target = lis_length;\n        for (int i =\
    \ A.size() - 1; i >= 0; i--) if (indices[i] == target) lis[--target] = A[i];\n\
    \n        return {lis_length, lis};\n    }\n}  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\
    \nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u6700\u9577\
    \u5897\u52A0\u90E8\u5206\u5217\n     * @tparam T vector\u306E\u8981\u7D20\u306E\
    \u578B\n     * @param A vector\n     * @param inf \u7121\u9650\u5927\n     * @return\
    \ pair<size_t, vector<T>> (\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\
    \u3055, \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217(\u4E00\u610F\u3067\u306F\u306A\
    \u3044))\n     * @note O(n log n). n = A.size()\n    */\n    template <typename\
    \ T>\n    pair<size_t, vector<T>> longest_increasing_subsequence(const vector<T>\
    \ &A, const T inf = ugilib::constants::INF<T>) {\n        static_assert(is_signed<T>::value,\
    \ \"T must be signed type.\");  // T\u306F\u7B26\u53F7\u4ED8\u304D\u578B\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n        // dp[i]: \u9577\u3055\u304C\
    i\u3067\u3042\u308B\u3088\u3046\u306A\u5897\u52A0\u90E8\u5206\u5217\u306E\u6700\
    \u5F8C\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024\n        vector<T> dp(A.size()\
    \ + 1, inf);  // 1-indexed\n        vector<size_t> indices(A.size());  // indices[i]:\
    \ A[i]\u304Cdp\u306E\u3069\u3053\u306B\u5165\u308B\u304B\n        dp[0] = -1;\n\
    \        for (size_t i = 0; i < A.size(); i++) {\n            size_t idx = lower_bound(dp.begin(),\
    \ dp.end(), A[i]) - dp.begin();\n            dp[idx] = A[i];\n            indices[i]\
    \ = idx;\n        }\n\n        // inf\u306E\u624B\u524D\u307E\u3067\u90E8\u5206\
    \u5897\u52A0\u5217\u306E\u6700\u7D42\u8981\u7D20\u304C\u5165\u3063\u3066\u3044\
    \u308B\n        const size_t lis_length = find(dp.begin(), dp.end(), inf) - dp.begin()\
    \ - 1;\n        // \u90E8\u5206\u5897\u52A0\u5217\u306E\u5FA9\u5143\n        vector<T>\
    \ lis(lis_length);\n        size_t target = lis_length;\n        for (int i =\
    \ A.size() - 1; i >= 0; i--) if (indices[i] == target) lis[--target] = A[i];\n\
    \n        return {lis_length, lis};\n    }\n}  // namespace ugilib\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/dp/lis.hpp
  requiredBy: []
  timestamp: '2024-04-03 22:46:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dp/lis.test.cpp
documentation_of: ugilib/dp/lis.hpp
layout: document
redirect_from:
- /library/ugilib/dp/lis.hpp
- /library/ugilib/dp/lis.hpp.html
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
---
