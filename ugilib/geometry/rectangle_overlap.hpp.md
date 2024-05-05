---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u3064\u306E\u9577\u65B9\u5F62\u306E\u91CD\u306A\u308A\u3092\
      \u5224\u5B9A"
    links: []
  bundledCode: "#line 2 \"ugilib/geometry/rectangle_overlap.hpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(size_t i\
    \ = 0; i < n; i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n\
    #line 4 \"ugilib/geometry/rectangle_overlap.hpp\"\n\nnamespace ugilib {\n    /**\n\
    \     * @brief \u4E8C\u3064\u306E\u9577\u65B9\u5F62\u306E\u91CD\u306A\u308A\u3092\
    \u5224\u5B9A\n     * @param a \u9577\u65B9\u5F621\u306E\u5EA7\u6A19 (ymin, xmin,\
    \ ymax, xmax)\n     * @param b \u9577\u65B9\u5F622\u306E\u5EA7\u6A19 (ymin, xmin,\
    \ ymax, xmax)\n     * @return \u91CD\u306A\u3063\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B. \u70B9\u3067\u63A5\u3057\u3066\u3044\u308B\u5834\u5408\u3082true\n\
    \     * @details 4\u3064\u306E\u5EA7\u6A19\u306F\u9589\u533A\u9593\u3067\u8868\
    \u3059. \u3064\u307E\u308A\uFF0C(ymin, xmin)\u3082(ymax, xmax)\u3082\u9577\u65B9\
    \u5F62\u306B\u542B\u307E\u308C\u308B\n    */\n    template <typename T>\n    bool\
    \ is_overlapping(const std::array<T, 4> &a, const std::array<T, 4> &b) {\n   \
    \     auto [ymin1, xmin1, ymax1, xmax1] = a;\n        auto [ymin2, xmin2, ymax2,\
    \ xmax2] = b;\n        return (xmin1 <= xmax2 && xmax1 >= xmin2 && ymin1 <= ymax2\
    \ && ymax1 >= ymin2);\n    }\n} // namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/definitions.hpp\"\
    \n\nnamespace ugilib {\n    /**\n     * @brief \u4E8C\u3064\u306E\u9577\u65B9\u5F62\
    \u306E\u91CD\u306A\u308A\u3092\u5224\u5B9A\n     * @param a \u9577\u65B9\u5F62\
    1\u306E\u5EA7\u6A19 (ymin, xmin, ymax, xmax)\n     * @param b \u9577\u65B9\u5F62\
    2\u306E\u5EA7\u6A19 (ymin, xmin, ymax, xmax)\n     * @return \u91CD\u306A\u3063\
    \u3066\u3044\u308B\u304B\u3069\u3046\u304B. \u70B9\u3067\u63A5\u3057\u3066\u3044\
    \u308B\u5834\u5408\u3082true\n     * @details 4\u3064\u306E\u5EA7\u6A19\u306F\u9589\
    \u533A\u9593\u3067\u8868\u3059. \u3064\u307E\u308A\uFF0C(ymin, xmin)\u3082(ymax,\
    \ xmax)\u3082\u9577\u65B9\u5F62\u306B\u542B\u307E\u308C\u308B\n    */\n    template\
    \ <typename T>\n    bool is_overlapping(const std::array<T, 4> &a, const std::array<T,\
    \ 4> &b) {\n        auto [ymin1, xmin1, ymax1, xmax1] = a;\n        auto [ymin2,\
    \ xmin2, ymax2, xmax2] = b;\n        return (xmin1 <= xmax2 && xmax1 >= xmin2\
    \ && ymin1 <= ymax2 && ymax1 >= ymin2);\n    }\n} // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/geometry/rectangle_overlap.hpp
  requiredBy: []
  timestamp: '2024-03-31 15:45:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/geometry/rectangle_overlap.hpp
layout: document
redirect_from:
- /library/ugilib/geometry/rectangle_overlap.hpp
- /library/ugilib/geometry/rectangle_overlap.hpp.html
title: "\u4E8C\u3064\u306E\u9577\u65B9\u5F62\u306E\u91CD\u306A\u308A\u3092\u5224\u5B9A"
---