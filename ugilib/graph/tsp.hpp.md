---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\u3092\
      \u89E3\u304FDP"
    links: []
  bundledCode: "#line 2 \"ugilib/graph/tsp.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\n#define rep(i, n) for(size_t i = 0; i <\
    \ n; i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n#line\
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
    \ i;\n        }\n        return num;\n    }\n}  // namespace ugilib\n#line 5 \"\
    ugilib/graph/tsp.hpp\"\n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n\
    \     * @brief \u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\u3092\
    \u89E3\u304FDP\n     * @param n \u90FD\u5E02\u6570\n     * @param start \u59CB\
    \u70B9\n     * @param graph \u30B0\u30E9\u30D5. vector<pair<int, weight_t>> \u3067\
    \u96A3\u63A5\u9802\u70B9\u3068\u30B3\u30B9\u30C8\u3092\u8868\u3059\n     * @param\
    \ weight_inf \u7121\u9650\u5927\u306E\u5024. \u30D1\u30B9\u304C\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\u30C8\n     * @return \u59CB\u70B9\u304B\
    \u3089\u5404\u9802\u70B9\u3092\u4E00\u5EA6\u3060\u3051\u901A\u3063\u3066\u623B\
    \u3063\u3066\u304F\u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n     * @note O(2^n * n^2)\n\
    \    */\n    template <typename weight_t>\n    weight_t tsp_bitDP(int n, int start,\
    \ const vector<vector<pair<int, weight_t>>> &graph, const weight_t weight_inf\
    \ = ugilib::constants::INF<weight_t>) {\n        const int num_states = (1 <<\
    \ n);\n        // dp[\u3053\u308C\u307E\u3067\u306B\u53D6\u3063\u305F\u90FD\u5E02\
    \u96C6\u5408. [0, 2^n-1]][\u73FE\u5728\u5730. [0, n-1]]\n        vector<vector<weight_t>>\
    \ dp(num_states, vector<weight_t>(n, weight_inf));\n        dp[0][start] = 0;\n\
    \n        // \u5168\u72B6\u614B\u306B\u3064\u3044\u3066DP\u3059\u308B\n      \
    \  for (int i = 0; i < num_states; i++) {\n            // \u72B6\u614B\u3092\u30D3\
    \u30C3\u30C8\u8868\u73FE\u3059\u308B\n            auto bits = ugilib::num_to_bits(i,\
    \ n);\n            // \u4ECA\u3069\u306E\u90FD\u5E02\u306B\u3044\u308B\u304B\n\
    \            for (int j = 0; j < n; j++) {\n                if (dp[i][j] == weight_inf)\
    \ continue;  // \u3053\u306E\u72B6\u614B\u306B\u8FBF\u308A\u7740\u304B\u306A\u3044\
    \u5834\u5408\n                // \u6B21\u3069\u306E\u90FD\u5E02\u306B\u884C\u304F\
    \u304B\n                for (const auto [node, cost] : graph[j]) {\n         \
    \           if (bits[node]) continue;  // \u8A2A\u554F\u6E08\u307F\n         \
    \           // \u8A2A\u554F\u3059\u308B\n                    bits[node] = true;\n\
    \                    auto &dest = dp[ugilib::bits_to_num(bits)][node];\n     \
    \               dest = min(dest, dp[i][j] + cost);\n                    bits[node]\
    \ = false;\n                }\n            }\n        }\n\n        return dp[num_states-1][start];\
    \  // \u5168\u72B6\u614B\u8A2A\u554F\u5F8C\u306Bstart\u306B\u623B\u3063\u3066\u6765\
    \u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n    }\n}  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\
    \n#include \"ugilib/bit/bit_util.hpp\"\n\nusing namespace std;\n\nnamespace ugilib\
    \ {\n    /**\n     * @brief \u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\
    \u984C\u3092\u89E3\u304FDP\n     * @param n \u90FD\u5E02\u6570\n     * @param\
    \ start \u59CB\u70B9\n     * @param graph \u30B0\u30E9\u30D5. vector<pair<int,\
    \ weight_t>> \u3067\u96A3\u63A5\u9802\u70B9\u3068\u30B3\u30B9\u30C8\u3092\u8868\
    \u3059\n     * @param weight_inf \u7121\u9650\u5927\u306E\u5024. \u30D1\u30B9\u304C\
    \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\u30C8\n     * @return\
    \ \u59CB\u70B9\u304B\u3089\u5404\u9802\u70B9\u3092\u4E00\u5EA6\u3060\u3051\u901A\
    \u3063\u3066\u623B\u3063\u3066\u304F\u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n   \
    \  * @note O(2^n * n^2)\n    */\n    template <typename weight_t>\n    weight_t\
    \ tsp_bitDP(int n, int start, const vector<vector<pair<int, weight_t>>> &graph,\
    \ const weight_t weight_inf = ugilib::constants::INF<weight_t>) {\n        const\
    \ int num_states = (1 << n);\n        // dp[\u3053\u308C\u307E\u3067\u306B\u53D6\
    \u3063\u305F\u90FD\u5E02\u96C6\u5408. [0, 2^n-1]][\u73FE\u5728\u5730. [0, n-1]]\n\
    \        vector<vector<weight_t>> dp(num_states, vector<weight_t>(n, weight_inf));\n\
    \        dp[0][start] = 0;\n\n        // \u5168\u72B6\u614B\u306B\u3064\u3044\u3066\
    DP\u3059\u308B\n        for (int i = 0; i < num_states; i++) {\n            //\
    \ \u72B6\u614B\u3092\u30D3\u30C3\u30C8\u8868\u73FE\u3059\u308B\n            auto\
    \ bits = ugilib::num_to_bits(i, n);\n            // \u4ECA\u3069\u306E\u90FD\u5E02\
    \u306B\u3044\u308B\u304B\n            for (int j = 0; j < n; j++) {\n        \
    \        if (dp[i][j] == weight_inf) continue;  // \u3053\u306E\u72B6\u614B\u306B\
    \u8FBF\u308A\u7740\u304B\u306A\u3044\u5834\u5408\n                // \u6B21\u3069\
    \u306E\u90FD\u5E02\u306B\u884C\u304F\u304B\n                for (const auto [node,\
    \ cost] : graph[j]) {\n                    if (bits[node]) continue;  // \u8A2A\
    \u554F\u6E08\u307F\n                    // \u8A2A\u554F\u3059\u308B\n        \
    \            bits[node] = true;\n                    auto &dest = dp[ugilib::bits_to_num(bits)][node];\n\
    \                    dest = min(dest, dp[i][j] + cost);\n                    bits[node]\
    \ = false;\n                }\n            }\n        }\n\n        return dp[num_states-1][start];\
    \  // \u5168\u72B6\u614B\u8A2A\u554F\u5F8C\u306Bstart\u306B\u623B\u3063\u3066\u6765\
    \u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n    }\n}  // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/graph/tsp.hpp
  requiredBy: []
  timestamp: '2024-05-05 21:37:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/graph/tsp.hpp
layout: document
redirect_from:
- /library/ugilib/graph/tsp.hpp
- /library/ugilib/graph/tsp.hpp.html
title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\u3092\u89E3\u304F\
  DP"
---
