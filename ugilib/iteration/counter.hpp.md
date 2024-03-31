---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u7BC4\u56F2\u306B\u542B\u307E\
      \u308C\u308B\u8981\u7D20\u306E\u51FA\u73FE\u56DE\u6570\u3092\u30AB\u30A6\u30F3\
      \u30C8\u3059\u308B"
    links: []
  bundledCode: "#line 2 \"ugilib/iteration/counter.hpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(int i =\
    \ 0; i < (int)(n); i++)  // rep macro\n#define all(v) begin(v), end(v)  // all\
    \ iterator\n#line 4 \"ugilib/iteration/counter.hpp\"\n\nusing namespace std;\n\
    \nnamespace ugilib {\n    /**\n     * @brief \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\
    \u7BC4\u56F2\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u51FA\u73FE\u56DE\
    \u6570\u3092\u30AB\u30A6\u30F3\u30C8\u3059\u308B\n     * @tparam Iterator \u30A4\
    \u30C6\u30EC\u30FC\u30BF\u306E\u578B\n     * @param first \u30A4\u30C6\u30EC\u30FC\
    \u30BF\u306E\u5148\u982D\n     * @param last \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\
    \u7D42\u7AEF\n     * @return unordered_map<\u8981\u7D20\u306E\u578B, \u51FA\u73FE\
    \u56DE\u6570> \u306E\u5F62\u5F0F\u3067\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\
    \n    */\n    template <typename Iterator, typename _Hash = std::hash<typename\
    \ std::iterator_traits<Iterator>::value_type>>\n    unordered_map<typename std::iterator_traits<Iterator>::value_type,\
    \ ll, _Hash> count_elements_as_unordered(Iterator first, Iterator last) {\n  \
    \      unordered_map<typename std::iterator_traits<Iterator>::value_type, ll,\
    \ _Hash> counter;\n        for (auto it = first; it != last; ++it) {\n       \
    \     counter[*it]++;\n        }\n        return counter;\n    }\n\n    /**\n\
    \     * @brief \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u7BC4\u56F2\u306B\u542B\u307E\
    \u308C\u308B\u8981\u7D20\u306E\u51FA\u73FE\u56DE\u6570\u3092\u30AB\u30A6\u30F3\
    \u30C8\u3059\u308B\n     * @tparam Iterator \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\
    \u578B\n     * @param first \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u5148\u982D\n\
    \     * @param last \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u7D42\u7AEF\n     * @return\
    \ map<\u8981\u7D20\u306E\u578B, \u51FA\u73FE\u56DE\u6570> \u306E\u5F62\u5F0F\u3067\
    \u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n    */\n    template <typename Iterator,\
    \ typename _Compare = less<typename std::iterator_traits<Iterator>::value_type>>\n\
    \    map<typename std::iterator_traits<Iterator>::value_type, ll, _Compare> count_elements_as_ordered(Iterator\
    \ first, Iterator last) {\n        map<typename std::iterator_traits<Iterator>::value_type,\
    \ ll, _Compare> counter;\n        for (auto it = first; it != last; ++it) {\n\
    \            counter[*it]++;\n        }\n        return counter;\n    }\n} //\
    \ namespace ugilib\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"ugilib/base/definitions.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u30A4\u30C6\
    \u30EC\u30FC\u30BF\u306E\u7BC4\u56F2\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\
    \u306E\u51FA\u73FE\u56DE\u6570\u3092\u30AB\u30A6\u30F3\u30C8\u3059\u308B\n   \
    \  * @tparam Iterator \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\n     * @param\
    \ first \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u5148\u982D\n     * @param last \u30A4\
    \u30C6\u30EC\u30FC\u30BF\u306E\u7D42\u7AEF\n     * @return unordered_map<\u8981\
    \u7D20\u306E\u578B, \u51FA\u73FE\u56DE\u6570> \u306E\u5F62\u5F0F\u3067\u51FA\u73FE\
    \u56DE\u6570\u3092\u8FD4\u3059\n    */\n    template <typename Iterator, typename\
    \ _Hash = std::hash<typename std::iterator_traits<Iterator>::value_type>>\n  \
    \  unordered_map<typename std::iterator_traits<Iterator>::value_type, ll, _Hash>\
    \ count_elements_as_unordered(Iterator first, Iterator last) {\n        unordered_map<typename\
    \ std::iterator_traits<Iterator>::value_type, ll, _Hash> counter;\n        for\
    \ (auto it = first; it != last; ++it) {\n            counter[*it]++;\n       \
    \ }\n        return counter;\n    }\n\n    /**\n     * @brief \u30A4\u30C6\u30EC\
    \u30FC\u30BF\u306E\u7BC4\u56F2\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\
    \u51FA\u73FE\u56DE\u6570\u3092\u30AB\u30A6\u30F3\u30C8\u3059\u308B\n     * @tparam\
    \ Iterator \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\n     * @param first \u30A4\
    \u30C6\u30EC\u30FC\u30BF\u306E\u5148\u982D\n     * @param last \u30A4\u30C6\u30EC\
    \u30FC\u30BF\u306E\u7D42\u7AEF\n     * @return map<\u8981\u7D20\u306E\u578B, \u51FA\
    \u73FE\u56DE\u6570> \u306E\u5F62\u5F0F\u3067\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\
    \u3059\n    */\n    template <typename Iterator, typename _Compare = less<typename\
    \ std::iterator_traits<Iterator>::value_type>>\n    map<typename std::iterator_traits<Iterator>::value_type,\
    \ ll, _Compare> count_elements_as_ordered(Iterator first, Iterator last) {\n \
    \       map<typename std::iterator_traits<Iterator>::value_type, ll, _Compare>\
    \ counter;\n        for (auto it = first; it != last; ++it) {\n            counter[*it]++;\n\
    \        }\n        return counter;\n    }\n} // namespace ugilib\n"
  dependsOn:
  - ugilib/base/definitions.hpp
  isVerificationFile: false
  path: ugilib/iteration/counter.hpp
  requiredBy: []
  timestamp: '2024-03-31 15:45:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/iteration/counter.hpp
layout: document
redirect_from:
- /library/ugilib/iteration/counter.hpp
- /library/ugilib/iteration/counter.hpp.html
title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u7BC4\u56F2\u306B\u542B\u307E\u308C\u308B\
  \u8981\u7D20\u306E\u51FA\u73FE\u56DE\u6570\u3092\u30AB\u30A6\u30F3\u30C8\u3059\u308B"
---
