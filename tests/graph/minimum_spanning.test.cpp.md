---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"tests/graph/minimum_spanning.test.cpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/graph/minimum_spanning.hpp\"\n\n/**\n * @file minimum_spanning.hpp\n\
    \ * @brief \u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\u95A2\u6570\u3092\
    \u63D0\u4F9B\n *\n * ## \u95A2\u6570\u4E00\u89A7\n * - `kruskal(n, edges)` : \u30AF\
    \u30E9\u30B9\u30AB\u30EB\u6CD5\u306B\u3088\u308A\u6700\u5C0F\u5168\u57DF\u6728\
    \u3092\u6C42\u3081\u308B\n*/\n\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 13 \"ugilib/graph/minimum_spanning.hpp\"\
    \n#include <atcoder/dsu>\n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n\
    \     * @brief \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\u306B\u3088\u308A\u6700\u5C0F\
    \u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\n     * @tparam weight_t \u8FBA\u306E\
    \u91CD\u307F\u306E\u578B\n     * @param n \u9802\u70B9\u6570\n     * @param edges\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8. \u30BD\u30FC\u30C8\u3059\u308B\u306E\u3067\u30B3\
    \u30D4\u30FC\u6E21\u3057\n     * @return \u6700\u5C0F\u5168\u57DF\u6728\u306E\u91CD\
    \u307F\u3068\u542B\u307E\u308C\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     * @note\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8\u306F {\u91CD\u307F, {\u9802\u70B91, \u9802\u70B9\
    2}} \u306E\u5F62\u5F0F\u3067\u4E0E\u3048\u308B\n     * @note \u8FBA\u306E\u30EA\
    \u30B9\u30C8\u306F\u91CD\u307F\u306E\u6607\u9806\u306B\u30BD\u30FC\u30C8\u3055\
    \u308C\u308B\n     * @note O(E log E). E \u306F\u8FBA\u306E\u6570. \u30DC\u30C8\
    \u30EB\u30CD\u30C3\u30AF\u306F\u30BD\u30FC\u30C8\n    */\n    template <typename\
    \ weight_t>\n    tuple<weight_t, vector<pair<int, int>>> kruskal(int n, vector<pair<weight_t,\
    \ pair<int, int>>> edges) {\n        // \u30BD\u30FC\u30C8\n        sort(edges.begin(),\
    \ edges.end());\n\n        // \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\n        //\
    \ \u91CD\u307F\u306E\u5C0F\u3055\u3044\u9806\u306B\u8FBA\u3092\u8FFD\u52A0\u3057\
    \u3066\u3044\u304F\n        atcoder::dsu uf(n);\n        vector<pair<int, int>>\
    \ mst_edges;\n        weight_t res = 0;\n        for (auto [w, e] : edges) {\n\
    \            auto [u, v] = e;\n            if (uf.same(u, v)) continue;\n    \
    \        uf.merge(u, v);\n            mst_edges.emplace_back(u, v);\n        \
    \    res += w;\n            if (uf.size(u) == n) break;\n        }\n\n       \
    \ // \u5168\u57DF\u6728\u304C\u3067\u304D\u306A\u304B\u3063\u305F\u5834\u5408\n\
    \        if (uf.size(0) != n) return {-1, {}};\n        // \u6700\u5C0F\u5168\u57DF\
    \u6728\u306E\u91CD\u307F\u3068\u8FBA\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\
    \n        return {res, mst_edges};\n    }\n}\n#line 3 \"tests/graph/minimum_spanning.test.cpp\"\
    \n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\nusing namespace std;\n\nint main() {\n    // speed up io\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    // code\n    int V, E;\n    cin >> V\
    \ >> E;\n\n    vector<pair<ll, pair<int, int>>> edges;\n    for (int i = 0; i\
    \ < E; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        edges.push_back({w,\
    \ {s, t}});\n    }\n\n    auto [res, mst_edges] = ugilib::kruskal(V, edges);\n\
    \    cout << res << endl;\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"ugilib/graph/minimum_spanning.hpp\"\n\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\nusing namespace std;\n\nint main() {\n    // speed up io\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    // code\n    int V, E;\n    cin >> V\
    \ >> E;\n\n    vector<pair<ll, pair<int, int>>> edges;\n    for (int i = 0; i\
    \ < E; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        edges.push_back({w,\
    \ {s, t}});\n    }\n\n    auto [res, mst_edges] = ugilib::kruskal(V, edges);\n\
    \    cout << res << endl;\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/graph/minimum_spanning.test.cpp
  requiredBy: []
  timestamp: '2024-05-05 21:37:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/graph/minimum_spanning.test.cpp
layout: document
redirect_from:
- /verify/tests/graph/minimum_spanning.test.cpp
- /verify/tests/graph/minimum_spanning.test.cpp.html
title: tests/graph/minimum_spanning.test.cpp
---