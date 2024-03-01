---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: lib/graph/dijkstra.cpp:\
    \ line -1: no such header\n"
  code: "#include <bits/stdc++.h>\n#include \"lib/graph/dijkstra.cpp\"\n\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp\"\
    \n\nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\n#define rep(i, n) for(int i = 0; i < (int)(n); i++) \
    \ // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n#define ur auto&&\
    \  // universal reference. care needed\n\n// const ll INF = 1LL << 60;  // infinity\n\
    \nint main() {\n    // speed up io\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    // code\n    ll V, E, r;\n    cin >> V >> E >> r;\n\n    vector<vector<pair<int,\
    \ ll>>> graph(V);\n\n    rep(i, E) {\n        int s, t, d;\n        cin >> s >>\
    \ t >> d;\n        graph[s].push_back({t, d});\n    }\n\n    auto &&costs = dijkstra(V,\
    \ r, graph);\n    rep(i, V) {\n        if (costs[i] == INF) cout << \"INF\\n\"\
    ;\n        else cout << costs[i] << '\\n';\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/graph/dijkstra.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/graph/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/tests/graph/dijkstra.test.cpp
- /verify/tests/graph/dijkstra.test.cpp.html
title: tests/graph/dijkstra.test.cpp
---
