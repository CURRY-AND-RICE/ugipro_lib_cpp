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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D
  bundledCode: "#line 1 \"tests/math/enum_divisors.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D\"\n\n#include <bits/stdc++.h>\n\
    #line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n#define rep(i, n) for(size_t i\
    \ = 0; i < n; i++)  // rep macro\n#define all(v) begin(v), end(v)  // all iterator\n\
    #line 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants {\n    template<typename\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / 2;\n} // namespace\
    \ ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n#line 3 \"\
    ugilib/math/enum_divisors.hpp\"\nusing namespace std;\n\nnamespace ugilib {\n\
    \    /**\n     * @brief \u7D04\u6570\u5217\u6319. \u7D50\u679C\u306F\u30BD\u30FC\
    \u30C8\u6E08\u307F\n     * @tparam T \u6574\u6570\u578B\n     * @param n \u7D04\
    \u6570\u5217\u6319\u3059\u308B\u6570\n     * @return vector<T> \u7D04\u6570\u30EA\
    \u30B9\u30C8\n     * @note O(sqrt(n))\n    */\n    template <typename T>\n   \
    \ vector<T> enum_divisors(T n) {\n        vector<T> divisors_front;\n        deque<T>\
    \ divisors_back;\n        for (T i = 1; i * i <= n; i++) {\n            if (n\
    \ % i == 0) {\n                divisors_front.push_back(i);\n                if\
    \ (i * i != n) divisors_back.push_front(n / i);\n            }\n        }\n  \
    \      divisors_front.insert(divisors_front.end(), divisors_back.begin(), divisors_back.end());\n\
    \        return divisors_front;\n    }\n\n    /**\n     * @brief \u7D04\u6570\u5217\
    \u6319. \u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\u3092\u7528\u3044\u308B\
    . \u7D50\u679C\u306F\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u306A\u3044\n \
    \    * @tparam T \u6574\u6570\u578B\n     * @param n \u7D04\u6570\u5217\u6319\u3059\
    \u308B\u6570\n     * @param factors \u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\
    \u679C\n     * @return vector<T> \u7D04\u6570\u30EA\u30B9\u30C8\n     * @note\
    \ O(\u03A0c_i) (c_i\u306F\u7D20\u56E0\u6570\u5206\u89E3\u306E\u6307\u6570)\n \
    \    * @note \u7D50\u679C\u304C\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u306A\
    \u3044\u3053\u3068\u306B\u6CE8\u610F\n     */\n    template <typename T>\n   \
    \ vector<T> enum_divisors_with_prime_factors(T n, const vector<pair<T, int>>&\
    \ factors) {\n        vector<T> divisors = {1};\n        for (const auto& [p,\
    \ c] : factors) {\n            vector<T> new_divisors;\n            for (T d :\
    \ divisors) {\n                T mul = 1;\n                for (int i = 0; i <\
    \ c; i++) {\n                    mul *= p;\n                    new_divisors.push_back(d\
    \ * mul);\n                }\n            }\n            divisors.insert(divisors.end(),\
    \ new_divisors.begin(), new_divisors.end());\n        }\n        return divisors;\n\
    \    }\n} // namespace ugilib\n#line 3 \"ugilib/math/primes.hpp\"\nusing namespace\
    \ std;\n\nnamespace ugilib {\n    /**\n     * @brief \u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u7BE9\n     * @tparam T \u6574\u6570\u578B\n     * @param n\
    \ \u7D20\u6570\u306E\u4E0A\u9650. n\u3092\u542B\u3080\n     * @return vector<T>\
    \ \u7D20\u6570\u30EA\u30B9\u30C8\n     * @note O(n log log n)\n     * @note j\u306B\
    \u4EE3\u5165\u3055\u308C\u308B\u6570\u306E\u6700\u5927\u5024\u306FN^2\u306A\u306E\
    \u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n    */\n \
    \   template <typename T>\n    vector<T> shieve(const T &n) {\n        vector<bool>\
    \ is_prime(n + 1, true);\n        vector<T> primes;\n        is_prime[0] = is_prime[1]\
    \ = false;\n        for (T i = 2; i <= n; i++) {\n            if (!is_prime[i])\
    \ continue;\n            primes.push_back(i);\n            for (T j = i * i; 0\
    \ <= j && j <= n; j += i) {  // \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\
    \u6CE8\u610F\n                is_prime[j] = false;\n            }\n        }\n\
    \        return primes;\n    }\n\n    /**\n     * @brief \u7D20\u56E0\u6570\u5206\
    \u89E3. \u7D20\u6570\u30EA\u30B9\u30C8\u3092\u7528\u3044\u308B\n     * @tparam\
    \ T \u6574\u6570\u578B\n     * @param n \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\
    \u6570\n     * @param primes \u7D20\u6570\u30EA\u30B9\u30C8. shieve\u3067\u53D6\
    \u5F97\u3057\u305F\u3082\u306E\u3092\u4F7F\u3046\n     * @return vector<pair<T,\
    \ int>> \u7D20\u56E0\u6570\u3068\u305D\u306E\u500B\u6570\n     * @note O(sqrt(n))\
    \ \u3088\u308A\u9AD8\u901F. shieve\u306B\u6642\u9593\u304C\u304B\u304B\u308A\uFF0C\
    \u30E1\u30E2\u30EA\u3092\u3088\u308A\u6D88\u8CBB\u3059\u308B\n    */\n    template\
    \ <typename T>\n    vector<pair<T, int>> prime_factorization_with_shieve(T n,\
    \ const vector<T>& primes) {\n        vector<pair<T, int>> factors;  // \u7D20\
    \u56E0\u6570\u3068\u305D\u306E\u500B\u6570\n        for (const T &p : primes)\
    \ {\n            if (p * p > n) break;\n            if (n % p != 0) continue;\n\
    \            int count = 0;\n            while (n % p == 0) {\n              \
    \  n /= p;\n                count++;\n            }\n            factors.push_back({p,\
    \ count});\n        }\n        if (n != 1) factors.push_back({n, 1});  // n\u304C\
    \u7D20\u6570\u306E\u5834\u5408\n        return factors;\n    }\n\n    /**\n  \
    \   * @brief \u7D20\u56E0\u6570\u5206\u89E3\n     * @tparam T \u6574\u6570\u578B\
    \n     * @param n \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u6570\n     * @return\
    \ vector<pair<T, int>> \u7D20\u56E0\u6570\u3068\u305D\u306E\u500B\u6570\n    \
    \ * @note O(sqrt(n))\n    */\n    template <typename T>\n    vector<pair<T, int>>\
    \ prime_factorization(T n) {\n        vector<pair<T, int>> factors;\n        for\
    \ (T i = 2; i * i <= n; i++) {\n            if (n % i != 0) continue;\n      \
    \      int count = 0;\n            while (n % i == 0) {\n                n /=\
    \ i;\n                count++;\n            }\n            factors.push_back({i,\
    \ count});\n        }\n        if (n != 1) factors.push_back({n, 1});  // n\u304C\
    \u7D20\u6570\u306E\u5834\u5408\n        return factors;\n    }\n} // namespace\
    \ ugilib\n#line 8 \"tests/math/enum_divisors.test.cpp\"\n\nusing namespace std;\n\
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
    \n    // code\n    auto [a, b, c] = rd::t<ll, ll, ll>();\n\n    auto divisors1\
    \ = ugilib::enum_divisors(c);\n    auto divisors2 = ugilib::enum_divisors_with_prime_factors(c,\
    \ ugilib::prime_factorization(c));\n    sort(all(divisors2));\n    assert(divisors1\
    \ == divisors2);\n\n    auto it_a = lower_bound(all(divisors1), a);\n    auto\
    \ it_b = lower_bound(all(divisors1), b);\n    if (it_b != divisors1.end() && *it_b\
    \ == b) it_b++;\n    ll ans = distance(it_a, it_b);\n\n    cout << ans << endl;\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D\"\n\n\
    #include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include \"\
    ugilib/base/definitions.hpp\"\n#include \"ugilib/math/enum_divisors.hpp\"\n#include\
    \ \"ugilib/math/primes.hpp\"\n\nusing namespace std;\n\n// debug settings\n//\
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
    \n    // code\n    auto [a, b, c] = rd::t<ll, ll, ll>();\n\n    auto divisors1\
    \ = ugilib::enum_divisors(c);\n    auto divisors2 = ugilib::enum_divisors_with_prime_factors(c,\
    \ ugilib::prime_factorization(c));\n    sort(all(divisors2));\n    assert(divisors1\
    \ == divisors2);\n\n    auto it_a = lower_bound(all(divisors1), a);\n    auto\
    \ it_b = lower_bound(all(divisors1), b);\n    if (it_b != divisors1.end() && *it_b\
    \ == b) it_b++;\n    ll ans = distance(it_a, it_b);\n\n    cout << ans << endl;\n\
    \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/math/enum_divisors.test.cpp
  requiredBy: []
  timestamp: '2024-03-27 18:24:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/math/enum_divisors.test.cpp
layout: document
redirect_from:
- /verify/tests/math/enum_divisors.test.cpp
- /verify/tests/math/enum_divisors.test.cpp.html
title: tests/math/enum_divisors.test.cpp
---
