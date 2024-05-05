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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
  bundledCode: "#line 1 \"tests/dp/lis.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    #define rep(i, n) for(size_t i = 0; i < n; i++)  // rep macro\n#define all(v)\
    \ begin(v), end(v)  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\n\
    namespace ugilib::constants {\n    template<typename T>\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n} // namespace ugilib::constants\n\
    \nconst ll INF = ugilib::constants::INF<ll>;\n#line 4 \"ugilib/dp/lis.hpp\"\n\
    using namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief \u6700\u9577\
    \u5897\u52A0\u90E8\u5206\u5217\n     * @tparam T vector\u306E\u8981\u7D20\u306E\
    \u578B\n     * @param A vector\n     * @param inf \u7121\u9650\u5927\n     * @return\
    \ pair<size_t, vector<T>> (\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\
    \u3055, \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217(\u4E00\u610F\u3067\u306F\u306A\
    \u3044))\n     * @note O(n log n). n = A.size()\n    */\n    template <typename\
    \ T>\n    pair<size_t, vector<T>> longest_increasing_subsequence(const vector<T>\
    \ &A, const T inf = ugilib::constants::INF<T>) {\n        static_assert(is_signed<T>::value,\
    \ \"T must be signed type.\");  // T\u306F\u7B26\u53F7\u4ED8\u304D\u578B\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n        // dp[i]: \u9577\u3055\u304C\
    i\u3067\u3042\u308B\u3088\u3046\u306A\u5897\u52A0\u90E8\u5206\u5217\u306E\u6700\
    \u5F8C\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024\n        vector<T> dp(A.size()\
    \ + 1, inf);  // 1-indexed\n        vector<size_t> indices(A.size());  // indices[i]:\
    \ A[i]\u304Cdp\u306E\u3069\u3053\u306B\u5165\u308B\u304B\n        dp[0] = -1;\n\
    \        for (size_t i = 0; i < A.size(); i++) {\n            size_t idx = lower_bound(dp.begin(),\
    \ dp.end(), A[i]) - dp.begin();\n            dp[idx] = A[i];\n            indices[i]\
    \ = idx;\n        }\n\n        // inf\u306E\u624B\u524D\u307E\u3067\u90E8\u5206\
    \u5897\u52A0\u5217\u306E\u6700\u7D42\u8981\u7D20\u304C\u5165\u3063\u3066\u3044\
    \u308B\n        const size_t lis_length = find(dp.begin(), dp.end(), inf) - dp.begin()\
    \ - 1;\n        // \u90E8\u5206\u5897\u52A0\u5217\u306E\u5FA9\u5143\n        vector<T>\
    \ lis(lis_length);\n        size_t target = lis_length;\n        for (int i =\
    \ A.size() - 1; i >= 0; i--) if (indices[i] == target) lis[--target] = A[i];\n\
    \n        return {lis_length, lis};\n    }\n}  // namespace ugilib\n#line 7 \"\
    tests/dp/lis.test.cpp\"\n\nusing namespace std;\n\n// debug settings\n// #define\
    \ DEBUG\n#ifdef DEBUG\n// debug input\nstring _INPUT = R\"(\n5\n1 2 3 4 5\n)\"\
    ;\nauto _cin = stringstream(_INPUT.substr(1)); // remove '\\n' at _INPUT[0]\n\
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
    \n    // code\n    int n = rd::i<int>();\n    vector<int> A = rd::v<int>(n);\n\
    \n    auto [ans, lis] = ugilib::longest_increasing_subsequence(A);\n    // deb::p(lis);\n\
    \n    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include\
    \ \"ugilib/base/definitions.hpp\"\n#include \"ugilib/dp/lis.hpp\"\n\nusing namespace\
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
    \n    // code\n    int n = rd::i<int>();\n    vector<int> A = rd::v<int>(n);\n\
    \n    auto [ans, lis] = ugilib::longest_increasing_subsequence(A);\n    // deb::p(lis);\n\
    \n    cout << ans << endl;\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/dp/lis.test.cpp
  requiredBy: []
  timestamp: '2024-04-03 22:40:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dp/lis.test.cpp
layout: document
redirect_from:
- /verify/tests/dp/lis.test.cpp
- /verify/tests/dp/lis.test.cpp.html
title: tests/dp/lis.test.cpp
---
