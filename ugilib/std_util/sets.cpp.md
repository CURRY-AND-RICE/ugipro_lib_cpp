---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ugilib/std_util/sets.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// \u548C\u96C6\u5408\ntemplate <typename SetType>\nSetType\
    \ set_union(const SetType& s1, const SetType& s2) {\n    SetType result(s1);\n\
    \    result.insert(s2.begin(), s2.end());\n    return result;\n}\n\n// \u7A4D\u96C6\
    \u5408\ntemplate <typename SetType>\nSetType set_intersection(const SetType& s1,\
    \ const SetType& s2) {\n    SetType intersection;\n    for (const auto& e : s1)\
    \ {\n        if (s2.find(e) != s2.end()) {\n            intersection.insert(e);\n\
    \        }\n    }\n    return intersection;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u548C\u96C6\u5408\n\
    template <typename SetType>\nSetType set_union(const SetType& s1, const SetType&\
    \ s2) {\n    SetType result(s1);\n    result.insert(s2.begin(), s2.end());\n \
    \   return result;\n}\n\n// \u7A4D\u96C6\u5408\ntemplate <typename SetType>\n\
    SetType set_intersection(const SetType& s1, const SetType& s2) {\n    SetType\
    \ intersection;\n    for (const auto& e : s1) {\n        if (s2.find(e) != s2.end())\
    \ {\n            intersection.insert(e);\n        }\n    }\n    return intersection;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/std_util/sets.cpp
  requiredBy: []
  timestamp: '2024-03-01 15:38:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/std_util/sets.cpp
layout: document
redirect_from:
- /library/ugilib/std_util/sets.cpp
- /library/ugilib/std_util/sets.cpp.html
title: ugilib/std_util/sets.cpp
---
