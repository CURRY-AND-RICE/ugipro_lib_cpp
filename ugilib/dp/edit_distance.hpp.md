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
    path: tests/dp/edit_distance.test.cpp
    title: tests/dp/edit_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7DE8\u96C6\u8DDD\u96E2"
    links: []
  bundledCode: "#line 2 \"ugilib/dp/edit_distance.hpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(int i =\
    \ 0; i < (int)(n); i++)  // rep macro\n#define all(v) begin(v), end(v)  // all\
    \ iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants\
    \ {\n    template<typename T>\n    inline constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n} // namespace ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n\
    #line 4 \"ugilib/dp/edit_distance.hpp\"\n\nusing namespace std;\n\nnamespace ugilib\
    \ {\n    /**\n     * @brief \u7DE8\u96C6\u8DDD\u96E2\n     * @tparam T vector\u306E\
    \u8981\u7D20\u306E\u578B. string\u3060\u3063\u305F\u3089vector<char>\u3067\u6E21\
    \u3059\n     * @param v1 vector1\n     * @param v2 vector2\n     * @return vector<vector<ll>>\
    \ dp[i][j]: v1\u306Ei\u6587\u5B57\u76EE\u307E\u3067\u3068v2\u306Ej\u6587\u5B57\
    \u76EE\u307E\u3067\u306E\u7DE8\u96C6\u8DDD\u96E2\n     * @note O(nm). n = v1.size(),\
    \ m = v2.size()\n     * @details\n     * auto dp = edit_distance(v1, v2);\n  \
    \   * cout << dp[v1.size()][v2.size()] << endl;\n     * cout << dp.back().back()\
    \ << endl;\n    */\n    template <typename T>\n    vector<vector<ll>> edit_distance(const\
    \ vector<T>& v1, const vector<T>& v2) {\n        int n = v1.size();\n        int\
    \ m = v2.size();\n        // dp[i][j]: v1\u306Ei\u6587\u5B57\u76EE\u307E\u3067\
    \u3068v2\u306Ej\u6587\u5B57\u76EE\u307E\u3067\u306E\u7DE8\u96C6\u8DDD\u96E2\n\
    \        vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));\n\n        // \u7A7A\
    \u6587\u5B57\u5217\u3068\u306E\u7DE8\u96C6\u8DDD\u96E2\n        for (int i = 0;\
    \ i <= n; i++) dp[i][0] = i;\n        for (int j = 0; j <= m; j++) dp[0][j] =\
    \ j;\n\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j <\
    \ m; j++) {\n                dp[i+1][j+1] = min(dp[i][j+1] + 1, dp[i+1][j] + 1);\
    \  // v1 or v2\u3069\u3061\u3089\u304B1\u6587\u5B57\u8FFD\u52A0\n            \
    \    if (v1[i] == v2[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);  // v1 and\
    \ v2\u4E21\u65B9\u304B\u30891\u6587\u5B57\u8FFD\u52A0\n                else dp[i+1][j+1]\
    \ = min(dp[i+1][j+1], dp[i][j] + 1);  // v1 and v2\u4E21\u65B9\u304B\u30891\u6587\
    \u5B57\u8FFD\u52A0\u3057, \u7247\u65B9\u3092\u5909\u66F4\u3059\u308B\n       \
    \     }\n        }\n\n        return dp;\n    }\n}  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u7DE8\u96C6\
    \u8DDD\u96E2\n     * @tparam T vector\u306E\u8981\u7D20\u306E\u578B. string\u3060\
    \u3063\u305F\u3089vector<char>\u3067\u6E21\u3059\n     * @param v1 vector1\n \
    \    * @param v2 vector2\n     * @return vector<vector<ll>> dp[i][j]: v1\u306E\
    i\u6587\u5B57\u76EE\u307E\u3067\u3068v2\u306Ej\u6587\u5B57\u76EE\u307E\u3067\u306E\
    \u7DE8\u96C6\u8DDD\u96E2\n     * @note O(nm). n = v1.size(), m = v2.size()\n \
    \    * @details\n     * auto dp = edit_distance(v1, v2);\n     * cout << dp[v1.size()][v2.size()]\
    \ << endl;\n     * cout << dp.back().back() << endl;\n    */\n    template <typename\
    \ T>\n    vector<vector<ll>> edit_distance(const vector<T>& v1, const vector<T>&\
    \ v2) {\n        int n = v1.size();\n        int m = v2.size();\n        // dp[i][j]:\
    \ v1\u306Ei\u6587\u5B57\u76EE\u307E\u3067\u3068v2\u306Ej\u6587\u5B57\u76EE\u307E\
    \u3067\u306E\u7DE8\u96C6\u8DDD\u96E2\n        vector<vector<ll>> dp(n+1, vector<ll>(m+1,\
    \ INF));\n\n        // \u7A7A\u6587\u5B57\u5217\u3068\u306E\u7DE8\u96C6\u8DDD\u96E2\
    \n        for (int i = 0; i <= n; i++) dp[i][0] = i;\n        for (int j = 0;\
    \ j <= m; j++) dp[0][j] = j;\n\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                dp[i+1][j+1] = min(dp[i][j+1]\
    \ + 1, dp[i+1][j] + 1);  // v1 or v2\u3069\u3061\u3089\u304B1\u6587\u5B57\u8FFD\
    \u52A0\n                if (v1[i] == v2[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);\
    \  // v1 and v2\u4E21\u65B9\u304B\u30891\u6587\u5B57\u8FFD\u52A0\n           \
    \     else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 1);  // v1 and v2\u4E21\
    \u65B9\u304B\u30891\u6587\u5B57\u8FFD\u52A0\u3057, \u7247\u65B9\u3092\u5909\u66F4\
    \u3059\u308B\n            }\n        }\n\n        return dp;\n    }\n}  // namespace\
    \ ugilib\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/dp/edit_distance.hpp
  requiredBy: []
  timestamp: '2024-04-03 22:40:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dp/edit_distance.test.cpp
documentation_of: ugilib/dp/edit_distance.hpp
layout: document
redirect_from:
- /library/ugilib/dp/edit_distance.hpp
- /library/ugilib/dp/edit_distance.hpp.html
title: "\u7DE8\u96C6\u8DDD\u96E2"
---
