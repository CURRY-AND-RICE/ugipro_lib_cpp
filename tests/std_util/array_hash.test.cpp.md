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
    path: ugilib/std_util/hashes.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53\u306E\u5B9A\u7FA9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/13/ALDS1_13_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/13/ALDS1_13_C
  bundledCode: "#line 1 \"tests/std_util/array_hash.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/13/ALDS1_13_C\"\n\n#include\
    \ <bits/stdc++.h>\n#line 2 \"ugilib/base/definitions.hpp\"\n\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\nusing ld = long double;\n#define rep(i,\
    \ n) for(size_t i = 0; i < n; i++)  // rep macro\n#define all(v) begin(v), end(v)\
    \  // all iterator\n#line 3 \"ugilib/base/constants.hpp\"\n\nnamespace ugilib::constants\
    \ {\n    template<typename T>\n    inline constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n} // namespace ugilib::constants\n\nconst ll INF = ugilib::constants::INF<ll>;\n\
    #line 2 \"ugilib/std_util/hashes.hpp\"\n\n/**\n * @file hashes.hpp\n * @brief\
    \ \u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53\u306E\u5B9A\u7FA9\n * @note pair<T1,\
    \ T2>, iterable<T>\u306B\u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \u3092\u5B9A\u7FA9\n*/\n\n#line 10 \"ugilib/std_util/hashes.hpp\"\n#include <type_traits>\n\
    using namespace std;\n\nnamespace ugilib {\n    /**\n     * @brief pair<T1, T2>\u306B\
    \u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\n     * @tparam T1 pair\u306E\
    1\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\n     * @tparam T2 pair\u306E2\u3064\
    \u76EE\u306E\u8981\u7D20\u306E\u578B\n    */\n    struct pair_hash {\n       \
    \ template <class T1, class T2>\n        size_t operator() (const pair<T1, T2>\
    \ &pair) const {\n            auto hash1 = hash<T1>{}(pair.first);\n         \
    \   auto hash2 = hash<T2>{}(pair.second);\n            return hash1 ^ (hash2 <<\
    \ 1);\n        }\n    };\n\n    /**\n     * @brief Iterable\u306B\u5BFE\u3059\u308B\
    \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\n     * @tparam Iterable \u30A4\u30C6\u30E9\
    \u30D6\u30EB\u306A\u30B3\u30F3\u30C6\u30CA\n    */\n    struct array_hash {\n\
    \        /**\n         * @brief \u30A4\u30C6\u30E9\u30D6\u30EB\u578B\u306E\u30CF\
    \u30C3\u30B7\u30E5\u8A08\u7B97\n         * @tparam T \u30A4\u30C6\u30E9\u30D6\u30EB\
    \u306E\u8981\u7D20\u306E\u578B\n         * @param value \u30A4\u30C6\u30E9\u30D6\
    \u30EB\u306E\u8981\u7D20\n         * @return size_t \u30CF\u30C3\u30B7\u30E5\u5024\
    \n         * @note \u518D\u5E30\u7684\u547C\u3073\u51FA\u3057\u3067\u7B97\u8853\
    \u578B\u306B\u8FBF\u308A\u7740\u3044\u305F\u5834\u5408\u306E\u30CF\u30C3\u30B7\
    \u30E5\n        */\n        template <typename T, std::enable_if_t<std::is_arithmetic_v<T>,\
    \ int> = 0>\n        size_t operator() (const T& value) const {\n            size_t\
    \ hash = 0;\n            hash ^= std::hash<T>{}(value) + 0x9e3779b9 + (hash <<\
    \ 6) + (hash >> 2);\n            return hash;\n        }\n\n        /**\n    \
    \     * @brief \u30A4\u30C6\u30EC\u30FC\u30BF\u7279\u6027\u3092\u6301\u305F\u306A\
    \u3044array<T, N>\u306B\u5BFE\u3059\u308B\u7279\u6B8A\u5316\n         * @tparam\
    \ T array\u306E\u8981\u7D20\u306E\u578B\n         * @tparam N array\u306E\u8981\
    \u7D20\u6570\n         * @param array array\n         * @return size_t \u30CF\u30C3\
    \u30B7\u30E5\u5024\n        */\n        template <typename T, size_t N>\n    \
    \    size_t operator() (const array<T, N> &array) const {\n            size_t\
    \ hash = 0;\n            for (const auto& item : array) {\n                hash\
    \ ^= (*this)(item) + 0x9e3779b9 + (hash << 6) + (hash >> 2);\n            }\n\
    \            return hash;\n        }\n\n        /**\n         * @brief \u30A4\u30C6\
    \u30E9\u30D6\u30EB\u578B\u306E\u30CF\u30C3\u30B7\u30E5\u8A08\u7B97\n         *\
    \ @tparam Iterable \u30A4\u30C6\u30E9\u30D6\u30EB\u306A\u30B3\u30F3\u30C6\u30CA\
    \n         * @param iterable \u30A4\u30C6\u30E9\u30D6\u30EB\n         * @return\
    \ size_t \u30CF\u30C3\u30B7\u30E5\u5024\n         * @note \u518D\u5E30\u7684\u547C\
    \u3073\u51FA\u3057\u3092\u884C\u3044\u3001\u591A\u6B21\u5143\u30B3\u30F3\u30C6\
    \u30CA\u306B\u5BFE\u3057\u3066\u3082\u30CF\u30C3\u30B7\u30E5\u53EF\u80FD\n   \
    \     */\n        template <typename Iterable, std::enable_if_t<!std::is_arithmetic_v<Iterable>\
    \ &&\n                                                    std::is_base_of_v<std::input_iterator_tag,\
    \ typename std::iterator_traits<typename Iterable::iterator>::iterator_category>,\
    \ int> = 0>\n        size_t operator() (const Iterable &iterable) const {\n  \
    \          size_t hash = 0;\n            for (const auto &item : iterable) {\n\
    \                hash ^= (*this)(item) + 0x9e3779b9 + (hash << 6) + (hash >> 2);\n\
    \            }\n            return hash;\n        }\n    };\n} // namespace ugilib\n\
    #line 7 \"tests/std_util/array_hash.test.cpp\"\n\nusing namespace std;\n\n// debug\
    \ settings\n// #define DEBUG\n#ifdef DEBUG\n// debug input\nstring _INPUT = R\"\
    (\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1)); // remove '\\\
    n' at _INPUT[0]\n#else\n// standard input\nauto& _cin = cin;\n#endif\n\n// speed\
    \ up\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n\n// reader\nstruct rd {\n    // T\n    template<typename\
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
    \        }\n    }\n};  // namespace deb\n\nconst int SIDE = 4;\nconst int DEPTH_LIMIT\
    \ = 45;\nusing Board = array<array<short, SIDE>, SIDE>;\n\n// A-star algorithm\n\
    int main() {\n    auto& cin = _cin;\n    // speed up io\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    // code\n    Board initial;\n    Board\
    \ ideal;\n    short sy, sx;\n    rep(i, 4) rep(j, 4) {\n        cin >> initial[i][j];\n\
    \        ideal[i][j] = (SIDE*i + j + 1) % 16;\n\n        if (initial[i][j] ==\
    \ 0) {\n            sy = i;\n            sx = j;\n        }\n    }\n\n    // A*\u30B9\
    \u30B3\u30A2\u3001\u76E4\u9762\u3001\u30B3\u30B9\u30C8\u3001\u30BC\u30ED\u4F4D\
    \u7F6Ey, x\n    using elements = tuple<short, Board, short, short, short>;\n \
    \   priority_queue<elements, vector<elements>, greater<>> pq;\n    unordered_map<Board,\
    \ short, ugilib::array_hash> costs;\n    pq.push({0, initial, 0, sy, sx});\n \
    \   costs[initial] = 0;\n\n    int ans = -1;\n    pair<short, short> dyxs[] =\
    \ {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};\n    while (!pq.empty()) {\n        auto\
    \ [score, board, cost, zy, zx] = pq.top();\n        pq.pop();\n\n        if (costs[board]\
    \ > cost) continue;\n        if (board == ideal) {\n            ans = cost;\n\
    \            break;\n        }\n\n        for (auto [dy, dx] : dyxs) {\n     \
    \       short ny = zy + dy;\n            short nx = zx + dx;\n            if (ny\
    \ < 0 || SIDE <= ny || nx < 0 || SIDE <= nx) continue;\n\n            swap(board[zy][zx],\
    \ board[ny][nx]);\n            if (costs.count(board) == 0 || costs[board] > cost\
    \ + 1) {\n                costs[board] = cost + 1;\n                short h =\
    \ 0;\n                rep(i, 4) rep(j, 4) {\n                    if (board[i][j]\
    \ == 0) continue;\n                    short num = board[i][j];\n            \
    \        short ideal_y = (num - 1) / 4;\n                    short ideal_x = (num\
    \ - 1) % 4;\n                    h += abs((short)i - ideal_y) + abs((short)j -\
    \ ideal_x);\n                }\n                pq.push({cost + 1 + h, board,\
    \ cost + 1, ny, nx});\n            }\n            swap(board[zy][zx], board[ny][nx]);\n\
    \        }\n    }\n\n    assert(ans != -1);\n    cout << ans << endl;\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/13/ALDS1_13_C\"\
    \n\n#include <bits/stdc++.h>\n#include \"ugilib/base/constants.hpp\"\n#include\
    \ \"ugilib/base/definitions.hpp\"\n#include \"ugilib/std_util/hashes.hpp\"\n\n\
    using namespace std;\n\n// debug settings\n// #define DEBUG\n#ifdef DEBUG\n//\
    \ debug input\nstring _INPUT = R\"(\n5\n1 2 3 4 5\n)\";\nauto _cin = stringstream(_INPUT.substr(1));\
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
    \ cout << endl;\n        }\n    }\n};  // namespace deb\n\nconst int SIDE = 4;\n\
    const int DEPTH_LIMIT = 45;\nusing Board = array<array<short, SIDE>, SIDE>;\n\n\
    // A-star algorithm\nint main() {\n    auto& cin = _cin;\n    // speed up io\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    // code\n    Board\
    \ initial;\n    Board ideal;\n    short sy, sx;\n    rep(i, 4) rep(j, 4) {\n \
    \       cin >> initial[i][j];\n        ideal[i][j] = (SIDE*i + j + 1) % 16;\n\n\
    \        if (initial[i][j] == 0) {\n            sy = i;\n            sx = j;\n\
    \        }\n    }\n\n    // A*\u30B9\u30B3\u30A2\u3001\u76E4\u9762\u3001\u30B3\
    \u30B9\u30C8\u3001\u30BC\u30ED\u4F4D\u7F6Ey, x\n    using elements = tuple<short,\
    \ Board, short, short, short>;\n    priority_queue<elements, vector<elements>,\
    \ greater<>> pq;\n    unordered_map<Board, short, ugilib::array_hash> costs;\n\
    \    pq.push({0, initial, 0, sy, sx});\n    costs[initial] = 0;\n\n    int ans\
    \ = -1;\n    pair<short, short> dyxs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};\n\
    \    while (!pq.empty()) {\n        auto [score, board, cost, zy, zx] = pq.top();\n\
    \        pq.pop();\n\n        if (costs[board] > cost) continue;\n        if (board\
    \ == ideal) {\n            ans = cost;\n            break;\n        }\n\n    \
    \    for (auto [dy, dx] : dyxs) {\n            short ny = zy + dy;\n         \
    \   short nx = zx + dx;\n            if (ny < 0 || SIDE <= ny || nx < 0 || SIDE\
    \ <= nx) continue;\n\n            swap(board[zy][zx], board[ny][nx]);\n      \
    \      if (costs.count(board) == 0 || costs[board] > cost + 1) {\n           \
    \     costs[board] = cost + 1;\n                short h = 0;\n               \
    \ rep(i, 4) rep(j, 4) {\n                    if (board[i][j] == 0) continue;\n\
    \                    short num = board[i][j];\n                    short ideal_y\
    \ = (num - 1) / 4;\n                    short ideal_x = (num - 1) % 4;\n     \
    \               h += abs((short)i - ideal_y) + abs((short)j - ideal_x);\n    \
    \            }\n                pq.push({cost + 1 + h, board, cost + 1, ny, nx});\n\
    \            }\n            swap(board[zy][zx], board[ny][nx]);\n        }\n \
    \   }\n\n    assert(ans != -1);\n    cout << ans << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - ugilib/base/constants.hpp
  - ugilib/base/definitions.hpp
  - ugilib/std_util/hashes.hpp
  isVerificationFile: true
  path: tests/std_util/array_hash.test.cpp
  requiredBy: []
  timestamp: '2024-05-18 23:39:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/std_util/array_hash.test.cpp
layout: document
redirect_from:
- /verify/tests/std_util/array_hash.test.cpp
- /verify/tests/std_util/array_hash.test.cpp.html
title: tests/std_util/array_hash.test.cpp
---
