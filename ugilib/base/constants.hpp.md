---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(size_t\
    \ i = 0; i < n; i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n\
    #line 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants {\n    template<typename\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / 2;\n} // namespace\
    \ ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n"
  code: "#pragma once\n#include \"ugilib/base/definitions.hpp\"\n\nnamespace ugilib::constants\
    \ {\n    template<typename T>\n    inline constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n} // namespace ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/base/constants.hpp
  requiredBy: []
  timestamp: '2024-04-03 22:40:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/base/constants.hpp
layout: document
redirect_from:
- /library/ugilib/base/constants.hpp
- /library/ugilib/base/constants.hpp.html
title: ugilib/base/constants.hpp
---
