---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
    links: []
  bundledCode: "#line 2 \"ugilib/math/pow.hpp\"\n#include <bits/stdc++.h>\n#line 2\
    \ \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\n#define rep(i, n) for(size_t i = 0; i <\
    \ n; i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n#line\
    \ 4 \"ugilib/math/pow.hpp\"\n\nnamespace ugilib {\n    /**\n     * @brief \u7E70\
    \u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n     * @param x \u57FA\u6570\n     * @param\
    \ n \u6307\u6570\n     * @param mod mod\n     * @return x^n % mod\n     * @note\
    \ O(log n)\n    */\n    template <typename T>\n    T fast_pow(T x, ll n, T mod\
    \ = ugilib::constants::INF<T>) {\n        assert(n >= 0);\n        T res = 1;\n\
    \        while (n) {\n            if (n & 1) res = res*x % mod;\n            x\
    \ = x*x % mod;\n            n >>= 1;\n        }\n        return res;\n    }\n\
    }  // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/definitions.hpp\"\
    \n\nnamespace ugilib {\n    /**\n     * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\
    \u6CD5\n     * @param x \u57FA\u6570\n     * @param n \u6307\u6570\n     * @param\
    \ mod mod\n     * @return x^n % mod\n     * @note O(log n)\n    */\n    template\
    \ <typename T>\n    T fast_pow(T x, ll n, T mod = ugilib::constants::INF<T>) {\n\
    \        assert(n >= 0);\n        T res = 1;\n        while (n) {\n          \
    \  if (n & 1) res = res*x % mod;\n            x = x*x % mod;\n            n >>=\
    \ 1;\n        }\n        return res;\n    }\n}  // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/math/pow.hpp
  requiredBy: []
  timestamp: '2024-03-31 15:45:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/math/pow.hpp
layout: document
redirect_from:
- /library/ugilib/math/pow.hpp
- /library/ugilib/math/pow.hpp.html
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
---
