---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/std_util/array_hash.test.cpp
    title: tests/std_util/array_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53\u306E\u5B9A\u7FA9"
    links: []
  bundledCode: "#line 2 \"ugilib/std_util/hashes.hpp\"\n\n/**\n * @file hashes.hpp\n\
    \ * @brief \u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53\u306E\u5B9A\u7FA9\n * @note\
    \ pair<T1, T2>, iterable<T>\u306B\u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\
    \u6570\u3092\u5B9A\u7FA9\n*/\n\n#include <utility>\n#include <type_traits>\nusing\
    \ namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief pair<T1, T2>\u306B\
    \u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\n     * @tparam T1 pair\u306E\
    1\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\n     * @tparam T2 pair\u306E2\u3064\
    \u76EE\u306E\u8981\u7D20\u306E\u578B\n    */\n    struct pair_hash {\n       \
    \ template <class T1, class T2>\n        size_t operator() (const pair<T1, T2>\
    \ &pair) const {\n            auto hash1 = hash<T1>{}(pair.first);\n         \
    \   auto hash2 = hash<T2>{}(pair.second);\n            return hash1 ^ (hash2 <<\
    \ 1);\n        }\n    };\n\n    /**\n     * @brief Iterable\u306B\u5BFE\u3059\u308B\
    \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\n     * @tparam Iterable \u30A4\u30C6\u30E9\
    \u30D6\u30EB\u306A\u30B3\u30F3\u30C6\u30CA\n    */\n    struct array_hash {\n\
    \        /**\n         * @brief \u30A4\u30C6\u30E9\u30D6\u30EB\u578B\u306E\u30CF\
    \u30C3\u30B7\u30E5\u8A08\u7B97\n         * @tparam T \u30A4\u30C6\u30E9\u30D6\u30EB\
    \u306E\u8981\u7D20\u306E\u578B\n         * @param value \u30A4\u30C6\u30E9\u30D6\
    \u30EB\u306E\u8981\u7D20\n         * @return size_t \u30CF\u30C3\u30B7\u30E5\u5024\
    \n         * @note \u518D\u5E30\u7684\u547C\u3073\u51FA\u3057\u3067\u7B97\u8853\
    \u578B\u306B\u8FBF\u308A\u7740\u3044\u305F\u5834\u5408\u306E\u30CF\u30C3\u30B7\
    \u30E5\n        */\n        template <typename T, std::enable_if_t<std::is_arithmetic_v<T>,\
    \ int> = 0>\n        size_t operator() (const T& value) const {\n            size_t\
    \ hash = 0;\n            hash ^= std::hash<T>{}(value) + 0x9e3779b9 + (hash <<\
    \ 6) + (hash >> 2);\n            return hash;\n        }\n\n        /**\n    \
    \     * @brief \u30A4\u30C6\u30EC\u30FC\u30BF\u7279\u6027\u3092\u6301\u305F\u306A\
    \u3044array<T, N>\u306B\u5BFE\u3059\u308B\u7279\u6B8A\u5316\n         * @tparam\
    \ T array\u306E\u8981\u7D20\u306E\u578B\n         * @tparam N array\u306E\u8981\
    \u7D20\u6570\n         * @param array array\n         * @return size_t \u30CF\u30C3\
    \u30B7\u30E5\u5024\n        */\n        template <typename T, size_t N>\n    \
    \    size_t operator() (const array<T, N> &array) const {\n            size_t\
    \ hash = 0;\n            for (const auto& item : array) {\n                hash\
    \ ^= (*this)(item) + 0x9e3779b9 + (hash << 6) + (hash >> 2);\n            }\n\
    \            return hash;\n        }\n\n        /**\n         * @brief \u30A4\u30C6\
    \u30E9\u30D6\u30EB\u578B\u306E\u30CF\u30C3\u30B7\u30E5\u8A08\u7B97\n         *\
    \ @tparam Iterable \u30A4\u30C6\u30E9\u30D6\u30EB\u306A\u30B3\u30F3\u30C6\u30CA\
    \n         * @param iterable \u30A4\u30C6\u30E9\u30D6\u30EB\n         * @return\
    \ size_t \u30CF\u30C3\u30B7\u30E5\u5024\n         * @note \u518D\u5E30\u7684\u547C\
    \u3073\u51FA\u3057\u3092\u884C\u3044\u3001\u591A\u6B21\u5143\u30B3\u30F3\u30C6\
    \u30CA\u306B\u5BFE\u3057\u3066\u3082\u30CF\u30C3\u30B7\u30E5\u53EF\u80FD\n   \
    \     */\n        template <typename Iterable, std::enable_if_t<!std::is_arithmetic_v<Iterable>\
    \ &&\n                                                    std::is_same_v<typename\
    \ std::iterator_traits<typename Iterable::iterator>::iterator_category, std::input_iterator_tag>,\
    \ int> = 0>\n        size_t operator() (const Iterable &iterable) const {\n  \
    \          size_t hash = 0;\n            for (const auto &item : iterable) {\n\
    \                hash ^= (*this)(item) + 0x9e3779b9 + (hash << 6) + (hash >> 2);\n\
    \            }\n            return hash;\n        }\n    };\n} // namespace ugilib\n"
  code: "#pragma once\n\n/**\n * @file hashes.hpp\n * @brief \u30CF\u30C3\u30B7\u30E5\
    \u69CB\u9020\u4F53\u306E\u5B9A\u7FA9\n * @note pair<T1, T2>, iterable<T>\u306B\
    \u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\u3092\u5B9A\u7FA9\n*/\n\
    \n#include <utility>\n#include <type_traits>\nusing namespace std;\n\nnamespace\
    \ ugilib {\n    /**\n     * @brief pair<T1, T2>\u306B\u5BFE\u3059\u308B\u30CF\u30C3\
    \u30B7\u30E5\u95A2\u6570\n     * @tparam T1 pair\u306E1\u3064\u76EE\u306E\u8981\
    \u7D20\u306E\u578B\n     * @tparam T2 pair\u306E2\u3064\u76EE\u306E\u8981\u7D20\
    \u306E\u578B\n    */\n    struct pair_hash {\n        template <class T1, class\
    \ T2>\n        size_t operator() (const pair<T1, T2> &pair) const {\n        \
    \    auto hash1 = hash<T1>{}(pair.first);\n            auto hash2 = hash<T2>{}(pair.second);\n\
    \            return hash1 ^ (hash2 << 1);\n        }\n    };\n\n    /**\n    \
    \ * @brief Iterable\u306B\u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \n     * @tparam Iterable \u30A4\u30C6\u30E9\u30D6\u30EB\u306A\u30B3\u30F3\u30C6\
    \u30CA\n    */\n    struct array_hash {\n        /**\n         * @brief \u30A4\
    \u30C6\u30E9\u30D6\u30EB\u578B\u306E\u30CF\u30C3\u30B7\u30E5\u8A08\u7B97\n   \
    \      * @tparam T \u30A4\u30C6\u30E9\u30D6\u30EB\u306E\u8981\u7D20\u306E\u578B\
    \n         * @param value \u30A4\u30C6\u30E9\u30D6\u30EB\u306E\u8981\u7D20\n \
    \        * @return size_t \u30CF\u30C3\u30B7\u30E5\u5024\n         * @note \u518D\
    \u5E30\u7684\u547C\u3073\u51FA\u3057\u3067\u7B97\u8853\u578B\u306B\u8FBF\u308A\
    \u7740\u3044\u305F\u5834\u5408\u306E\u30CF\u30C3\u30B7\u30E5\n        */\n   \
    \     template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>\n\
    \        size_t operator() (const T& value) const {\n            size_t hash =\
    \ 0;\n            hash ^= std::hash<T>{}(value) + 0x9e3779b9 + (hash << 6) + (hash\
    \ >> 2);\n            return hash;\n        }\n\n        /**\n         * @brief\
    \ \u30A4\u30C6\u30EC\u30FC\u30BF\u7279\u6027\u3092\u6301\u305F\u306A\u3044array<T,\
    \ N>\u306B\u5BFE\u3059\u308B\u7279\u6B8A\u5316\n         * @tparam T array\u306E\
    \u8981\u7D20\u306E\u578B\n         * @tparam N array\u306E\u8981\u7D20\u6570\n\
    \         * @param array array\n         * @return size_t \u30CF\u30C3\u30B7\u30E5\
    \u5024\n        */\n        template <typename T, size_t N>\n        size_t operator()\
    \ (const array<T, N> &array) const {\n            size_t hash = 0;\n         \
    \   for (const auto& item : array) {\n                hash ^= (*this)(item) +\
    \ 0x9e3779b9 + (hash << 6) + (hash >> 2);\n            }\n            return hash;\n\
    \        }\n\n        /**\n         * @brief \u30A4\u30C6\u30E9\u30D6\u30EB\u578B\
    \u306E\u30CF\u30C3\u30B7\u30E5\u8A08\u7B97\n         * @tparam Iterable \u30A4\
    \u30C6\u30E9\u30D6\u30EB\u306A\u30B3\u30F3\u30C6\u30CA\n         * @param iterable\
    \ \u30A4\u30C6\u30E9\u30D6\u30EB\n         * @return size_t \u30CF\u30C3\u30B7\
    \u30E5\u5024\n         * @note \u518D\u5E30\u7684\u547C\u3073\u51FA\u3057\u3092\
    \u884C\u3044\u3001\u591A\u6B21\u5143\u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3057\
    \u3066\u3082\u30CF\u30C3\u30B7\u30E5\u53EF\u80FD\n        */\n        template\
    \ <typename Iterable, std::enable_if_t<!std::is_arithmetic_v<Iterable> &&\n  \
    \                                                  std::is_same_v<typename std::iterator_traits<typename\
    \ Iterable::iterator>::iterator_category, std::input_iterator_tag>, int> = 0>\n\
    \        size_t operator() (const Iterable &iterable) const {\n            size_t\
    \ hash = 0;\n            for (const auto &item : iterable) {\n               \
    \ hash ^= (*this)(item) + 0x9e3779b9 + (hash << 6) + (hash >> 2);\n          \
    \  }\n            return hash;\n        }\n    };\n} // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/std_util/hashes.hpp
  requiredBy: []
  timestamp: '2024-05-11 00:20:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/std_util/array_hash.test.cpp
documentation_of: ugilib/std_util/hashes.hpp
layout: document
redirect_from:
- /library/ugilib/std_util/hashes.hpp
- /library/ugilib/std_util/hashes.hpp.html
title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53\u306E\u5B9A\u7FA9"
---
