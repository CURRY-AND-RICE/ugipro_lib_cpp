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
  bundledCode: "#line 2 \"ugilib/std_util/hashes.hpp\"\n#include <utility>\nusing\
    \ namespace std;\n\nnamespace ugilib {\n    struct pair_hash {\n        template\
    \ <class T1, class T2>\n        size_t operator () (const pair<T1, T2> &pair)\
    \ const {\n            auto hash1 = hash<T1>{}(pair.first);\n            auto\
    \ hash2 = hash<T2>{}(pair.second);\n            return hash1 ^ (hash2 << 1);\n\
    \        }\n    };\n} // namespace ugilib\n"
  code: "#pragma once\n#include <utility>\nusing namespace std;\n\nnamespace ugilib\
    \ {\n    struct pair_hash {\n        template <class T1, class T2>\n        size_t\
    \ operator () (const pair<T1, T2> &pair) const {\n            auto hash1 = hash<T1>{}(pair.first);\n\
    \            auto hash2 = hash<T2>{}(pair.second);\n            return hash1 ^\
    \ (hash2 << 1);\n        }\n    };\n} // namespace ugilib\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/std_util/hashes.hpp
  requiredBy: []
  timestamp: '2024-03-31 15:54:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/std_util/hashes.hpp
layout: document
redirect_from:
- /library/ugilib/std_util/hashes.hpp
- /library/ugilib/std_util/hashes.hpp.html
title: ugilib/std_util/hashes.hpp
---
