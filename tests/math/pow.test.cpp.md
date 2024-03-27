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
    path: ugilib/math/pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
  bundledCode: "#line 1 \"tests/math/pow.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(int i = 0; i < (int)(n); i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 4;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"ugilib/math/pow.hpp\"\n\
    \nnamespace ugilib {\n/**\n * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\
    \n * @param x \u57FA\u6570\n * @param n \u6307\u6570\n * @param mod mod\n * @return\
    \ x^n % mod\n * @note O(log n)\n*/\ntemplate <typename T>\nT fast_pow(T x, ll\
    \ n, T mod = ugilib::constants::INF<T>) {\n    assert(n >= 0);\n    T res = 1;\n\
    \    while (n) {\n        if (n & 1) res = res*x % mod;\n        x = x*x % mod;\n\
    \        n >>= 1;\n    }\n    return res;\n}\n}  // namespace ugilib\n#line 7\
    \ \"tests/math/pow.test.cpp\"\n\nusing namespace std;\n\n// debug settings\n//\
    \ #define DEBUG\n#ifdef DEBUG\n// debug input\nstring _INPUT = R\"(\n5\n1 2 3\
    \ 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1)); // remove '\\n' at _INPUT[0]\n\
    #else\n// standard input\nauto& _cin = cin;\n#endif\n\n// speed up\n#pragma GCC\
    \ target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n// reader\nstruct rd {\n    // T\n    template<typename T> static T i() {\
    \ T x; _cin >> x; return x; }  // T item\n    // vector<T>\n    template<typename\
    \ T> static vector<T> v(int n) {vector<T> v(n); rep(i, n) _cin >> v[i]; return\
    \ v;}  // vector<T>\n    // vector<pair<T, T>>\n    template<typename T> static\
    \ vector<pair<T, T>> vp(int n) {vector<pair<T, T>> v(n); rep(i, n) _cin >> v[i].first\
    \ >> v[i].second; return v;}  // vector<pair<T, T>>\n    // tuple\n    template<typename...\
    \ Args> static tuple<Args...> t() {\n        tuple<Args...> values;\n        apply([](auto&...\
    \ args) { ((_cin >> args), ...); }, values);\n        return values;\n    }\n\
    };\n\nint main() {\n    auto& cin = _cin;\n    // speed up io\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    // code\n    auto [m, n] = rd::t<ll,\
    \ ll>();\n    cout << ugilib::fast_pow(m, n, ll(1e9)+7) << endl;;\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\n\n\
    #include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include \"\
    ugilib/base/definitions.hpp\"\n#include \"ugilib/math/pow.hpp\"\n\nusing namespace\
    \ std;\n\n// debug settings\n// #define DEBUG\n#ifdef DEBUG\n// debug input\n\
    string _INPUT = R\"(\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1));\
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
    \ >> args), ...); }, values);\n        return values;\n    }\n};\n\nint main()\
    \ {\n    auto& cin = _cin;\n    // speed up io\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    // code\n    auto [m, n] = rd::t<ll, ll>();\n    cout << ugilib::fast_pow(m,\
    \ n, ll(1e9)+7) << endl;;\n\n    return 0;\n}\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  - ugilib/math/pow.hpp
  isVerificationFile: true
  path: tests/math/pow.test.cpp
  requiredBy: []
  timestamp: '2024-03-27 18:24:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/math/pow.test.cpp
layout: document
redirect_from:
- /verify/tests/math/pow.test.cpp
- /verify/tests/math/pow.test.cpp.html
title: tests/math/pow.test.cpp
---
