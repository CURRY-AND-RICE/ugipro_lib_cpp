---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53\u306E\u5B9A\u7FA9"
    links: []
  bundledCode: "#line 2 \"ugilib/std_util/hashes.hpp\"\n\n/**\n * @file hashes.hpp\n\
    \ * @brief \u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53\u306E\u5B9A\u7FA9\n * @note\
    \ pair<T1, T2>, iterable<T>\u306B\u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\
    \u6570\u3092\u5B9A\u7FA9\n*/\n\n#include <utility>\nusing namespace std;\n\nnamespace\
    \ ugilib {\n    /**\n     * @brief pair<T1, T2>\u306B\u5BFE\u3059\u308B\u30CF\u30C3\
    \u30B7\u30E5\u95A2\u6570\n     * @tparam T1 pair\u306E1\u3064\u76EE\u306E\u8981\
    \u7D20\u306E\u578B\n     * @tparam T2 pair\u306E2\u3064\u76EE\u306E\u8981\u7D20\
    \u306E\u578B\n    */\n    struct pair_hash {\n        template <class T1, class\
    \ T2>\n        size_t operator () (const pair<T1, T2> &pair) const {\n       \
    \     auto hash1 = hash<T1>{}(pair.first);\n            auto hash2 = hash<T2>{}(pair.second);\n\
    \            return hash1 ^ (hash2 << 1);\n        }\n    };\n\n    /**\n    \
    \ * @brief iterable<T>\u306B\u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \n     * @tparam T iterable\u306E\u8981\u7D20\u306E\u578B\n     * @note zobrist\
    \ hashing + DJB2 hash\u3067\u5B9F\u88C5\n     * @note \u672C\u6765\u306A\u3089\
    \u3070zobrist hashing\u306F\u4E71\u6570\u3092\u7528\u3044\u308B\u304C\u3001\u3053\
    \u3053\u3067\u306Fstd::hash\u3092\u7528\u3044\u3066\u3044\u308B\n    */\n    struct\
    \ zobrist_hash {\n        template <class T>\n        size_t operator () (const\
    \ T &iterable) const {\n            size_t hash = 0;\n            for (const auto\
    \ &item : iterable) {\n                hash ^= std::hash<typename T::value_type>{}(item)\
    \ + 0x9e3779b9 + (hash << 6) + (hash >> 2);\n            }\n            return\
    \ hash;\n        }\n    };\n} // namespace ugilib\n"
  code: "#pragma once\n\n/**\n * @file hashes.hpp\n * @brief \u30CF\u30C3\u30B7\u30E5\
    \u69CB\u9020\u4F53\u306E\u5B9A\u7FA9\n * @note pair<T1, T2>, iterable<T>\u306B\
    \u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\u3092\u5B9A\u7FA9\n*/\n\
    \n#include <utility>\nusing namespace std;\n\nnamespace ugilib {\n    /**\n  \
    \   * @brief pair<T1, T2>\u306B\u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\
    \u6570\n     * @tparam T1 pair\u306E1\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\
    \n     * @tparam T2 pair\u306E2\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\n  \
    \  */\n    struct pair_hash {\n        template <class T1, class T2>\n       \
    \ size_t operator () (const pair<T1, T2> &pair) const {\n            auto hash1\
    \ = hash<T1>{}(pair.first);\n            auto hash2 = hash<T2>{}(pair.second);\n\
    \            return hash1 ^ (hash2 << 1);\n        }\n    };\n\n    /**\n    \
    \ * @brief iterable<T>\u306B\u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \n     * @tparam T iterable\u306E\u8981\u7D20\u306E\u578B\n     * @note zobrist\
    \ hashing + DJB2 hash\u3067\u5B9F\u88C5\n     * @note \u672C\u6765\u306A\u3089\
    \u3070zobrist hashing\u306F\u4E71\u6570\u3092\u7528\u3044\u308B\u304C\u3001\u3053\
    \u3053\u3067\u306Fstd::hash\u3092\u7528\u3044\u3066\u3044\u308B\n    */\n    struct\
    \ zobrist_hash {\n        template <class T>\n        size_t operator () (const\
    \ T &iterable) const {\n            size_t hash = 0;\n            for (const auto\
    \ &item : iterable) {\n                hash ^= std::hash<typename T::value_type>{}(item)\
    \ + 0x9e3779b9 + (hash << 6) + (hash >> 2);\n            }\n            return\
    \ hash;\n        }\n    };\n} // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/std_util/hashes.hpp
  requiredBy: []
  timestamp: '2024-04-28 18:37:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/std_util/hashes.hpp
layout: document
redirect_from:
- /library/ugilib/std_util/hashes.hpp
- /library/ugilib/std_util/hashes.hpp.html
title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53\u306E\u5B9A\u7FA9"
---
