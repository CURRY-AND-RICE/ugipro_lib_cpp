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
    path: ugilib/iteration/all_combinations.hpp
    title: "num_items\u500B\u306E\u4E2D\u304B\u3089num_pick\u500B\u9078\u3076\u7D44\
      \u307F\u5408\u308F\u305B\u3092\u5168\u63A2\u7D22\u3057, \u305D\u308C\u305E\u308C\
      \u306B\u5BFE\u3057\u3066\u95A2\u6570f\u3092\u5B9F\u884C\u3059\u308B"
  - icon: ':heavy_check_mark:'
    path: ugilib/iteration/next_combination.hpp
    title: "\u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u751F\u6210\u3059\u308B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_B
  bundledCode: "#line 1 \"tests/iteration/combinations.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_B\"\n\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(int i =\
    \ 0; i < (int)(n); i++)  // rep macro\n#define all(v) begin(v), end(v)  // all\
    \ iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants\
    \ {\n    template<typename T>\n    inline constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n} // namespace ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n\
    #line 4 \"ugilib/iteration/next_combination.hpp\"\n\nusing namespace std;\n\n\
    namespace ugilib {\n    /**\n     * @brief \u6B21\u306E\u7D44\u307F\u5408\u308F\
    \u305B\u3092\u751F\u6210\u3059\u308B\n     * @param indices \u73FE\u5728\u306E\
    \u7D44\u307F\u5408\u308F\u305B\n     * @param num_items \u5168\u4F53\u306E\u8981\
    \u7D20\u6570\n     * @return bool \u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u304C\
    \u5B58\u5728\u3059\u308B\u304B\u3069\u3046\u304B\n     * @details \u4F8B\u3048\
    \u3070, indices = {0, 1, 2}, num_items = 5\u306E\u5834\u5408, \u6B21\u306E\u7D44\
    \u307F\u5408\u308F\u305B\u306F{0, 1, 3}\u3068\u306A\u308B\n     * @details \u3053\
    \u308C\u3092\u30E9\u30C3\u30D7\u3057\u305F\u3082\u306E\u304Cexec_all_combination\n\
    \    */\n    bool next_combination(vector<size_t> &indices, const size_t &num_items)\
    \ {\n        const int num_pick = indices.size();\n        for (signed i = num_pick\
    \ - 1; i >= 0; i--) {\n            if (indices[i] < num_items - num_pick + i)\
    \ {\n                indices[i]++;\n                for (size_t j = i + 1; j <\
    \ num_pick; j++) {\n                    indices[j] = indices[j - 1] + 1;\n   \
    \             }\n                return true;\n            }\n        }\n    \
    \    return false;\n    }\n} // namespace ugilib\n#line 5 \"ugilib/iteration/all_combinations.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief num_items\u500B\
    \u306E\u4E2D\u304B\u3089num_pick\u500B\u9078\u3076\u7D44\u307F\u5408\u308F\u305B\
    \u3092\u5168\u63A2\u7D22\u3057, \u305D\u308C\u305E\u308C\u306B\u5BFE\u3057\u3066\
    \u95A2\u6570f\u3092\u5B9F\u884C\u3059\u308B\n     * @tparam Func \u30E9\u30E0\u30C0\
    \u5F0F\n     * @param num_items \u9078\u629E\u5BFE\u8C61\u5168\u4F53\u306E\u8981\
    \u7D20\u6570\n     * @param num_pick \u9078\u629E\u3059\u308B\u8981\u7D20\u6570\
    \n     * @param f \u5B9F\u884C\u3059\u308B\u95A2\u6570. true\u3092\u8FD4\u3059\
    \u3068\u63A2\u7D22\u3092\u6253\u3061\u5207\u308B\n     * @details \u30E9\u30E0\
    \u30C0\u5F0F\u306B\u306F\u9078\u629E\u3057\u305F\u8981\u7D20\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\u304C\u6607\u9806\u3067\u6E21\u3055\u308C\u308B\n   \
    \  * @example\n     * auto f = [&](const vector<size_t> &indices) {\n     *  \
    \  for (const auto &i : indices) {\n     *       cout << i << \" \";\n     * \
    \  }\n     *  cout << endl;\n     * return false;\n     * };\n     * exec_all_combination(5,\
    \ 3, f);\n    */\n    template <typename Func>\n    void exec_all_combinations(const\
    \ size_t &num_items, const size_t &num_pick, Func f) {\n        vector<size_t>\
    \ indices(num_pick);\n        iota(indices.begin(), indices.end(), 0);\n     \
    \   do {\n            bool will_break = f(indices);\n            if (will_break)\
    \ break;\n        } while (next_combination(indices, num_items));\n    }\n}  //\
    \ namespace ugilib\n#line 7 \"tests/iteration/combinations.test.cpp\"\n\nusing\
    \ namespace std;\n\n// debug settings\n// #define DEBUG\n#ifdef DEBUG\n// debug\
    \ input\nstring _INPUT = R\"(\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1));\
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
    \n    // code\n    while (true) {\n        auto [n, x] = rd::t<int, int>();\n\
    \        if (n == x && x == 0) break;\n\n        int ans = 0;\n        auto f\
    \ = [&](const vector<size_t> &indices) {\n            int y = 0;\n           \
    \ for (const auto i : indices) y += i+1;  // [0, n-1]\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u304C\u6E21\u3055\u308C\u308B\u306E\u3067\uFF0C\u305D\u308C\u305E\
    \u308C1\u3092\u8DB3\u3057\u3066[1, n]\u306B\u3059\u308B\n            if (y ==\
    \ x) ans += 1;\n            return false;\n        };\n        ugilib::exec_all_combinations(n,\
    \ 3, f);\n        cout << ans << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_B\"\n\n\
    #include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include \"\
    ugilib/base/definitions.hpp\"\n#include \"ugilib/iteration/all_combinations.hpp\"\
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
    \n    // code\n    while (true) {\n        auto [n, x] = rd::t<int, int>();\n\
    \        if (n == x && x == 0) break;\n\n        int ans = 0;\n        auto f\
    \ = [&](const vector<size_t> &indices) {\n            int y = 0;\n           \
    \ for (const auto i : indices) y += i+1;  // [0, n-1]\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u304C\u6E21\u3055\u308C\u308B\u306E\u3067\uFF0C\u305D\u308C\u305E\
    \u308C1\u3092\u8DB3\u3057\u3066[1, n]\u306B\u3059\u308B\n            if (y ==\
    \ x) ans += 1;\n            return false;\n        };\n        ugilib::exec_all_combinations(n,\
    \ 3, f);\n        cout << ans << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  - ugilib/iteration/all_combinations.hpp
  - ugilib/iteration/next_combination.hpp
  isVerificationFile: true
  path: tests/iteration/combinations.test.cpp
  requiredBy: []
  timestamp: '2024-04-03 22:40:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/iteration/combinations.test.cpp
layout: document
redirect_from:
- /verify/tests/iteration/combinations.test.cpp
- /verify/tests/iteration/combinations.test.cpp.html
title: tests/iteration/combinations.test.cpp
---
