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
    path: ugilib/geometry/rectangle_overlap.hpp
    title: "\u4E8C\u3064\u306E\u9577\u65B9\u5F62\u306E\u91CD\u306A\u308A\u3092\u5224\
      \u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0059
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0059
  bundledCode: "#line 1 \"tests/geometry/rectangle_overlap.test.cpp\"\n// this problem\
    \ is not available for download\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0059\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(int i = 0; i < (int)(n); i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 4;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"ugilib/geometry/rectangle_overlap.hpp\"\
    \n\nnamespace ugilib {\n    /**\n     * @brief \u4E8C\u3064\u306E\u9577\u65B9\u5F62\
    \u306E\u91CD\u306A\u308A\u3092\u5224\u5B9A\n     * @param a \u9577\u65B9\u5F62\
    1\u306E\u5EA7\u6A19 (ymin, xmin, ymax, xmax)\n     * @param b \u9577\u65B9\u5F62\
    2\u306E\u5EA7\u6A19 (ymin, xmin, ymax, xmax)\n     * @return \u91CD\u306A\u3063\
    \u3066\u3044\u308B\u304B\u3069\u3046\u304B. \u70B9\u3067\u63A5\u3057\u3066\u3044\
    \u308B\u5834\u5408\u3082true\n     * @details 4\u3064\u306E\u5EA7\u6A19\u306F\u9589\
    \u533A\u9593\u3067\u8868\u3059. \u3064\u307E\u308A\uFF0C(ymin, xmin)\u3082(ymax,\
    \ xmax)\u3082\u9577\u65B9\u5F62\u306B\u542B\u307E\u308C\u308B\n    */\n    template\
    \ <typename T>\n    bool is_overlapping(const std::array<T, 4> &a, const std::array<T,\
    \ 4> &b) {\n        auto [ymin1, xmin1, ymax1, xmax1] = a;\n        auto [ymin2,\
    \ xmin2, ymax2, xmax2] = b;\n        return (xmin1 <= xmax2 && xmax1 >= xmin2\
    \ && ymin1 <= ymax2 && ymax1 >= ymin2);\n    }\n} // namespace ugilib\n#line 8\
    \ \"tests/geometry/rectangle_overlap.test.cpp\"\n\nusing namespace std;\n\n//\
    \ debug settings\n// #define DEBUG\n#ifdef DEBUG\n// debug input\nstring _INPUT\
    \ = R\"(\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1)); // remove\
    \ '\\n' at _INPUT[0]\n#else\n// standard input\nauto& _cin = cin;\n#endif\n\n\
    // speed up\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma\
    \ GCC optimize(\"unroll-loops\")\n\n// reader\nstruct rd {\n    // T\n    template<typename\
    \ T> static T i() { T x; _cin >> x; return x; }  // T item\n    // vector<T>\n\
    \    template<typename T> static vector<T> v(int n) {vector<T> v(n); rep(i, n)\
    \ _cin >> v[i]; return v;}  // vector<T>\n    // array<T, N>\n    template<typename\
    \ T, size_t N> static array<T, N> a() {array<T, N> a; rep(i, N) _cin >> a[i];\
    \ return a;}  // array<T, N>\n    // vector<pair<T, T>>\n    template<typename\
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
    \ cout << endl; }\n    // for containers\n    template<typename T,  typename enable_if<!is_arithmetic<T>::value,\
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
    \n    // code\n    // checked by submitting by myself\n    cout << \"/* Test case\
    \ #1 for problem 0059 is not available. */\";\n    exit(0);\n\n    array<ld, 4>\
    \ a, b;\n    ld temp;\n    while (cin >> temp) {\n        a[0] = temp;\n     \
    \   rep(i, 3) cin >> a[i + 1];\n        rep(i, 4) cin >> b[i];\n\n        cout\
    \ << (ugilib::is_overlapping(a, b) ? \"YES\" : \"NO\") << endl;\n    }\n\n   \
    \ return 0;\n}\n"
  code: "// this problem is not available for download\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0059\"\
    \n\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include\
    \ \"ugilib/base/definitions.hpp\"\n#include \"ugilib/geometry/rectangle_overlap.hpp\"\
    \n\nusing namespace std;\n\n// debug settings\n// #define DEBUG\n#ifdef DEBUG\n\
    // debug input\nstring _INPUT = R\"(\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1));\
    \ // remove '\\n' at _INPUT[0]\n#else\n// standard input\nauto& _cin = cin;\n\
    #endif\n\n// speed up\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\n\n// reader\nstruct rd {\n    // T\n\
    \    template<typename T> static T i() { T x; _cin >> x; return x; }  // T item\n\
    \    // vector<T>\n    template<typename T> static vector<T> v(int n) {vector<T>\
    \ v(n); rep(i, n) _cin >> v[i]; return v;}  // vector<T>\n    // array<T, N>\n\
    \    template<typename T, size_t N> static array<T, N> a() {array<T, N> a; rep(i,\
    \ N) _cin >> a[i]; return a;}  // array<T, N>\n    // vector<pair<T, T>>\n   \
    \ template<typename T> static vector<pair<T, T>> vp(int n) {vector<pair<T, T>>\
    \ v(n); rep(i, n) _cin >> v[i].first >> v[i].second; return v;}  // vector<pair<T,\
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
    \n    // code\n    // checked by submitting by myself\n    cout << \"/* Test case\
    \ #1 for problem 0059 is not available. */\";\n    exit(0);\n\n    array<ld, 4>\
    \ a, b;\n    ld temp;\n    while (cin >> temp) {\n        a[0] = temp;\n     \
    \   rep(i, 3) cin >> a[i + 1];\n        rep(i, 4) cin >> b[i];\n\n        cout\
    \ << (ugilib::is_overlapping(a, b) ? \"YES\" : \"NO\") << endl;\n    }\n\n   \
    \ return 0;\n}\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  - ugilib/geometry/rectangle_overlap.hpp
  isVerificationFile: true
  path: tests/geometry/rectangle_overlap.test.cpp
  requiredBy: []
  timestamp: '2024-03-31 15:45:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/geometry/rectangle_overlap.test.cpp
layout: document
redirect_from:
- /verify/tests/geometry/rectangle_overlap.test.cpp
- /verify/tests/geometry/rectangle_overlap.test.cpp.html
title: tests/geometry/rectangle_overlap.test.cpp
---
