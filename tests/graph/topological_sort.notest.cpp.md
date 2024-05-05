---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B
  bundledCode: "#line 1 \"tests/graph/topological_sort.notest.cpp\"\n// \u7D50\u679C\
    \u304C\u4E00\u610F\u3067\u306A\u3044\u305F\u3081\u3001\u30C6\u30B9\u30C8\u306F\
    \u884C\u308F\u306A\u3044\n// #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 2 \"ugilib/graph/topological_sort.hpp\"\
    \n\n/**\n * @file topological_sort.hpp\n * @brief \u30C8\u30DD\u30ED\u30B8\u30AB\
    \u30EB\u30BD\u30FC\u30C8\uFF0C\u5165\u6B21\u6570\u8A08\u7B97\u95A2\u6570\u306E\
    \u5B9A\u7FA9\n*/\n\n#line 9 \"ugilib/graph/topological_sort.hpp\"\nusing namespace\
    \ std;\n\nnamespace ugilib {\n    /**\n     * @brief DAG\u306E\u5404\u9802\u70B9\
    \u306E\u5165\u6B21\u6570\u3092\u8A08\u7B97\u3059\u308B\n     * @tparam T \u6574\
    \u6570\u578B\n     * @param g \u6709\u5411\u30B0\u30E9\u30D5\n     * @return vector<T>\
    \ \u5165\u6B21\u6570\u30EA\u30B9\u30C8\n     * @note O(V + E)\n     */\n    template\
    \ <typename T>\n    vector<T> calc_indegrees(const vector<vector<T>> &g) {\n \
    \       static_assert(is_integral<T>::value, \"T must be integral type\");\n \
    \       vector<T> indeg(g.size(), 0);\n        for (const vector<T> &edges_from_u\
    \ : g) {\n            for (const T &v : edges_from_u) {\n                indeg[v]++;\n\
    \            }\n        }\n        return indeg;\n    }\n\n    /**\n     * @brief\
    \ DAG\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n     * @tparam\
    \ T \u6574\u6570\u578B\n     * @param g DAG\n     * @return vector<T> \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u7D50\u679C\n     * @note O(V + E)\n\
    \    */\n    template <typename T>\n    vector<T> topological_sort(const vector<vector<T>>\
    \ &g) {\n        static_assert(is_integral<T>::value, \"T must be integral type\"\
    );\n        // \u5165\u6B21\u6570\u306E\u8A08\u7B97\n        vector<T> indegs\
    \ = ugilib::calc_indegrees(g);\n\n        // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u9806\u5E8F\u3092\u6C7A\u5B9A\u3059\u308B\n        vector<T> topology;\n    \
    \    queue<T> start_nodes;\n        for (size_t i = 0; i < indegs.size(); i++)\
    \ {\n            if (indegs[i] == 0) start_nodes.push(i);\n        }\n       \
    \ while (!start_nodes.empty()) {\n            // \u5165\u6B21\u65700\u306E\u9802\
    \u70B9\u306E\u9806\u5E8F\u3092\u78BA\u5B9A\n            T node = start_nodes.front();\
    \ start_nodes.pop();\n            topology.push_back(node);\n\n            //\
    \ \u9802\u70B9\u30FB\u8FBA\u3092\u524A\u9664\u3059\u308B\n            for (const\
    \ T &next : g[node]) {  // \u3053\u306E\u9802\u70B9\u304B\u3089\u51FA\u308B\u5168\
    \u3066\u306E\u8FBA\u3092\u524A\u9664\n                if (--indegs[next] == 0)\
    \ {  // \u305D\u308C\u306B\u3088\u3063\u3066\u5165\u6B21\u6570\u304C0\u306B\u306A\
    \u3063\u305F\u3089\n                    start_nodes.push(next);  // \u9806\u5E8F\
    \u3092\u78BA\u5B9A\u3067\u304D\u308B\n                }\n            }\n     \
    \   }\n\n        assert(topology.size() == g.size());  // DAG\u3067\u306A\u3044\
    \u5834\u5408\u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3067\
    \u304D\u306A\u3044\n        return topology;\n    }\n}  // namespace ugilib\n\
    #line 8 \"tests/graph/topological_sort.notest.cpp\"\n\nusing namespace std;\n\n\
    // debug settings\n// #define DEBUG\n#ifdef DEBUG\n// debug input\nstring _INPUT\
    \ = R\"(\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1)); // remove\
    \ '\\n' at _INPUT[0]\n#else\n// standard input\nauto& _cin = cin;\n#endif\n\n\
    // speed up\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma\
    \ GCC optimize(\"unroll-loops\")\n\n// reader\nstruct rd {\n    // T\n    template<typename\
    \ T> static T i() { T x; _cin >> x; return x; }  // T item\n    // vector<T>\n\
    \    template<typename T> static vector<T> v(int n) {vector<T> v(n); rep(i, n)\
    \ _cin >> v[i]; return v;}  // vector<T>\n    // vector<pair<T, T>>\n    template<typename\
    \ T> static vector<pair<T, T>> vp(int n) {vector<pair<T, T>> v(n); rep(i, n) _cin\
    \ >> v[i].first >> v[i].second; return v;}  // vector<pair<T, T>>\n    // tuple\n\
    \    template<typename... Args> static tuple<Args...> t() {\n        tuple<Args...>\
    \ values;\n        apply([](auto&... args) { ((_cin >> args), ...); }, values);\n\
    \        return values;\n    }\n};\n\n// debug print utility\nnamespace deb {\n\
    \    #include <cxxabi.h>\n    // demangle type name\n    string demangle(const\
    \ char* name) {\n        int status = -4;\n        unique_ptr<char, void(*)(void*)>\
    \ res{\n            abi::__cxa_demangle(name, NULL, NULL, &status),\n        \
    \    free\n        };\n        return (status == 0) ? string(res.get()) : name\
    \ ;\n    }\n    // meta functions for type traits\n    template<typename T>\n\
    \    constexpr bool isArithmeticContainer() { return is_arithmetic<typename T::value_type>::value;\
    \ }\n    // for SFINAE\n    template<typename T, typename = void> struct has_key_and_mapped_type\
    \ : false_type {};\n    template<typename T> struct has_key_and_mapped_type<T,\
    \ void_t<typename T::key_type, typename T::mapped_type>> : true_type {};\n   \
    \ // for map or unordered_map\n    template<typename T>\n    constexpr bool isMapLike()\
    \ { return has_key_and_mapped_type<T>::value; }\n\n    // for values\n    template<typename\
    \ T, typename enable_if<is_arithmetic<T>::value, nullptr_t>::type = nullptr>\n\
    \    void p(const T& x) { cout << x << \" \"; }\n    // for pairs\n    template\
    \ <typename T, typename S>\n    void p(const pair<T, S>& _p){ p(_p.first); p(_p.second);\
    \ cout << endl; }\n    // for string\n    void p(const string& s) { cout << s\
    \ << endl; }\n    // for containers\n    template<typename T,  typename enable_if<!is_arithmetic<T>::value,\
    \ nullptr_t>::type = nullptr>\n    void p(const T& container) {\n        // map\
    \ and unordered_map\n        if constexpr (isMapLike<T>()) {\n            cout\
    \ << demangle(typeid(T).name()) << \":\" << endl;\n            for (const auto&\
    \ kv : container) {\n                cout << \"[\" << kv.first << \"] => \";\n\
    \                p(kv.second);\n                if constexpr (is_arithmetic_v<typename\
    \ T::mapped_type>) cout << endl;\n            }\n        // vector or set or others\n\
    \        } else {\n            if constexpr (!isArithmeticContainer<T>()) cout\
    \ << demangle(typeid(T).name()) << \":\" << endl;\n            for (auto it =\
    \ begin(container); it != end(container); ++it) {\n                p(*it);\n \
    \           }\n            if constexpr (isArithmeticContainer<T>()) cout << endl;\n\
    \        }\n    }\n};  // namespace deb\n\nint main() {\n    auto& cin = _cin;\n\
    \    // speed up io\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    // code\n    auto [N, M] = rd::t<ll, ll>();\n    vector<vector<int>> g(N);\n\
    \    rep(i, M) {\n        auto [x, y] = rd::t<int, int>();\n        g[x].push_back(y);\n\
    \    }\n\n    vector<int> topology = ugilib::topological_sort(g);\n    for (int\
    \ node : topology) cout << node << endl;\n\n    return 0;\n}\n"
  code: "// \u7D50\u679C\u304C\u4E00\u610F\u3067\u306A\u3044\u305F\u3081\u3001\u30C6\
    \u30B9\u30C8\u306F\u884C\u308F\u306A\u3044\n// #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B\"\
    \n\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include\
    \ \"ugilib/base/definitions.hpp\"\n#include \"ugilib/graph/topological_sort.hpp\"\
    \n\nusing namespace std;\n\n// debug settings\n// #define DEBUG\n#ifdef DEBUG\n\
    // debug input\nstring _INPUT = R\"(\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1));\
    \ // remove '\\n' at _INPUT[0]\n#else\n// standard input\nauto& _cin = cin;\n\
    #endif\n\n// speed up\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\n\n// reader\nstruct rd {\n    // T\n\
    \    template<typename T> static T i() { T x; _cin >> x; return x; }  // T item\n\
    \    // vector<T>\n    template<typename T> static vector<T> v(int n) {vector<T>\
    \ v(n); rep(i, n) _cin >> v[i]; return v;}  // vector<T>\n    // vector<pair<T,\
    \ T>>\n    template<typename T> static vector<pair<T, T>> vp(int n) {vector<pair<T,\
    \ T>> v(n); rep(i, n) _cin >> v[i].first >> v[i].second; return v;}  // vector<pair<T,\
    \ T>>\n    // tuple\n    template<typename... Args> static tuple<Args...> t()\
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
    \ S>& _p){ p(_p.first); p(_p.second); cout << endl; }\n    // for string\n   \
    \ void p(const string& s) { cout << s << endl; }\n    // for containers\n    template<typename\
    \ T,  typename enable_if<!is_arithmetic<T>::value, nullptr_t>::type = nullptr>\n\
    \    void p(const T& container) {\n        // map and unordered_map\n        if\
    \ constexpr (isMapLike<T>()) {\n            cout << demangle(typeid(T).name())\
    \ << \":\" << endl;\n            for (const auto& kv : container) {\n        \
    \        cout << \"[\" << kv.first << \"] => \";\n                p(kv.second);\n\
    \                if constexpr (is_arithmetic_v<typename T::mapped_type>) cout\
    \ << endl;\n            }\n        // vector or set or others\n        } else\
    \ {\n            if constexpr (!isArithmeticContainer<T>()) cout << demangle(typeid(T).name())\
    \ << \":\" << endl;\n            for (auto it = begin(container); it != end(container);\
    \ ++it) {\n                p(*it);\n            }\n            if constexpr (isArithmeticContainer<T>())\
    \ cout << endl;\n        }\n    }\n};  // namespace deb\n\nint main() {\n    auto&\
    \ cin = _cin;\n    // speed up io\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    // code\n    auto [N, M] = rd::t<ll, ll>();\n    vector<vector<int>> g(N);\n\
    \    rep(i, M) {\n        auto [x, y] = rd::t<int, int>();\n        g[x].push_back(y);\n\
    \    }\n\n    vector<int> topology = ugilib::topological_sort(g);\n    for (int\
    \ node : topology) cout << node << endl;\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tests/graph/topological_sort.notest.cpp
  requiredBy: []
  timestamp: '2024-04-04 16:06:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/graph/topological_sort.notest.cpp
layout: document
redirect_from:
- /library/tests/graph/topological_sort.notest.cpp
- /library/tests/graph/topological_sort.notest.cpp.html
title: tests/graph/topological_sort.notest.cpp
---
