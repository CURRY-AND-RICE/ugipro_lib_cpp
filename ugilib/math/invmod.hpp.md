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
    path: ugilib/math/combinatorics.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B\u8A08\u7B97\u306E\u95A2\u6570\u306E\u5B9A\
      \u7FA9. perm(), comb(), fact()."
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u9006\u5143\u8A08\u7B97\u306E\u95A2\u6570\u306E\u5B9A\u7FA9\
      . invmod()."
    links: []
  bundledCode: "#line 2 \"ugilib/math/invmod.hpp\"\n\n/**\n * @file invmod.hpp\n *\
    \ @brief \u9006\u5143\u8A08\u7B97\u306E\u95A2\u6570\u306E\u5B9A\u7FA9. invmod().\n\
    */\n\n#include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 11 \"ugilib/math/invmod.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u62E1\u5F35\
    \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n     * @tparam T\
    \ \u6574\u6570\u578B\n     * @param a a\n     * @param b b\n     * @param x x\n\
    \     * @param y y\n     * @return T gcd(a, b)\n     * @note O(log^2(max(a, b)))\n\
    \     * @note ax + by = gcd(a, b)\u3092\u6E80\u305F\u3059x, y\u3092\u6C42\u3081\
    \u308B\n    */\n    template <typename T>\n    T extended_gcd(T a, T b, T& x,\
    \ T& y) {\n        if (b == 0) {\n            x = 1;\n            y = 0;\n   \
    \         return a;\n        }\n        T gcd = extended_gcd(b, a % b, x, y);\n\
    \        T tmp = x;\n        x = y;\n        y = tmp - a / b * y;\n        return\
    \ gcd;\n    }\n\n    /**\n     * @brief a\u306Emod\u306B\u304A\u3051\u308B\u9006\
    \u5143\u3092\u6C42\u3081\u308B\n     * @tparam T \u6574\u6570\u578B\n     * @param\
    \ a a\n     * @param mod mod\n     * @return T a\u306Emod\u306B\u304A\u3051\u308B\
    \u9006\u5143\n     * @note O(log^2(mod))\n     * @note mod\u304C\u7D20\u6570\u3067\
    \u3042\u308A\u3001\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\u304C\
    \u524D\u63D0\n    */\n    template <typename T>\n    T invmod(T a, T mod) {\n\
    \        T x, y;\n        T gcd = extended_gcd(a, mod, x, y);\n        assert(gcd\
    \ == 1);\n        return (x % mod + mod) % mod;\n    }\n}\n"
  code: "#pragma once\n\n/**\n * @file invmod.hpp\n * @brief \u9006\u5143\u8A08\u7B97\
    \u306E\u95A2\u6570\u306E\u5B9A\u7FA9. invmod().\n*/\n\n#include <bits/stdc++.h>\n\
    #include \"ugilib/base/definitions.hpp\"\n#include \"ugilib/base/constants.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u62E1\u5F35\
    \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n     * @tparam T\
    \ \u6574\u6570\u578B\n     * @param a a\n     * @param b b\n     * @param x x\n\
    \     * @param y y\n     * @return T gcd(a, b)\n     * @note O(log^2(max(a, b)))\n\
    \     * @note ax + by = gcd(a, b)\u3092\u6E80\u305F\u3059x, y\u3092\u6C42\u3081\
    \u308B\n    */\n    template <typename T>\n    T extended_gcd(T a, T b, T& x,\
    \ T& y) {\n        if (b == 0) {\n            x = 1;\n            y = 0;\n   \
    \         return a;\n        }\n        T gcd = extended_gcd(b, a % b, x, y);\n\
    \        T tmp = x;\n        x = y;\n        y = tmp - a / b * y;\n        return\
    \ gcd;\n    }\n\n    /**\n     * @brief a\u306Emod\u306B\u304A\u3051\u308B\u9006\
    \u5143\u3092\u6C42\u3081\u308B\n     * @tparam T \u6574\u6570\u578B\n     * @param\
    \ a a\n     * @param mod mod\n     * @return T a\u306Emod\u306B\u304A\u3051\u308B\
    \u9006\u5143\n     * @note O(log^2(mod))\n     * @note mod\u304C\u7D20\u6570\u3067\
    \u3042\u308A\u3001\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\u304C\
    \u524D\u63D0\n    */\n    template <typename T>\n    T invmod(T a, T mod) {\n\
    \        T x, y;\n        T gcd = extended_gcd(a, mod, x, y);\n        assert(gcd\
    \ == 1);\n        return (x % mod + mod) % mod;\n    }\n}\n"
  dependsOn:
  - ugilib/base/definitions.hpp
  - ugilib/base/constants.hpp
  isVerificationFile: false
  path: ugilib/math/invmod.hpp
  requiredBy:
  - ugilib/math/combinatorics.hpp
  timestamp: '2024-04-26 23:52:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/math/invmod.hpp
layout: document
redirect_from:
- /library/ugilib/math/invmod.hpp
- /library/ugilib/math/invmod.hpp.html
title: "\u9006\u5143\u8A08\u7B97\u306E\u95A2\u6570\u306E\u5B9A\u7FA9. invmod()."
---
