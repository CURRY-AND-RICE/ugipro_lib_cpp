---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.cpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
  bundledCode: "#line 1 \"tests/graph/dijkstra.test.cpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"lib/graph/dijkstra.cpp\"\n\nusing namespace std;\nusing ll = long long;\n\
    \nconst ll INF = 1LL << 60;  // infinity\n\n/// cut begin\n/**\n * @brief \u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @param n \u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u6570\n * @param start \u59CB\u70B9\n * @param graph \u30B0\u30E9\u30D5\
    . vector<pair<int, ll>> \u3067\u96A3\u63A5\u9802\u70B9\u3068\u30B3\u30B9\u30C8\
    \u3092\u8868\u3059\n * @return \u59CB\u70B9\u304B\u3089\u5404\u9802\u70B9\u307E\
    \u3067\u306E\u6700\u77ED\u8DDD\u96E2\n * @note O((E+V)logV)\n*/\ntemplate<typename\
    \ weight_type>\nvector<weight_type> dijkstra(int n, int start, const vector<vector<pair<int,\
    \ weight_type>>>& graph) {\n    vector<weight_type> costs(n, INF);\n    costs[start]\
    \ = 0;\n\n    priority_queue<pair<weight_type, int>, vector<pair<weight_type,\
    \ int>>, greater<>> next_nodes;\n    next_nodes.push({0, start});\n\n    while\
    \ (!next_nodes.empty()) {\n        auto [cost, node] = next_nodes.top(); next_nodes.pop();\n\
    \        if (cost > costs[node]) continue;\n\n        for (auto [next_node, next_cost]\
    \ : graph[node]) {\n            auto new_cost = cost + next_cost;\n          \
    \  if (new_cost < costs[next_node]) {\n                costs[next_node] = cost\
    \ + next_cost;\n                next_nodes.push({costs[next_node], next_node});\n\
    \            }\n        }\n    }\n\n    return costs;\n}\n/// cut end\n\n#line\
    \ 3 \"tests/graph/dijkstra.test.cpp\"\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp\"\
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
  dependsOn:
  - lib/graph/dijkstra.cpp
  isVerificationFile: true
  path: tests/graph/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2024-02-28 22:23:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/tests/graph/dijkstra.test.cpp
- /verify/tests/graph/dijkstra.test.cpp.html
title: tests/graph/dijkstra.test.cpp
---
