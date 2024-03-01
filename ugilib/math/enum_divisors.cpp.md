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
  bundledCode: "#line 1 \"ugilib/math/enum_divisors.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// \u7D04\u6570\u5217\u6319\ntemplate <typename T>\nunordered_set<T>\
    \ enum_divisors(T n) {\n    unordered_set<T> divisors;\n    for (T i = 1; i *\
    \ i <= n; i++) {\n        if (n % i == 0) {\n            divisors.insert(i);\n\
    \            divisors.insert(n / i);\n        }\n    }\n    return divisors;\n\
    }\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u7D04\u6570\u5217\u6319\
    \ntemplate <typename T>\nunordered_set<T> enum_divisors(T n) {\n    unordered_set<T>\
    \ divisors;\n    for (T i = 1; i * i <= n; i++) {\n        if (n % i == 0) {\n\
    \            divisors.insert(i);\n            divisors.insert(n / i);\n      \
    \  }\n    }\n    return divisors;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/math/enum_divisors.cpp
  requiredBy: []
  timestamp: '2024-03-01 15:38:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/math/enum_divisors.cpp
layout: document
redirect_from:
- /library/ugilib/math/enum_divisors.cpp
- /library/ugilib/math/enum_divisors.cpp.html
title: ugilib/math/enum_divisors.cpp
---
