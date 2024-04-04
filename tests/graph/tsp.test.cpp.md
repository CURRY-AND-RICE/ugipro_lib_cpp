---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ugilib/base/constants.hpp
    title: ugilib/base/constants.hpp
  - icon: ':question:'
    path: ugilib/base/definitions.hpp
    title: ugilib/base/definitions.hpp
  - icon: ':heavy_check_mark:'
    path: ugilib/bit/bit_util.hpp
    title: "\u6570\u5024 -> \u30D3\u30C3\u30C8\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: ugilib/graph/tsp.hpp
    title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\u3092\u89E3\
      \u304FDP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"tests/graph/tsp.test.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\n#define rep(i, n) for(size_t i = 0; i <\
    \ n; i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n#line\
    \ 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants {\n    template<typename\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / 2;\n} // namespace\
    \ ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"\
    ugilib/bit/bit_util.hpp\"\n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n\
    \     * @brief \u6570\u5024 -> \u30D3\u30C3\u30C8\u914D\u5217\n     * @param num\
    \ \u30D3\u30C3\u30C8\u914D\u5217\u306B\u3059\u308B\u305F\u3081\u306E\u6570\u5024\
    \n     * @param digit \u30D3\u30C3\u30C8\u6570\n     * @return vector<bool> \u5909\
    \u63DB\u3055\u308C\u305F\u30D3\u30C3\u30C8\u914D\u5217. 0\u756A\u76EE\u304C\u4E00\
    \u756A\u4E0B\u306E\u6841\n     * @details \u6570\u5024\u3092\u6307\u5B9A\u6841\
    \u306E\u30D3\u30C3\u30C8\u914D\u5217\u306B\u5909\u63DB\u3059\u308B\n    */\n \
    \   vector<bool> num_to_bits(const ll num, const size_t &digit) {\n        vector<bool>\
    \ bits(digit);\n        for (int i = 0; i < digit; i++) {\n            bits[i]\
    \ = (num >> i) & 1U;\n        }\n        return bits;\n    }\n\n    /**\n    \
    \ * @brief \u30D3\u30C3\u30C8\u914D\u5217 -> \u6570\u5024\n     * @param bits\
    \ \u6570\u5024\u306B\u3059\u308B\u305F\u3081\u306E\u30D3\u30C3\u30C8\u914D\u5217\
    . 0\u756A\u76EE\u304C\u4E00\u756A\u4E0B\u306E\u6841\n     * @return ll \u5909\u63DB\
    \u3055\u308C\u305F\u6570\u5024\n     * @details \u30D3\u30C3\u30C8\u914D\u5217\
    \u3092\u6570\u5024\u306B\u623B\u3059. num_to_bits\u306E\u9006\u5909\u63DB\n  \
    \  */\n    ll bits_to_num(const vector<bool> &bits) {\n        ll num = 0;\n \
    \       for (int i = 0; i < bits.size(); i++) {\n            num += bits[i] <<\
    \ i;\n        }\n        return num;\n    }\n}  // namespace ugilib\n#line 5 \"\
    ugilib/graph/tsp.hpp\"\n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n\
    \     * @brief \u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\u3092\
    \u89E3\u304FDP\n     * @param n \u90FD\u5E02\u6570\n     * @param start \u59CB\
    \u70B9\n     * @param graph \u30B0\u30E9\u30D5. vector<pair<int, weight_t>> \u3067\
    \u96A3\u63A5\u9802\u70B9\u3068\u30B3\u30B9\u30C8\u3092\u8868\u3059\n     * @param\
    \ weight_inf \u7121\u9650\u5927\u306E\u5024. \u30D1\u30B9\u304C\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306E\u30B3\u30B9\u30C8\n     * @return \u59CB\u70B9\u304B\
    \u3089\u5404\u9802\u70B9\u3092\u4E00\u5EA6\u3060\u3051\u901A\u3063\u3066\u623B\
    \u3063\u3066\u304F\u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n     * @note O(2^n * n^2)\n\
    \    */\n    template <typename weight_t>\n    weight_t tsp_bitDP(int n, int start,\
    \ const vector<vector<pair<int, weight_t>>> &graph, const weight_t weight_inf\
    \ = ugilib::constants::INF<weight_t>) {\n        const int num_states = (1 <<\
    \ n);\n        // dp[\u3053\u308C\u307E\u3067\u306B\u53D6\u3063\u305F\u90FD\u5E02\
    \u96C6\u5408. [0, 2^n-1]][\u73FE\u5728\u5730. [0, n-1]]\n        vector<vector<weight_t>>\
    \ dp(num_states, vector<weight_t>(n, weight_inf));\n        dp[0][start] = 0;\n\
    \n        // \u5168\u72B6\u614B\u306B\u3064\u3044\u3066DP\u3059\u308B\n      \
    \  for (int i = 0; i < num_states; i++) {\n            // \u72B6\u614B\u3092\u30D3\
    \u30C3\u30C8\u8868\u73FE\u3059\u308B\n            auto bits = ugilib::num_to_bits(i,\
    \ n);\n            // \u4ECA\u3069\u306E\u90FD\u5E02\u306B\u3044\u308B\u304B\n\
    \            for (int j = 0; j < n; j++) {\n                if (dp[i][j] == weight_inf)\
    \ continue;  // \u3053\u306E\u72B6\u614B\u306B\u8FBF\u308A\u7740\u304B\u306A\u3044\
    \u5834\u5408\n                // \u6B21\u3069\u306E\u90FD\u5E02\u306B\u884C\u304F\
    \u304B\n                for (const auto [node, cost] : graph[j]) {\n         \
    \           if (bits[node]) continue;  // \u8A2A\u554F\u6E08\u307F\n         \
    \           // \u8A2A\u554F\u3059\u308B\n                    bits[node] = true;\n\
    \                    auto &dest = dp[ugilib::bits_to_num(bits)][node];\n     \
    \               dest = min(dest, dp[i][j] + cost);\n                    bits[node]\
    \ = false;\n                }\n            }\n        }\n\n        return dp[num_states-1][start];\
    \  // \u5168\u72B6\u614B\u8A2A\u554F\u5F8C\u306Bstart\u306B\u623B\u3063\u3066\u6765\
    \u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n    }\n    }  // namespace ugilib\n#line\
    \ 5 \"tests/graph/tsp.test.cpp\"\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
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
    \n    // code\n    auto [V, E] = rd::t<int, int>();\n    vector<vector<pair<int,\
    \ int>>> graph(V);\n    rep(i, E) {\n        auto [s, t, d] = rd::t<int, int,\
    \ int>();\n        graph[s].emplace_back(t, d);\n    }\n\n    int ans = ugilib::tsp_bitDP(V,\
    \ 0, graph, ugilib::constants::INF<int>);\n    // \u3069\u3053\u3092\u59CB\u70B9\
    \u306B\u3057\u3066\u3082\u7D50\u679C\u306F\u540C\u3058\n    for (int i = 1; i\
    \ < V; i++) {\n        int another_ans = ugilib::tsp_bitDP(V, i, graph);\n   \
    \     assert(ans == another_ans);\n    }\n\n    if (ans == ugilib::constants::INF<int>)\
    \ cout << -1 << endl;\n    else cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include\
    \ \"ugilib/base/definitions.hpp\"\n#include \"ugilib/graph/tsp.hpp\"\n\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
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
    \n    // code\n    auto [V, E] = rd::t<int, int>();\n    vector<vector<pair<int,\
    \ int>>> graph(V);\n    rep(i, E) {\n        auto [s, t, d] = rd::t<int, int,\
    \ int>();\n        graph[s].emplace_back(t, d);\n    }\n\n    int ans = ugilib::tsp_bitDP(V,\
    \ 0, graph, ugilib::constants::INF<int>);\n    // \u3069\u3053\u3092\u59CB\u70B9\
    \u306B\u3057\u3066\u3082\u7D50\u679C\u306F\u540C\u3058\n    for (int i = 1; i\
    \ < V; i++) {\n        int another_ans = ugilib::tsp_bitDP(V, i, graph);\n   \
    \     assert(ans == another_ans);\n    }\n\n    if (ans == ugilib::constants::INF<int>)\
    \ cout << -1 << endl;\n    else cout << ans << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  - ugilib/graph/tsp.hpp
  - ugilib/bit/bit_util.hpp
  isVerificationFile: true
  path: tests/graph/tsp.test.cpp
  requiredBy: []
  timestamp: '2024-04-03 22:46:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph/tsp.test.cpp
layout: document
redirect_from:
- /verify/tests/graph/tsp.test.cpp
- /verify/tests/graph/tsp.test.cpp.html
title: tests/graph/tsp.test.cpp
---
