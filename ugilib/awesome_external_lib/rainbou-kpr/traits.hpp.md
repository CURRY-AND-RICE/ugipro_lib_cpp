---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tests/awesome_external_lib/rolling_hash.notest.cpp
    title: tests/awesome_external_lib/rolling_hash.notest.cpp
  - icon: ':heavy_check_mark:'
    path: ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3092\u6271\u3046\
      \u30D8\u30C3\u30C0"
  - icon: ':heavy_check_mark:'
    path: ugilib/string/palindrome.hpp
    title: "\u5217\u306E[l, r)\u304C\u56DE\u6587\u304B\u3069\u3046\u304B\u3092\u5224\
      \u5B9A\u3059\u308B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string/palindrome.test.cpp
    title: tests/string/palindrome.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u578B\u7279\u6027\u3092\u6271\u3046\u30D8\u30C3\u30C0"
    links:
    - "https://github.com/rainbou-kpr/library\u304B\u3089\u306E\u30B3\u30D4\u30FC\u3067\
      \u3059"
  bundledCode: "#line 2 \"ugilib/awesome_external_lib/rainbou-kpr/traits.hpp\"\n\n\
    /**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\u3092\u6271\u3046\u30D8\
    \u30C3\u30C0\n * @note https://github.com/rainbou-kpr/library\u304B\u3089\u306E\
    \u30B3\u30D4\u30FC\u3067\u3059\n */\n\n#include <iterator>\n#include <type_traits>\n\
    #include <utility>\n\nnamespace ugilib::rainbou_kpr {\n    namespace detail {\n\
    \    using std::begin, std::end;\n\n    template <class T, class = void>\n   \
    \ struct is_range_impl : std::false_type {};\n    template <class T>\n    struct\
    \ is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>>\
    \ : std::true_type {};\n    }  // namespace detail\n\n    template <class T>\n\
    \    struct is_range : detail::is_range_impl<T>::type {};\n    template <class\
    \ T>\n    inline constexpr bool is_range_v = is_range<T>::value;\n}  // namespace\
    \ ugilib::rainbou_kpr\n"
  code: "#pragma once\n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\u3092\
    \u6271\u3046\u30D8\u30C3\u30C0\n * @note https://github.com/rainbou-kpr/library\u304B\
    \u3089\u306E\u30B3\u30D4\u30FC\u3067\u3059\n */\n\n#include <iterator>\n#include\
    \ <type_traits>\n#include <utility>\n\nnamespace ugilib::rainbou_kpr {\n    namespace\
    \ detail {\n    using std::begin, std::end;\n\n    template <class T, class =\
    \ void>\n    struct is_range_impl : std::false_type {};\n    template <class T>\n\
    \    struct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>>\
    \ : std::true_type {};\n    }  // namespace detail\n\n    template <class T>\n\
    \    struct is_range : detail::is_range_impl<T>::type {};\n    template <class\
    \ T>\n    inline constexpr bool is_range_v = is_range<T>::value;\n}  // namespace\
    \ ugilib::rainbou_kpr"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/awesome_external_lib/rainbou-kpr/traits.hpp
  requiredBy:
  - ugilib/string/palindrome.hpp
  - ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp
  - tests/awesome_external_lib/rolling_hash.notest.cpp
  timestamp: '2024-05-18 17:31:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string/palindrome.test.cpp
documentation_of: ugilib/awesome_external_lib/rainbou-kpr/traits.hpp
layout: document
redirect_from:
- /library/ugilib/awesome_external_lib/rainbou-kpr/traits.hpp
- /library/ugilib/awesome_external_lib/rainbou-kpr/traits.hpp.html
title: "\u578B\u7279\u6027\u3092\u6271\u3046\u30D8\u30C3\u30C0"
---
