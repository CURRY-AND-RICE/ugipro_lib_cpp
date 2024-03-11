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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ugilib/bits/bit_exhaustive_search.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A\"\
    \n\n\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include\
    \ \"ugilib/base/definitions.hpp\"\n#include \"ugilib/bits/bit_exhaustive_search.hpp\"\
    \n\nusing namespace std;\n\n// speed up\n#pragma GCC target(\"avx2\")\n#pragma\
    \ GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n\n// reader\n\
    struct rd {\n    static ll i() {ll i; cin >> i; return i;}  // long long\n   \
    \ static ld d() {ld d; cin >> d; return d;}  // long double\n    static string\
    \ s() {string s; cin >> s; return s;}  // string\n    static char c() {char c;\
    \ cin >> c; return c;}  // char\n    static vector<ll> vi(int n) {vector<ll> v(n);\
    \ rep(i, n) cin >> v[i]; return v;}  // vector<long long>\n    static vector<pair<ll,\
    \ ll>> g(int n) {vector<pair<ll, ll>> v(n); rep(i, n) cin >> v[i].first >> v[i].second;\
    \ return v;}  // vector<pair<long long, long long>>\n    // tuple\n    template<typename...\
    \ Args> static tuple<Args...> t() {\n        tuple<Args...> values;\n        apply([](auto&...\
    \ args) { ((cin >> args), ...); }, values);\n        return values;\n    }\n};\n\
    \n// debug print utility\nnamespace deb {\n    #include <cxxabi.h>\n    // demangle\
    \ type name\n    string demangle(const char* name) {\n        int status = -4;\n\
    \        unique_ptr<char, void(*)(void*)> res{\n            abi::__cxa_demangle(name,\
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
    \ cout << endl;\n        }\n    }\n};  // namespace deb\n\nint main() {\n    //\
    \ speed up io\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n   \
    \ // code\n    ll n = rd::i();\n    auto a = rd::vi(n);\n    ll q = rd::i();\n\
    \    auto m = rd::vi(q);\n\n    unordered_set<ll> numbers;\n    auto f = [&](const\
    \ auto &&bits) {\n        ll sum = 0;\n        for (int i = 0; i < n; i++) {\n\
    \            if (bits[i]) sum += a[i];\n        }\n        numbers.insert(sum);\n\
    \        return false;\n    };\n    ugilib::bit_exhaustive_search(n, f);\n\n \
    \   rep(i, q) {\n        if (numbers.find(m[i]) != numbers.end()) cout << \"yes\"\
    \ << endl;\n        else cout << \"no\" << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/bit/bit_exhaustive_search.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/bit/bit_exhaustive_search.test.cpp
layout: document
redirect_from:
- /verify/tests/bit/bit_exhaustive_search.test.cpp
- /verify/tests/bit/bit_exhaustive_search.test.cpp.html
title: tests/bit/bit_exhaustive_search.test.cpp
---
