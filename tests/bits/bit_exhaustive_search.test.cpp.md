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
    path: ugilib/bits/bit_exhaustive_search.hpp
    title: bit_exhaustive_search
  - icon: ':heavy_check_mark:'
    path: ugilib/bits/bit_util.hpp
    title: num_to_bits
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A
  bundledCode: "#line 1 \"tests/bits/bit_exhaustive_search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A\"\n\n\n\
    #include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll\
    \ = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n#define\
    \ rep(i, n) for(int i = 0; i < (int)(n); i++)  // rep macro\n#define all(v) begin(v),\
    \ end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\nnamespace\
    \ ugilib::constants {\n    template<typename T>\n    inline constexpr T INF =\
    \ std::numeric_limits<T>::max() / 4;\n} // namespace ugilib::constants\n\nconst\
    \ ll INF = ugilib::constants::INF<ll>;\n#line 4 \"ugilib/bits/bit_util.hpp\"\n\
    \nusing namespace std;\n\nnamespace ugilib {\n/**\n * @brief num_to_bits\n * @param\
    \ num an integer to be converted to bits\n * @param digit the number of bits\n\
    \ * @return vector<bool> bits of num\n * @details convert an integer to bits\n\
    */\nvector<bool> num_to_bits(const ll num, const size_t &digit) {\n    vector<bool>\
    \ bits(digit);\n    for (int i = 0; i < digit; i++) {\n        bits[i] = (num\
    \ >> i) & 1U;\n    }\n    return bits;\n}\n\n/**\n * @brief bits_to_num\n * @param\
    \ bits a vector of bits\n * @return ll an integer of bits\n * @details convert\
    \ bits to an integer\n*/\nll bits_to_num(const vector<bool> &bits) {\n    ll num\
    \ = 0;\n    for (int i = 0; i < bits.size(); i++) {\n        num += bits[i] <<\
    \ i;\n    }\n    return num;\n}\n}  // namespace ugilib\n#line 4 \"ugilib/bits/bit_exhaustive_search.hpp\"\
    \n\nnamespace ugilib {\n/**\n * @brief bit_exhaustive_search\n * @param digit\
    \ the number of bits\n * @param f a function to be called with bits\n * @details\
    \ exhaustive search for bits\n *\n * @example\n * vector<int> ans;\n * auto f\
    \ = [&](const auto &&bits) {\n *    if (count(bits.begin(), bits.end(), true)\
    \ == 2) {\n *        ans.push_back(bits_to_num(bits));\n *    }\n *    return\
    \ false;\n * };\n * bit_exhaustive_search(4, f);\n * // ans = {3, 5, 6, 9, 10,\
    \ 12}\n *\n*/\ntemplate <typename Func>\nvoid bit_exhaustive_search(const size_t\
    \ &digit, Func f) {\n    for (ll i = 0; i < (1 << digit); i++) {\n        bool\
    \ will_break = f(num_to_bits(i, digit));\n        if (will_break) break;\n   \
    \ }\n}\n}  // namespace ugilib\n#line 8 \"tests/bits/bit_exhaustive_search.test.cpp\"\
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
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  - ugilib/bits/bit_exhaustive_search.hpp
  - ugilib/bits/bit_util.hpp
  isVerificationFile: true
  path: tests/bits/bit_exhaustive_search.test.cpp
  requiredBy: []
  timestamp: '2024-03-06 18:21:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/bits/bit_exhaustive_search.test.cpp
layout: document
redirect_from:
- /verify/tests/bits/bit_exhaustive_search.test.cpp
- /verify/tests/bits/bit_exhaustive_search.test.cpp.html
title: tests/bits/bit_exhaustive_search.test.cpp
---
