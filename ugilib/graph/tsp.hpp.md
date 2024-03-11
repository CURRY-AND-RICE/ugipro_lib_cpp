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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ugilib/bits/bit_util.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\
    \n#include \"ugilib/bits/bit_util.hpp\"\n\nusing namespace std;\n\n/// cut begin\n\
    namespace ugilib {\n/**\n * @brief \u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\
    \u554F\u984C\u3092\u89E3\u304FDP\n * @param n \u90FD\u5E02\u6570\n * @param start\
    \ \u59CB\u70B9\n * @param graph \u30B0\u30E9\u30D5. vector<pair<int, weight_t>>\
    \ \u3067\u96A3\u63A5\u9802\u70B9\u3068\u30B3\u30B9\u30C8\u3092\u8868\u3059\n *\
    \ @param weight_inf \u7121\u9650\u5927\u306E\u5024. \u30D1\u30B9\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\u30C8\n * @return \u59CB\u70B9\
    \u304B\u3089\u5404\u9802\u70B9\u3092\u4E00\u5EA6\u3060\u3051\u901A\u3063\u3066\
    \u623B\u3063\u3066\u304F\u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n * @note O(2^n *\
    \ n^2)\n*/\ntemplate <typename weight_t>\nweight_t tsp_bitDP(int n, int start,\
    \ const vector<vector<pair<int, weight_t>>> &graph, const weight_t weight_inf\
    \ = ugilib::constants::INF<weight_t>) {\n    const int num_states = (1 << n);\n\
    \    // dp[\u3053\u308C\u307E\u3067\u306B\u53D6\u3063\u305F\u90FD\u5E02\u96C6\u5408\
    . [0, 2^n-1]][\u73FE\u5728\u5730. [0, n-1]]\n    vector<vector<weight_t>> dp(num_states,\
    \ vector<weight_t>(n, weight_inf));\n    dp[0][start] = 0;\n\n    // \u5168\u72B6\
    \u614B\u306B\u3064\u3044\u3066DP\u3059\u308B\n    for (int i = 0; i < num_states;\
    \ i++) {\n        // \u72B6\u614B\u3092\u30D3\u30C3\u30C8\u8868\u73FE\u3059\u308B\
    \n        auto bits = ugilib::num_to_bits(i, n);\n        // \u4ECA\u3069\u306E\
    \u90FD\u5E02\u306B\u3044\u308B\u304B\n        for (int j = 0; j < n; j++) {\n\
    \            if (dp[i][j] == weight_inf) continue;  // \u3053\u306E\u72B6\u614B\
    \u306B\u8FBF\u308A\u7740\u304B\u306A\u3044\u5834\u5408\n            // \u6B21\u3069\
    \u306E\u90FD\u5E02\u306B\u884C\u304F\u304B\n            for (const auto [node,\
    \ cost] : graph[j]) {\n                if (bits[node]) continue;  // \u8A2A\u554F\
    \u6E08\u307F\n                // \u8A2A\u554F\u3059\u308B\n                bits[node]\
    \ = true;\n                auto &dest = dp[ugilib::bits_to_num(bits)][node];\n\
    \                dest = min(dest, dp[i][j] + cost);\n                bits[node]\
    \ = false;\n            }\n        }\n    }\n\n    return dp[num_states-1][start];\
    \  // \u5168\u72B6\u614B\u8A2A\u554F\u5F8C\u306Bstart\u306B\u623B\u3063\u3066\u6765\
    \u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n}\n}  // namespace ugilib\n/// cut end\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/graph/tsp.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
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
