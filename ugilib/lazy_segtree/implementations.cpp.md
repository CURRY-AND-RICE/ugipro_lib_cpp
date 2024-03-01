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
  bundledCode: "#line 1 \"ugilib/lazy_segtree/implementations.cpp\"\n#include <bits/stdc++.h>\n\
    #include <atcoder/segtree>\n#include <atcoder/lazysegtree>\n\nusing namespace\
    \ std;\nusing namespace atcoder;\n\nusing ll = long long;\nconst ll INF = 1LL\
    \ << 60;\n\nnamespace segtree_min {\n    using S = ll;\n    S op(S a, S b) { return\
    \ min(a, b); }\n    S e() { return INF;}\n\n    vector<S> initializer{1, 2, 3,\
    \ 4, 5};\n    segtree<S, segtree_sum::op, segtree_sum::e> seg(initializer);\n\
    };\n\nnamespace segtree_sum {\n    using S = ll;\n    S op(S a, S b) { return\
    \ a + b; }\n    S e() { return 0;}\n\n    vector<S> initializer{1, 2, 3, 4, 5};\n\
    \    segtree<S, segtree_sum::op, segtree_sum::e> seg(initializer);\n};\n\nnamespace\
    \ lazy_segtree_range_update {\n    using S = ll;\n    using F = ll;\n    const\
    \ F ID = INF;\n\n    S op(S a, S b) { return 0; }  // no prod query\n    S e()\
    \ { return (1LL<<31) - 1; }  // intial value\n    S mapping(F f, S s) { return\
    \ (f != ID) ? f : s; }\n    F composition(F f, F lazy) { return (f != ID) ? f\
    \ : lazy; }\n    F id() { return ID; }\n\n    int n = 5;\n    lazy_segtree<S,\
    \ op, e, F, mapping, composition, id> lst(n);\n};\n\nnamespace lazy_segtree_range_add\
    \ {\n    using S = ll;\n    using F = ll;\n\n    S op(S a, S b) { return 0; }\
    \  // no prod query\n    S e() { return 0; }  // intial value\n    S mapping(F\
    \ f, S x) { return f + x; }\n    F composition(F f, F g) { return f + g; }\n \
    \   F id() { return 0; }\n\n    int n = 5;\n    lazy_segtree<S, op, e, F, mapping,\
    \ composition, id> lst(n);\n};\n\n// range minimum query and range update query\n\
    namespace lazy_segtree_rmq_ruq {\n    using S = ll;\n    using F = ll;\n    const\
    \ F ID = INF;\n\n    S op(S a, S b) { return (a < b) ? a : b; }  // min query\n\
    \    S e() { return (1LL<<31) - 1; }  // initial value\n    S mapping(F f, S x)\
    \ { return (f == ID) ? x : f; }\n    F composition(F f, F g) { return (f == ID)\
    \ ? g : f; }\n    F id() { return ID; }\n\n    int  n = 5;\n    lazy_segtree<S,\
    \ op, e, F, mapping, composition, id> lst(n);\n}\n\n// range sum query and range\
    \ add query\nnamespace lazy_segtree_rsq_raq {\n    struct S {\n        ll value;\n\
    \        ll size;\n    };\n    using F = ll;\n    S op(S a, S b) { return {a.value\
    \ + b.value, a.size + b.size}; }  // sum query\n    S e() { return {0, 0}; } \
    \ // initial value\n    S mapping(F f, S x) {  // lazy add\n        x.value +=\
    \ f * x.size;\n        return x;\n    }\n    F composition(F f, F g) { return\
    \ f + g;}\n    F id() { return 0; }\n\n    vector<S> initializer{{0, 1}, {0, 1},\
    \ {0, 1}, {0, 1}, {0, 1}};\n    lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> lst(initializer);\n}\n\n// range minimum query and range add query\nnamespace\
    \ lazy_segtree_rmq_raq {\n    using S = ll;\n    using F = ll;\n    S op(S a,\
    \ S b) { return (a < b) ? a : b; }  // min query\n    S e() { return INF; }  //\
    \ initial value\n    S mapping(F f, S x) { return f + x; }  // add to minimum\n\
    \    F composition(F f, F g) { return f + g; }\n    F id() { return 0; }\n\n \
    \   vector<S> initializer{0, 0, 0, 0, 0};\n    lazy_segtree<S, op, e, F, mapping,\
    \ composition, id> lst(initializer);\n}\n\n// range sum query and range update\
    \ query\nnamespace lazy_segtree_rsq_ruq {\n    struct S {\n        ll value;\n\
    \        ll size;\n    };\n    using F = ll;\n    const F ID = INF;\n    S op(S\
    \ a, S b) { return {a.value + b.value, a.size + b.size}; }\n    S e() { return\
    \ {0, 0}; }\n    S mapping(F f, S x) {\n        if (f != ID) x.value = f * x.size;\n\
    \        return x;\n    }\n    F composition(F f, F g) { return (f == ID) ? g\
    \ : f; }\n    F id() { return ID; }\n\n    vector<S> initializer{{0, 1}, {0, 1},\
    \ {0, 1}, {0, 1}, {0, 1}};\n    lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> lst(ini);\n}\n"
  code: "#include <bits/stdc++.h>\n#include <atcoder/segtree>\n#include <atcoder/lazysegtree>\n\
    \nusing namespace std;\nusing namespace atcoder;\n\nusing ll = long long;\nconst\
    \ ll INF = 1LL << 60;\n\nnamespace segtree_min {\n    using S = ll;\n    S op(S\
    \ a, S b) { return min(a, b); }\n    S e() { return INF;}\n\n    vector<S> initializer{1,\
    \ 2, 3, 4, 5};\n    segtree<S, segtree_sum::op, segtree_sum::e> seg(initializer);\n\
    };\n\nnamespace segtree_sum {\n    using S = ll;\n    S op(S a, S b) { return\
    \ a + b; }\n    S e() { return 0;}\n\n    vector<S> initializer{1, 2, 3, 4, 5};\n\
    \    segtree<S, segtree_sum::op, segtree_sum::e> seg(initializer);\n};\n\nnamespace\
    \ lazy_segtree_range_update {\n    using S = ll;\n    using F = ll;\n    const\
    \ F ID = INF;\n\n    S op(S a, S b) { return 0; }  // no prod query\n    S e()\
    \ { return (1LL<<31) - 1; }  // intial value\n    S mapping(F f, S s) { return\
    \ (f != ID) ? f : s; }\n    F composition(F f, F lazy) { return (f != ID) ? f\
    \ : lazy; }\n    F id() { return ID; }\n\n    int n = 5;\n    lazy_segtree<S,\
    \ op, e, F, mapping, composition, id> lst(n);\n};\n\nnamespace lazy_segtree_range_add\
    \ {\n    using S = ll;\n    using F = ll;\n\n    S op(S a, S b) { return 0; }\
    \  // no prod query\n    S e() { return 0; }  // intial value\n    S mapping(F\
    \ f, S x) { return f + x; }\n    F composition(F f, F g) { return f + g; }\n \
    \   F id() { return 0; }\n\n    int n = 5;\n    lazy_segtree<S, op, e, F, mapping,\
    \ composition, id> lst(n);\n};\n\n// range minimum query and range update query\n\
    namespace lazy_segtree_rmq_ruq {\n    using S = ll;\n    using F = ll;\n    const\
    \ F ID = INF;\n\n    S op(S a, S b) { return (a < b) ? a : b; }  // min query\n\
    \    S e() { return (1LL<<31) - 1; }  // initial value\n    S mapping(F f, S x)\
    \ { return (f == ID) ? x : f; }\n    F composition(F f, F g) { return (f == ID)\
    \ ? g : f; }\n    F id() { return ID; }\n\n    int  n = 5;\n    lazy_segtree<S,\
    \ op, e, F, mapping, composition, id> lst(n);\n}\n\n// range sum query and range\
    \ add query\nnamespace lazy_segtree_rsq_raq {\n    struct S {\n        ll value;\n\
    \        ll size;\n    };\n    using F = ll;\n    S op(S a, S b) { return {a.value\
    \ + b.value, a.size + b.size}; }  // sum query\n    S e() { return {0, 0}; } \
    \ // initial value\n    S mapping(F f, S x) {  // lazy add\n        x.value +=\
    \ f * x.size;\n        return x;\n    }\n    F composition(F f, F g) { return\
    \ f + g;}\n    F id() { return 0; }\n\n    vector<S> initializer{{0, 1}, {0, 1},\
    \ {0, 1}, {0, 1}, {0, 1}};\n    lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> lst(initializer);\n}\n\n// range minimum query and range add query\nnamespace\
    \ lazy_segtree_rmq_raq {\n    using S = ll;\n    using F = ll;\n    S op(S a,\
    \ S b) { return (a < b) ? a : b; }  // min query\n    S e() { return INF; }  //\
    \ initial value\n    S mapping(F f, S x) { return f + x; }  // add to minimum\n\
    \    F composition(F f, F g) { return f + g; }\n    F id() { return 0; }\n\n \
    \   vector<S> initializer{0, 0, 0, 0, 0};\n    lazy_segtree<S, op, e, F, mapping,\
    \ composition, id> lst(initializer);\n}\n\n// range sum query and range update\
    \ query\nnamespace lazy_segtree_rsq_ruq {\n    struct S {\n        ll value;\n\
    \        ll size;\n    };\n    using F = ll;\n    const F ID = INF;\n    S op(S\
    \ a, S b) { return {a.value + b.value, a.size + b.size}; }\n    S e() { return\
    \ {0, 0}; }\n    S mapping(F f, S x) {\n        if (f != ID) x.value = f * x.size;\n\
    \        return x;\n    }\n    F composition(F f, F g) { return (f == ID) ? g\
    \ : f; }\n    F id() { return ID; }\n\n    vector<S> initializer{{0, 1}, {0, 1},\
    \ {0, 1}, {0, 1}, {0, 1}};\n    lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> lst(ini);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ugilib/lazy_segtree/implementations.cpp
  requiredBy: []
  timestamp: '2024-03-01 15:38:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ugilib/lazy_segtree/implementations.cpp
layout: document
redirect_from:
- /library/ugilib/lazy_segtree/implementations.cpp
- /library/ugilib/lazy_segtree/implementations.cpp.html
title: ugilib/lazy_segtree/implementations.cpp
---
