---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5EA7\u6A19\u5727\u7E2E\u306E\u5B9F\u88C5"
    links: []
  bundledCode: "#line 2 \"ugilib/std_util/coord_compress.hpp\"\n\n/**\n * @file coord_compress.hpp\n\
    \ * @brief \u5EA7\u6A19\u5727\u7E2E\u306E\u5B9F\u88C5\n*/\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u5EA7\u6A19\
    \u5727\u7E2E\n     * @tparam T \u5EA7\u6A19\u5727\u7E2E\u3057\u305F\u3044\u578B\
    \n     * @param v \u5727\u7E2E\u3057\u305F\u3044\u914D\u5217\n     * @param descending\
    \ true\u306E\u5834\u5408\u3001\u964D\u9806\u306B\u5727\u7E2E\u3059\u308B\n   \
    \  * @return unordered_map<T, ll> \u5143\u306E\u5024\u304B\u3089\u5727\u7E2E\u3057\
    \u305F\u5024\u3078\u306E\u30DE\u30C3\u30D7\n     * @note \u5727\u7E2E\u5F8C\u306E\
    \u5024\u306F0-indexed\n     * @note O(NlogN)\n    */\n    template <typename T>\n\
    \    unordered_map<T, int> compress(vector<T>& v, bool descending = false) {\n\
    \        // \u30E6\u30CB\u30FC\u30AF\u306B\u3059\u308B\n        vector<T> sorted_unique_v(v.begin(),\
    \ v.end());  // \u30B3\u30D4\u30FC\n        auto end_unique = unique(sorted_unique_v.begin(),\
    \ sorted_unique_v.end());  // \u30E6\u30CB\u30FC\u30AF\u8981\u7D20\u3092\u524D\
    \u306B\u8A70\u3081\u308B\n        sorted_unique_v.erase(end_unique, sorted_unique_v.end());\
    \  // \u91CD\u8907\u8981\u7D20\u3092\u524A\u9664\n        // \u30BD\u30FC\u30C8\
    \n        if (descending) {\n            sort(sorted_unique_v.rbegin(), sorted_unique_v.rend());\n\
    \        } else {\n            sort(sorted_unique_v.begin(), sorted_unique_v.end());\n\
    \        }\n        // \u5727\u7E2E\n        unordered_map<T, int> compressed;\n\
    \        rep(i, sorted_unique_v.size()) {\n            compressed[sorted_unique_v[i]]\
    \ = i;\n        }\n        return compressed;\n    }\n} // namespace ugilib\n"
  code: "#pragma once\n\n/**\n * @file coord_compress.hpp\n * @brief \u5EA7\u6A19\u5727\
    \u7E2E\u306E\u5B9F\u88C5\n*/\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nnamespace ugilib {\n    /**\n     * @brief \u5EA7\u6A19\u5727\u7E2E\n     *\
    \ @tparam T \u5EA7\u6A19\u5727\u7E2E\u3057\u305F\u3044\u578B\n     * @param v\
    \ \u5727\u7E2E\u3057\u305F\u3044\u914D\u5217\n     * @param descending true\u306E\
    \u5834\u5408\u3001\u964D\u9806\u306B\u5727\u7E2E\u3059\u308B\n     * @return unordered_map<T,\
    \ ll> \u5143\u306E\u5024\u304B\u3089\u5727\u7E2E\u3057\u305F\u5024\u3078\u306E\
    \u30DE\u30C3\u30D7\n     * @note \u5727\u7E2E\u5F8C\u306E\u5024\u306F0-indexed\n\
    \     * @note O(NlogN)\n    */\n    template <typename T>\n    unordered_map<T,\
    \ int> compress(vector<T>& v, bool descending = false) {\n        // \u30E6\u30CB\
    \u30FC\u30AF\u306B\u3059\u308B\n        vector<T> sorted_unique_v(v.begin(), v.end());\
    \  // \u30B3\u30D4\u30FC\n        auto end_unique = unique(sorted_unique_v.begin(),\
    \ sorted_unique_v.end());  // \u30E6\u30CB\u30FC\u30AF\u8981\u7D20\u3092\u524D\
    \u306B\u8A70\u3081\u308B\n        sorted_unique_v.erase(end_unique, sorted_unique_v.end());\
    \  // \u91CD\u8907\u8981\u7D20\u3092\u524A\u9664\n        // \u30BD\u30FC\u30C8\
    \n        if (descending) {\n            sort(sorted_unique_v.rbegin(), sorted_unique_v.rend());\n\
    \        } else {\n            sort(sorted_unique_v.begin(), sorted_unique_v.end());\n\
    \        }\n        // \u5727\u7E2E\n        unordered_map<T, int> compressed;\n\
    \        rep(i, sorted_unique_v.size()) {\n            compressed[sorted_unique_v[i]]\
    \ = i;\n        }\n        return compressed;\n    }\n} // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/std_util/coord_compress.hpp
  requiredBy: []
  timestamp: '2024-04-28 18:37:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/std_util/coord_compress.hpp
layout: document
redirect_from:
- /library/ugilib/std_util/coord_compress.hpp
- /library/ugilib/std_util/coord_compress.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E\u306E\u5B9F\u88C5"
---
