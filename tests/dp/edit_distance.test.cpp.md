---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E
  bundledCode: "#line 1 \"tests/dp/edit_distance.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"ugilib/dp/edit_distance.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u7DE8\u96C6\
    \u8DDD\u96E2\n     * @tparam T vector\u306E\u8981\u7D20\u306E\u578B. string\u3060\
    \u3063\u305F\u3089vector<char>\u3067\u6E21\u3059\n     * @param v1 vector1\n \
    \    * @param v2 vector2\n     * @return vector<vector<ll>> dp[i][j]: v1\u306E\
    i\u6587\u5B57\u76EE\u307E\u3067\u3068v2\u306Ej\u6587\u5B57\u76EE\u307E\u3067\u306E\
    \u7DE8\u96C6\u8DDD\u96E2\n     * @note O(nm). n = v1.size(), m = v2.size()\n \
    \    * @details\n     * auto dp = edit_distance(v1, v2);\n     * cout << dp[v1.size()][v2.size()]\
    \ << endl;\n     * cout << dp.back().back() << endl;\n    */\n    template <typename\
    \ T>\n    vector<vector<ll>> edit_distance(const vector<T>& v1, const vector<T>&\
    \ v2) {\n        int n = v1.size();\n        int m = v2.size();\n        // dp[i][j]:\
    \ v1\u306Ei\u6587\u5B57\u76EE\u307E\u3067\u3068v2\u306Ej\u6587\u5B57\u76EE\u307E\
    \u3067\u306E\u7DE8\u96C6\u8DDD\u96E2\n        vector<vector<ll>> dp(n+1, vector<ll>(m+1,\
    \ INF));\n\n        // \u7A7A\u6587\u5B57\u5217\u3068\u306E\u7DE8\u96C6\u8DDD\u96E2\
    \n        for (int i = 0; i <= n; i++) dp[i][0] = i;\n        for (int j = 0;\
    \ j <= m; j++) dp[0][j] = j;\n\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                dp[i+1][j+1] = min(dp[i][j+1]\
    \ + 1, dp[i+1][j] + 1);  // v1 or v2\u3069\u3061\u3089\u304B1\u6587\u5B57\u8FFD\
    \u52A0\n                if (v1[i] == v2[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);\
    \  // v1 and v2\u4E21\u65B9\u304B\u30891\u6587\u5B57\u8FFD\u52A0\n           \
    \     else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 1);  // v1 and v2\u4E21\
    \u65B9\u304B\u30891\u6587\u5B57\u8FFD\u52A0\u3057, \u7247\u65B9\u3092\u5909\u66F4\
    \u3059\u308B\n            }\n        }\n\n        return dp;\n    }\n}  // namespace\
    \ ugilib\n#line 7 \"tests/dp/edit_distance.test.cpp\"\n\nusing namespace std;\n\
    \n// debug settings\n// #define DEBUG\n#ifdef DEBUG\n// debug input\nstring _INPUT\
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
    \n    // code\n    string s1 = rd::i<string>();\n    string s2 = rd::i<string>();\n\
    \n    vector<char> v1(all(s1)), v2(all(s2));\n    auto dp = ugilib::edit_distance(v1,\
    \ v2);\n    cout << dp.back().back() << endl;\n\n    // deb::p(dp);\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E\"\n\n\
    #include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include \"\
    ugilib/base/definitions.hpp\"\n#include \"ugilib/dp/edit_distance.hpp\"\n\nusing\
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
    \n    // code\n    string s1 = rd::i<string>();\n    string s2 = rd::i<string>();\n\
    \n    vector<char> v1(all(s1)), v2(all(s2));\n    auto dp = ugilib::edit_distance(v1,\
    \ v2);\n    cout << dp.back().back() << endl;\n\n    // deb::p(dp);\n\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/dp/edit_distance.test.cpp
  requiredBy: []
  timestamp: '2024-04-03 18:17:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dp/edit_distance.test.cpp
layout: document
redirect_from:
- /verify/tests/dp/edit_distance.test.cpp
- /verify/tests/dp/edit_distance.test.cpp.html
title: tests/dp/edit_distance.test.cpp
---
