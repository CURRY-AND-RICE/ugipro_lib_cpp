---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/base/constants.hpp
    title: ugilib/base/constants.hpp
  - icon: ':heavy_check_mark:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/bfs.hpp
    title: "0or1\u5E45\u512A\u5148\u63A2\u7D22. 01BFS"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"tests/graph/bfs.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(int i = 0; i < (int)(n); i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"ugilib/graph/bfs.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief 0or1\u5E45\
    \u512A\u5148\u63A2\u7D22. 01BFS\n     * @param n \u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u6570\n     * @param start \u59CB\u70B9\n     * @param graph \u30B0\u30E9\
    \u30D5. vector<pair<int, weight_type>> \u3067\u96A3\u63A5\u9802\u70B9\u3068\u30B3\
    \u30B9\u30C8\u3092\u8868\u3059. \u30B3\u30B9\u30C8\u306F0 or 1\n     * @param\
    \ weight_inf \u7121\u9650\u5927\u306E\u5024. \u30D1\u30B9\u304C\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\u30C8\n     * @return \u59CB\u70B9\u304B\
    \u3089\u5404\u9802\u70B9\u307E\u3067\u306E\u6700\u77ED\u8DDD\u96E2\n     * @note\
    \ O(E+V)\n     * @todo 01BFS\u554F\u984C\u3067\u306E\u30C6\u30B9\u30C8\u3092\u66F8\
    \u304F\n    */\n    template <typename weight_type>\n    vector<weight_type> bfs01(int\
    \ n, int start, const vector<vector<pair<int, weight_type>>> &graph, weight_type\
    \ weight_inf = ugilib::constants::INF<weight_type>) {\n        vector<weight_type>\
    \ costs(n, weight_inf);\n        costs[start] = 0;\n\n        deque<int> next_nodes;\n\
    \        next_nodes.push_back(start);\n\n        while (!next_nodes.empty()) {\n\
    \            auto node = next_nodes.front(); next_nodes.pop_front();\n       \
    \     auto cost = costs[node];\n\n            for (const auto [next_node, next_cost]\
    \ : graph[node]) {\n                auto new_cost = cost + next_cost;\n      \
    \          if (new_cost < costs[next_node]) {\n                    costs[next_node]\
    \ = new_cost;\n                    // 0or1\u5E45\u512A\u5148\u63A2\u7D22\u306E\
    \u5834\u5408, \u30B3\u30B9\u30C8\u304C0\u306E\u5834\u5408\u306F\u524D\u304B\u3089\
    \u5165\u308C, 1\u306E\u5834\u5408\u306F\u5F8C\u308D\u306B\u5165\u308C\u308B\n\
    \                    if (next_cost == 0) next_nodes.push_front(next_node);\n \
    \                   else next_nodes.push_back(next_node);\n                }\n\
    \            }\n        }\n\n        return costs;\n    }\n}  // namespace ugilib\n\
    #line 7 \"tests/graph/bfs.test.cpp\"\n\nusing namespace std;\n\n// debug settings\n\
    // #define DEBUG\n#ifdef DEBUG\n// debug input\nstring _INPUT = R\"(\n5\n1 2 3\
    \ 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1)); // remove '\\n' at _INPUT[0]\n\
    #else\n// standard input\nauto& _cin = cin;\n#endif\n\n// speed up\n#pragma GCC\
    \ target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n// reader\nstruct rd {\n    static ll i() {ll i; _cin >> i; return i;}  //\
    \ long long\n    static ld d() {ld d; _cin >> d; return d;}  // long double\n\
    \    static string s() {string s; _cin >> s; return s;}  // string\n    static\
    \ char c() {char c; _cin >> c; return c;}  // char\n    static vector<ll> vi(int\
    \ n) {vector<ll> v(n); rep(i, n) _cin >> v[i]; return v;}  // vector<long long>\n\
    \    static vector<pair<ll, ll>> g(int n) {vector<pair<ll, ll>> v(n); rep(i, n)\
    \ _cin >> v[i].first >> v[i].second; return v;}  // vector<pair<long long, long\
    \ long>>\n    // tuple\n    template<typename... Args> static tuple<Args...> t()\
    \ {\n        tuple<Args...> values;\n        apply([](auto&... args) { ((_cin\
    \ >> args), ...); }, values);\n        return values;\n    }\n};\n\n// debug print\
    \ utility\nnamespace deb {\n    #include <cxxabi.h>\n    // demangle type name\n\
    \    string demangle(const char* name) {\n        int status = -4;\n        unique_ptr<char,\
    \ void(*)(void*)> res{\n            abi::__cxa_demangle(name, NULL, NULL, &status),\n\
    \            free\n        };\n        return (status == 0) ? string(res.get())\
    \ : name ;\n    }\n    // meta functions for type traits\n    template<typename\
    \ T>\n    constexpr bool isArithmeticContainer() { return is_arithmetic<typename\
    \ T::value_type>::value; }\n    // for SFINAE\n    template<typename T, typename\
    \ = void> struct has_key_and_mapped_type : false_type {};\n    template<typename\
    \ T> struct has_key_and_mapped_type<T, void_t<typename T::key_type, typename T::mapped_type>>\
    \ : true_type {};\n    // for map or unordered_map\n    template<typename T>\n\
    \    constexpr bool isMapLike() { return has_key_and_mapped_type<T>::value; }\n\
    \n    // for values\n    template<typename T, typename enable_if<is_arithmetic<T>::value,\
    \ nullptr_t>::type = nullptr>\n    void p(const T& x) { cout << x << \" \"; }\n\
    \    // for pairs\n    template <typename T, typename S>\n    void p(const pair<T,\
    \ S>& _p){ p(_p.first); p(_p.second); cout << endl; }\n    // for containers\n\
    \    template<typename T,  typename enable_if<!is_arithmetic<T>::value, nullptr_t>::type\
    \ = nullptr>\n    void p(const T& container) {\n        // map and unordered_map\n\
    \        if constexpr (isMapLike<T>()) {\n            cout << demangle(typeid(T).name())\
    \ << \":\" << endl;\n            for (const auto& kv : container) {\n        \
    \        cout << \"[\" << kv.first << \"] => \";\n                p(kv.second);\n\
    \                if constexpr (is_arithmetic_v<typename T::mapped_type>) cout\
    \ << endl;\n            }\n        // vector or set or others\n        } else\
    \ {\n            if constexpr (!isArithmeticContainer<T>()) cout << demangle(typeid(T).name())\
    \ << \":\" << endl;\n            for (auto it = begin(container); it != end(container);\
    \ ++it) {\n                p(*it);\n            }\n            if constexpr (isArithmeticContainer<T>())\
    \ cout << endl;\n        }\n    }\n};  // namespace deb\n\nint main() {\n    auto&\
    \ cin = _cin;\n    // speed up io\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    // code\n    ll n = rd::i();\n    vector<vector<pair<int, int>>> graph(n);\n\
    \    rep(i, n) {\n        auto [u, k] = rd::t<int, int>();\n        rep(j, k)\
    \ {\n            auto v = rd::i();\n            graph[u - 1].emplace_back(v -\
    \ 1, 1);\n        }\n    }\n\n    auto costs = ugilib::bfs01(n, 0, graph);\n \
    \   rep(i, n) {\n        cout << i + 1 << \" \" << (costs[i] == ugilib::constants::INF<int>\
    \ ? -1 : costs[i]) << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include\
    \ \"ugilib/base/definitions.hpp\"\n#include \"ugilib/graph/bfs.hpp\"\n\nusing\
    \ namespace std;\n\n// debug settings\n// #define DEBUG\n#ifdef DEBUG\n// debug\
    \ input\nstring _INPUT = R\"(\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1));\
    \ // remove '\\n' at _INPUT[0]\n#else\n// standard input\nauto& _cin = cin;\n\
    #endif\n\n// speed up\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\n\n// reader\nstruct rd {\n    static\
    \ ll i() {ll i; _cin >> i; return i;}  // long long\n    static ld d() {ld d;\
    \ _cin >> d; return d;}  // long double\n    static string s() {string s; _cin\
    \ >> s; return s;}  // string\n    static char c() {char c; _cin >> c; return\
    \ c;}  // char\n    static vector<ll> vi(int n) {vector<ll> v(n); rep(i, n) _cin\
    \ >> v[i]; return v;}  // vector<long long>\n    static vector<pair<ll, ll>> g(int\
    \ n) {vector<pair<ll, ll>> v(n); rep(i, n) _cin >> v[i].first >> v[i].second;\
    \ return v;}  // vector<pair<long long, long long>>\n    // tuple\n    template<typename...\
    \ Args> static tuple<Args...> t() {\n        tuple<Args...> values;\n        apply([](auto&...\
    \ args) { ((_cin >> args), ...); }, values);\n        return values;\n    }\n\
    };\n\n// debug print utility\nnamespace deb {\n    #include <cxxabi.h>\n    //\
    \ demangle type name\n    string demangle(const char* name) {\n        int status\
    \ = -4;\n        unique_ptr<char, void(*)(void*)> res{\n            abi::__cxa_demangle(name,\
    \ NULL, NULL, &status),\n            free\n        };\n        return (status\
    \ == 0) ? string(res.get()) : name ;\n    }\n    // meta functions for type traits\n\
    \    template<typename T>\n    constexpr bool isArithmeticContainer() { return\
    \ is_arithmetic<typename T::value_type>::value; }\n    // for SFINAE\n    template<typename\
    \ T, typename = void> struct has_key_and_mapped_type : false_type {};\n    template<typename\
    \ T> struct has_key_and_mapped_type<T, void_t<typename T::key_type, typename T::mapped_type>>\
    \ : true_type {};\n    // for map or unordered_map\n    template<typename T>\n\
    \    constexpr bool isMapLike() { return has_key_and_mapped_type<T>::value; }\n\
    \n    // for values\n    template<typename T, typename enable_if<is_arithmetic<T>::value,\
    \ nullptr_t>::type = nullptr>\n    void p(const T& x) { cout << x << \" \"; }\n\
    \    // for pairs\n    template <typename T, typename S>\n    void p(const pair<T,\
    \ S>& _p){ p(_p.first); p(_p.second); cout << endl; }\n    // for containers\n\
    \    template<typename T,  typename enable_if<!is_arithmetic<T>::value, nullptr_t>::type\
    \ = nullptr>\n    void p(const T& container) {\n        // map and unordered_map\n\
    \        if constexpr (isMapLike<T>()) {\n            cout << demangle(typeid(T).name())\
    \ << \":\" << endl;\n            for (const auto& kv : container) {\n        \
    \        cout << \"[\" << kv.first << \"] => \";\n                p(kv.second);\n\
    \                if constexpr (is_arithmetic_v<typename T::mapped_type>) cout\
    \ << endl;\n            }\n        // vector or set or others\n        } else\
    \ {\n            if constexpr (!isArithmeticContainer<T>()) cout << demangle(typeid(T).name())\
    \ << \":\" << endl;\n            for (auto it = begin(container); it != end(container);\
    \ ++it) {\n                p(*it);\n            }\n            if constexpr (isArithmeticContainer<T>())\
    \ cout << endl;\n        }\n    }\n};  // namespace deb\n\nint main() {\n    auto&\
    \ cin = _cin;\n    // speed up io\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    // code\n    ll n = rd::i();\n    vector<vector<pair<int, int>>> graph(n);\n\
    \    rep(i, n) {\n        auto [u, k] = rd::t<int, int>();\n        rep(j, k)\
    \ {\n            auto v = rd::i();\n            graph[u - 1].emplace_back(v -\
    \ 1, 1);\n        }\n    }\n\n    auto costs = ugilib::bfs01(n, 0, graph);\n \
    \   rep(i, n) {\n        cout << i + 1 << \" \" << (costs[i] == ugilib::constants::INF<int>\
    \ ? -1 : costs[i]) << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  - ugilib/graph/bfs.hpp
  isVerificationFile: true
  path: tests/graph/bfs.test.cpp
  requiredBy: []
  timestamp: '2024-04-03 22:40:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph/bfs.test.cpp
layout: document
redirect_from:
- /verify/tests/graph/bfs.test.cpp
- /verify/tests/graph/bfs.test.cpp.html
title: tests/graph/bfs.test.cpp
---
