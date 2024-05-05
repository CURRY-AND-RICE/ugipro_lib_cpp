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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_8_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_8_C
  bundledCode: "#line 1 \"tests/iteration/counter.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_8_C\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"ugilib/iteration/counter.hpp\"\
    \n\nusing namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u30A4\u30C6\
    \u30EC\u30FC\u30BF\u306E\u7BC4\u56F2\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\
    \u306E\u51FA\u73FE\u56DE\u6570\u3092\u30AB\u30A6\u30F3\u30C8\u3059\u308B\n   \
    \  * @tparam Iterator \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\n     * @param\
    \ first \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u5148\u982D\n     * @param last \u30A4\
    \u30C6\u30EC\u30FC\u30BF\u306E\u7D42\u7AEF\n     * @return unordered_map<\u8981\
    \u7D20\u306E\u578B, \u51FA\u73FE\u56DE\u6570> \u306E\u5F62\u5F0F\u3067\u51FA\u73FE\
    \u56DE\u6570\u3092\u8FD4\u3059\n    */\n    template <typename Iterator, typename\
    \ _Hash = std::hash<typename std::iterator_traits<Iterator>::value_type>>\n  \
    \  unordered_map<typename std::iterator_traits<Iterator>::value_type, ll, _Hash>\
    \ count_elements_as_unordered(Iterator first, Iterator last) {\n        unordered_map<typename\
    \ std::iterator_traits<Iterator>::value_type, ll, _Hash> counter;\n        for\
    \ (auto it = first; it != last; ++it) {\n            counter[*it]++;\n       \
    \ }\n        return counter;\n    }\n\n    /**\n     * @brief \u30A4\u30C6\u30EC\
    \u30FC\u30BF\u306E\u7BC4\u56F2\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\
    \u51FA\u73FE\u56DE\u6570\u3092\u30AB\u30A6\u30F3\u30C8\u3059\u308B\n     * @tparam\
    \ Iterator \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\n     * @param first \u30A4\
    \u30C6\u30EC\u30FC\u30BF\u306E\u5148\u982D\n     * @param last \u30A4\u30C6\u30EC\
    \u30FC\u30BF\u306E\u7D42\u7AEF\n     * @return map<\u8981\u7D20\u306E\u578B, \u51FA\
    \u73FE\u56DE\u6570> \u306E\u5F62\u5F0F\u3067\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\
    \u3059\n    */\n    template <typename Iterator, typename _Compare = less<typename\
    \ std::iterator_traits<Iterator>::value_type>>\n    map<typename std::iterator_traits<Iterator>::value_type,\
    \ ll, _Compare> count_elements_as_ordered(Iterator first, Iterator last) {\n \
    \       map<typename std::iterator_traits<Iterator>::value_type, ll, _Compare>\
    \ counter;\n        for (auto it = first; it != last; ++it) {\n            counter[*it]++;\n\
    \        }\n        return counter;\n    }\n} // namespace ugilib\n#line 7 \"\
    tests/iteration/counter.test.cpp\"\n\nusing namespace std;\n\n// debug settings\n\
    // #define DEBUG\n#ifdef DEBUG\n// debug input\nstring _INPUT = R\"(\n5\n1 2 3\
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
    \n    // code\n    string s;\n    string t;\n    while (cin >> t) {\n        s\
    \ += t;\n    }\n    // s \u3092\u5C0F\u6587\u5B57\u306B\u5909\u63DB\n    transform(s.begin(),\
    \ s.end(), s.begin(), ::tolower);\n\n    unordered_map<char, ll> count1 = ugilib::count_elements_as_unordered(all(s));\n\
    \    map<char, ll> count2 = ugilib::count_elements_as_ordered(all(s));\n\n   \
    \ unordered_map<char, ll> count2_converted(count2.begin(), count2.end());\n  \
    \  assert(count1 == count2_converted);\n\n    for (int i = 0; i < 26; i++) {\n\
    \        char c = 'a' + i;\n        cout << c << \" : \" << count1[c] << endl;\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_8_C\"\n\n\
    #include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include \"\
    ugilib/base/definitions.hpp\"\n#include \"ugilib/iteration/counter.hpp\"\n\nusing\
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
    \n    // code\n    string s;\n    string t;\n    while (cin >> t) {\n        s\
    \ += t;\n    }\n    // s \u3092\u5C0F\u6587\u5B57\u306B\u5909\u63DB\n    transform(s.begin(),\
    \ s.end(), s.begin(), ::tolower);\n\n    unordered_map<char, ll> count1 = ugilib::count_elements_as_unordered(all(s));\n\
    \    map<char, ll> count2 = ugilib::count_elements_as_ordered(all(s));\n\n   \
    \ unordered_map<char, ll> count2_converted(count2.begin(), count2.end());\n  \
    \  assert(count1 == count2_converted);\n\n    for (int i = 0; i < 26; i++) {\n\
    \        char c = 'a' + i;\n        cout << c << \" : \" << count1[c] << endl;\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/iteration/counter.test.cpp
  requiredBy: []
  timestamp: '2024-04-03 21:32:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/iteration/counter.test.cpp
layout: document
redirect_from:
- /verify/tests/iteration/counter.test.cpp
- /verify/tests/iteration/counter.test.cpp.html
title: tests/iteration/counter.test.cpp
---
