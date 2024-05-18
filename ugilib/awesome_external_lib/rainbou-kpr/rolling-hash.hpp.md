---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ugilib/awesome_external_lib/rainbou-kpr/traits.hpp
    title: "\u578B\u7279\u6027\u3092\u6271\u3046\u30D8\u30C3\u30C0"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tests/awesome_external_lib/rolling_hash.notest.cpp
    title: tests/awesome_external_lib/rolling_hash.notest.cpp
  - icon: ':heavy_check_mark:'
    path: ugilib/string/palindrome.hpp
    title: "\u5217\u306E[l, r)\u304C\u56DE\u6587\u304B\u3069\u3046\u304B\u3092\u5224\
      \u5B9A\u3059\u308B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string/palindrome.test.cpp
    title: tests/string/palindrome.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3092\u6271\
      \u3046\u30D8\u30C3\u30C0"
    links:
    - "https://github.com/rainbou-kpr/library\u304B\u3089\u306E\u30B3\u30D4\u30FC\u3067\
      \u3059"
  bundledCode: "#line 2 \"ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp\"\
    \n\n/**\n * @file rolling-hash.hpp\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\
    \u30C3\u30B7\u30E5\u3092\u6271\u3046\u30D8\u30C3\u30C0\n * @note https://github.com/rainbou-kpr/library\u304B\
    \u3089\u306E\u30B3\u30D4\u30FC\u3067\u3059\n */\n\n#include <string>\n#include\
    \ <vector>\n#include <random>\n#include <cassert>\n#include <string_view>\n#include\
    \ <type_traits>\n\n#line 2 \"ugilib/awesome_external_lib/rainbou-kpr/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\u3092\u6271\u3046\u30D8\
    \u30C3\u30C0\n * @note https://github.com/rainbou-kpr/library\u304B\u3089\u306E\
    \u30B3\u30D4\u30FC\u3067\u3059\n */\n\n#include <iterator>\n#line 11 \"ugilib/awesome_external_lib/rainbou-kpr/traits.hpp\"\
    \n#include <utility>\n\nnamespace ugilib::rainbou_kpr {\n    namespace detail\
    \ {\n    using std::begin, std::end;\n\n    template <class T, class = void>\n\
    \    struct is_range_impl : std::false_type {};\n    template <class T>\n    struct\
    \ is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>>\
    \ : std::true_type {};\n    }  // namespace detail\n\n    template <class T>\n\
    \    struct is_range : detail::is_range_impl<T>::type {};\n    template <class\
    \ T>\n    inline constexpr bool is_range_v = is_range<T>::value;\n}  // namespace\
    \ ugilib::rainbou_kpr\n#line 17 \"ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp\"\
    \n\nnamespace ugilib::rainbou_kpr {\n    struct RHString;\n\n    /**\n     * @brief\
    \ \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     *\n     * \u30D3\
    \u30C3\u30C8\u6F14\u7B97\u306B\u5BC4\u308B\u9AD8\u901F\u5316\u306E\u305F\u3081\
    \u30CF\u30C3\u30B7\u30E5\u306FMOD = 2^61-1\u3067\u8A08\u7B97\u3055\u308C\u308B\
    \n     *\n     * 10^8\u500B\u304F\u3089\u3044\u306A\u308999%\u306E\u78BA\u7387\
    \u3067\u885D\u7A81\u3059\u308B\u7D44\u304C\u5B58\u5728\u3057\u306A\u3044\n   \
    \  */\n    class RollingHash {\n        constexpr static unsigned long long MASK30\
    \ = (1ULL << 30) - 1;\n        constexpr static unsigned long long MASK31 = (1ULL\
    \ << 31) - 1;\n        constexpr static unsigned long long MOD = (1ULL << 61)\
    \ - 1;\n\n        // a < MOD, b < MOD\u5FC5\u9808\n        constexpr static unsigned\
    \ long long add(unsigned long long a, unsigned long long b) {\n            if((a\
    \ += b) >= MOD) a -= MOD;\n            return a;\n        }\n\n        // a <\
    \ MOD, b < MOD\u5FC5\u9808\n        constexpr static unsigned long long mul(unsigned\
    \ long long a, unsigned long long b) {\n            __uint128_t c = static_cast<__uint128_t>(a)\
    \ * b;\n            return add(static_cast<unsigned long long>(c >> 61), static_cast<unsigned\
    \ long long>(c & MOD));\n        }\n\n        void expand(int n) {\n         \
    \   while(static_cast<int>(power.size()) <= n) power.push_back(mul(power.back(),\
    \ base));\n        }\n\n    public:\n        unsigned int base; //!< \u30CF\u30C3\
    \u30B7\u30E5\u306E\u57FA\u6570\n        std::vector<unsigned long long> power;\
    \ //!< base\u306E\u7D2F\u4E57\n\n        /**\n         * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n         *\n         * @param base \u30CF\u30C3\u30B7\
    \u30E5\u306E\u57FA\u6570 \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\
    \n         */\n        RollingHash(unsigned int base = 0) : base(base) {\n   \
    \         if(base == 0) {\n                std::mt19937 mt(std::random_device{}());\n\
    \                this->base = std::uniform_int_distribution<unsigned int>(129,\
    \ ~0U)(mt);\n            }\n            power = {1};\n        }\n\n        /**\n\
    \         * @brief \u914D\u5217/\u6587\u5B57\u5217\u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u9593\u306E\u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97(O(N))\n         *\n\
    \         * @tparam It \u30A4\u30C6\u30EC\u30FC\u30BF\n         * @param first\
    \ \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n         * @param\
    \ last \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n        \
    \ * @return std::vector<unsigned long long> \u5148\u982D\u304B\u3089\u5404\u8981\
    \u7D20\u6570\u5206\u306E\u30CF\u30C3\u30B7\u30E5\n         */\n        template\
    \ <typename It>\n        std::vector<unsigned long long> build(It first, It last)\
    \ {\n            std::vector<unsigned long long> res;\n            if constexpr\
    \ (std::is_convertible_v<typename std::iterator_traits<It>::iterator_category,\
    \ std::random_access_iterator_tag>) {\n                res.reserve(last - first\
    \ + 1);\n            }\n            res.push_back(0);\n            for(; first\
    \ != last; ++first) {\n                res.push_back(add(mul(res.back(), base),\
    \ *first));\n            }\n            return res;\n        }\n\n        /**\n\
    \         * @brief \u914D\u5217/\u6587\u5B57\u5217\u5168\u4F53\u306E\u30CF\u30C3\
    \u30B7\u30E5\u306E\u8A08\u7B97(O(N))\n         *\n         * @param s \u914D\u5217\
    /\u6587\u5B57\u5217\n         * @return std::vector<unsigned long long> \u5148\
    \u982D\u304B\u3089\u5404\u6587\u5B57\u6570\u5206\u306E\u30CF\u30C3\u30B7\u30E5\
    \n         */\n        template <typename R>\n        std::vector<unsigned long\
    \ long> build(R&& s) {\n            using std::begin, std::end;\n            return\
    \ build(begin(s), end(s));\n        }\n\n        /**\n         * @brief [l,r)\u306E\
    \u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97(O(1))\n         *\n         * @param\
    \ hash \u5148\u982D\u304B\u3089\u306E\u30CF\u30C3\u30B7\u30E5\n         * @param\
    \ l \u533A\u9593\u306E\u5DE6\u7AEF\n         * @param r \u533A\u9593\u306E\u53F3\
    \u7AEF\n         * @return unsigned long long [l,r)\u306E\u30CF\u30C3\u30B7\u30E5\
    \n         */\n        unsigned long long query(const std::vector<unsigned long\
    \ long>& hash, int l, int r) {\n            expand(r - l);\n            return\
    \ add(hash[r], MOD - mul(hash[l], power[r-l]));\n        }\n\n        friend RHString;\n\
    \    };\n\n    /**\n     * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
    \u30E5\u306B\u3088\u3063\u3066\u7BA1\u7406\u3055\u308C\u308B\u6587\u5B57\u5217\
    \u578B\n     */\n    struct RHString {\n        RollingHash& rh;\n        size_t\
    \ sz;\n        unsigned long long hash1;  //!< \u6B63\u9806\n        unsigned\
    \ long long hash2;  //!< \u9006\u9806\n        /**\n         * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n         * \u4E88\u3081RollingHash\u3092\u30A4\
    \u30F3\u30B9\u30BF\u30F3\u30B9\u5316\u3057\u3066\u304A\u304F\u5FC5\u8981\u304C\
    \u3042\u308B\n         */\n        RHString(RollingHash& rh) : rh(rh), sz(0),\
    \ hash1(0), hash2(0) {}\n        RHString(RollingHash& rh, size_t sz, unsigned\
    \ long long hash1, unsigned long long hash2) : rh(rh), sz(sz), hash1(hash1), hash2(hash2)\
    \ {}\n        RHString(const RHString& o) : rh(o.rh), sz(o.sz), hash1(o.hash1),\
    \ hash2(o.hash2) {}\n        /**\n         * @brief vector\u306A\u3069\u3067\u521D\
    \u671F\u5316\u3059\u308B\n         */\n        template <class R, std::enable_if_t<is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>, std::nullptr_t> = nullptr>\n\
    \        RHString(RollingHash& rh, R&& v) : rh(rh) {\n            using std::begin,\
    \ std::end, std::rbegin, std::rend;\n            sz = std::distance(begin(v),\
    \ end(v));\n            hash1 = rh.build(begin(v), end(v)).back();\n         \
    \   hash2 = rh.build(rbegin(v), rend(v)).back();\n        }\n        /**\n   \
    \      * @brief char\u3084unsigned long long\u306A\u3069\u3067\u521D\u671F\u5316\
    \u3059\u308B\n         */\n        template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n        RHString(RollingHash& rh, T&& x) : rh(rh) {\n          \
    \  sz = 1;\n            hash1 = x;\n            hash2 = x;\n        }\n      \
    \  /**\n         * @brief \u6587\u5B57\u5217(string, const char*, string_view)\u3067\
    \u521D\u671F\u5316\u3059\u308B\n         */\n        RHString(RollingHash& rh,\
    \ std::string_view s) : rh(rh) {\n            sz = std::distance(s.begin(), s.end());\n\
    \            hash1 = rh.build(s.begin(), s.end()).back();\n            hash2 =\
    \ rh.build(s.rbegin(), s.rend()).back();\n        }\n\n        /**\n         *\
    \ @brief \u56DE\u6587\u304B\u5426\u304B\n         */\n        bool is_palindrome()\
    \ const {\n            return hash1 == hash2;\n        }\n        size_t size()\
    \ const {\n            return sz;\n        }\n        void clear() {\n       \
    \     sz = 0;\n            hash1 = 0;\n            hash2 = 0;\n        }\n   \
    \     bool empty() const {\n            return sz == 0;\n        }\n        RHString&\
    \ operator+=(const RHString& o) {\n            assert(&rh == &o.rh);\n       \
    \     rh.expand(sz);\n            rh.expand(o.sz);\n            hash1 = rh.add(rh.mul(hash1,\
    \ rh.power[o.sz]), o.hash1);\n            hash2 = rh.add(hash2, rh.mul(o.hash2,\
    \ rh.power[sz]));\n            sz += o.sz;\n            return *this;\n      \
    \  }\n        /**\n         * @brief \u518D\u4EE3\u5165\u3059\u308B\n        \
    \ * RollingHash\u306F\u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\n         */\n        void assign(const RHString& o) {\n        \
    \    assert(&rh == &o.rh);\n            sz = o.sz;\n            hash1 = o.hash1;\n\
    \            hash2 = o.hash2;\n        }\n        /**\n         * @brief vector\u306A\
    \u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\n         */\n        template <class\
    \ R, std::enable_if_t<is_range_v<R> && !std::is_convertible_v<R, std::string_view>,\
    \ std::nullptr_t> = nullptr>\n        void assign(R&& v) {\n            using\
    \ std::begin, std::end, std::rbegin, std::rend;\n            sz = std::distance(begin(v),\
    \ end(v));\n            hash1 = rh.build(begin(v), end(v)).back();\n         \
    \   hash2 = rh.build(rbegin(v), rend(v)).back();\n        }\n        /**\n   \
    \      * @brief char\u3084unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\
    \u3059\u308B\n         */\n        template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n        void assign(T&& x) {\n            sz = 1;\n            hash1\
    \ = x;\n            hash2 = x;\n        }\n        /**\n         * @brief \u6587\
    \u5B57\u5217(string, const char*, string_view)\u3092\u518D\u4EE3\u5165\u3059\u308B\
    \n         */\n        void assign(std::string_view s) {\n            sz = std::distance(s.begin(),\
    \ s.end());\n            hash1 = rh.build(s.begin(), s.end()).back();\n      \
    \      hash2 = rh.build(s.rbegin(), s.rend()).back();\n        }\n        /**\n\
    \         * @brief \u518D\u4EE3\u5165\u3059\u308B\n         * RollingHash\u306F\
    \u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n   \
    \      */\n        RHString& operator=(const RHString& o) {\n            assign(o);\n\
    \            return *this;\n        }\n        /**\n         * @brief vector\u306A\
    \u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\n         */\n        template <class\
    \ R, std::enable_if_t<is_range_v<R> && !std::is_convertible_v<R, std::string_view>,\
    \ std::nullptr_t> = nullptr>\n        RHString& operator=(R&& v) {\n         \
    \   assign(v);\n            return *this;\n        }\n        /**\n         *\
    \ @brief char\u3084unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\
    \u308B\n         */\n        template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n        RHString& operator=(T&& x) {\n            assign(x);\n \
    \           return *this;\n        }\n        /**\n         * @brief \u6587\u5B57\
    \u5217(string, const char*, string_view)\u3092\u518D\u4EE3\u5165\u3059\u308B\n\
    \         */\n        RHString& operator=(std::string_view s) {\n            assign(s);\n\
    \            return *this;\n        }\n        friend RHString operator+(const\
    \ RHString& t1, const RHString& t2) {\n            RHString ret = t1;\n      \
    \      ret += t2;\n            return ret;\n        }\n        friend bool operator==(const\
    \ RHString& t1, const RHString& t2) {\n            assert(&t1.rh == &t2.rh);\n\
    \            return t1.sz == t2.sz && t1.hash1 == t2.hash1 && t1.hash2 == t2.hash2;\n\
    \        }\n        friend bool operator!=(const RHString& t1, const RHString&\
    \ t2) { return !(t1 == t2); }\n    };\n}  // namespace ugilib::rainbou_kpr\n"
  code: "#pragma once\n\n/**\n * @file rolling-hash.hpp\n * @brief \u30ED\u30FC\u30EA\
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3092\u6271\u3046\u30D8\u30C3\u30C0\n * @note\
    \ https://github.com/rainbou-kpr/library\u304B\u3089\u306E\u30B3\u30D4\u30FC\u3067\
    \u3059\n */\n\n#include <string>\n#include <vector>\n#include <random>\n#include\
    \ <cassert>\n#include <string_view>\n#include <type_traits>\n\n#include \"traits.hpp\"\
    \n\nnamespace ugilib::rainbou_kpr {\n    struct RHString;\n\n    /**\n     * @brief\
    \ \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     *\n     * \u30D3\
    \u30C3\u30C8\u6F14\u7B97\u306B\u5BC4\u308B\u9AD8\u901F\u5316\u306E\u305F\u3081\
    \u30CF\u30C3\u30B7\u30E5\u306FMOD = 2^61-1\u3067\u8A08\u7B97\u3055\u308C\u308B\
    \n     *\n     * 10^8\u500B\u304F\u3089\u3044\u306A\u308999%\u306E\u78BA\u7387\
    \u3067\u885D\u7A81\u3059\u308B\u7D44\u304C\u5B58\u5728\u3057\u306A\u3044\n   \
    \  */\n    class RollingHash {\n        constexpr static unsigned long long MASK30\
    \ = (1ULL << 30) - 1;\n        constexpr static unsigned long long MASK31 = (1ULL\
    \ << 31) - 1;\n        constexpr static unsigned long long MOD = (1ULL << 61)\
    \ - 1;\n\n        // a < MOD, b < MOD\u5FC5\u9808\n        constexpr static unsigned\
    \ long long add(unsigned long long a, unsigned long long b) {\n            if((a\
    \ += b) >= MOD) a -= MOD;\n            return a;\n        }\n\n        // a <\
    \ MOD, b < MOD\u5FC5\u9808\n        constexpr static unsigned long long mul(unsigned\
    \ long long a, unsigned long long b) {\n            __uint128_t c = static_cast<__uint128_t>(a)\
    \ * b;\n            return add(static_cast<unsigned long long>(c >> 61), static_cast<unsigned\
    \ long long>(c & MOD));\n        }\n\n        void expand(int n) {\n         \
    \   while(static_cast<int>(power.size()) <= n) power.push_back(mul(power.back(),\
    \ base));\n        }\n\n    public:\n        unsigned int base; //!< \u30CF\u30C3\
    \u30B7\u30E5\u306E\u57FA\u6570\n        std::vector<unsigned long long> power;\
    \ //!< base\u306E\u7D2F\u4E57\n\n        /**\n         * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n         *\n         * @param base \u30CF\u30C3\u30B7\
    \u30E5\u306E\u57FA\u6570 \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\
    \n         */\n        RollingHash(unsigned int base = 0) : base(base) {\n   \
    \         if(base == 0) {\n                std::mt19937 mt(std::random_device{}());\n\
    \                this->base = std::uniform_int_distribution<unsigned int>(129,\
    \ ~0U)(mt);\n            }\n            power = {1};\n        }\n\n        /**\n\
    \         * @brief \u914D\u5217/\u6587\u5B57\u5217\u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u9593\u306E\u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97(O(N))\n         *\n\
    \         * @tparam It \u30A4\u30C6\u30EC\u30FC\u30BF\n         * @param first\
    \ \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n         * @param\
    \ last \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n        \
    \ * @return std::vector<unsigned long long> \u5148\u982D\u304B\u3089\u5404\u8981\
    \u7D20\u6570\u5206\u306E\u30CF\u30C3\u30B7\u30E5\n         */\n        template\
    \ <typename It>\n        std::vector<unsigned long long> build(It first, It last)\
    \ {\n            std::vector<unsigned long long> res;\n            if constexpr\
    \ (std::is_convertible_v<typename std::iterator_traits<It>::iterator_category,\
    \ std::random_access_iterator_tag>) {\n                res.reserve(last - first\
    \ + 1);\n            }\n            res.push_back(0);\n            for(; first\
    \ != last; ++first) {\n                res.push_back(add(mul(res.back(), base),\
    \ *first));\n            }\n            return res;\n        }\n\n        /**\n\
    \         * @brief \u914D\u5217/\u6587\u5B57\u5217\u5168\u4F53\u306E\u30CF\u30C3\
    \u30B7\u30E5\u306E\u8A08\u7B97(O(N))\n         *\n         * @param s \u914D\u5217\
    /\u6587\u5B57\u5217\n         * @return std::vector<unsigned long long> \u5148\
    \u982D\u304B\u3089\u5404\u6587\u5B57\u6570\u5206\u306E\u30CF\u30C3\u30B7\u30E5\
    \n         */\n        template <typename R>\n        std::vector<unsigned long\
    \ long> build(R&& s) {\n            using std::begin, std::end;\n            return\
    \ build(begin(s), end(s));\n        }\n\n        /**\n         * @brief [l,r)\u306E\
    \u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97(O(1))\n         *\n         * @param\
    \ hash \u5148\u982D\u304B\u3089\u306E\u30CF\u30C3\u30B7\u30E5\n         * @param\
    \ l \u533A\u9593\u306E\u5DE6\u7AEF\n         * @param r \u533A\u9593\u306E\u53F3\
    \u7AEF\n         * @return unsigned long long [l,r)\u306E\u30CF\u30C3\u30B7\u30E5\
    \n         */\n        unsigned long long query(const std::vector<unsigned long\
    \ long>& hash, int l, int r) {\n            expand(r - l);\n            return\
    \ add(hash[r], MOD - mul(hash[l], power[r-l]));\n        }\n\n        friend RHString;\n\
    \    };\n\n    /**\n     * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
    \u30E5\u306B\u3088\u3063\u3066\u7BA1\u7406\u3055\u308C\u308B\u6587\u5B57\u5217\
    \u578B\n     */\n    struct RHString {\n        RollingHash& rh;\n        size_t\
    \ sz;\n        unsigned long long hash1;  //!< \u6B63\u9806\n        unsigned\
    \ long long hash2;  //!< \u9006\u9806\n        /**\n         * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n         * \u4E88\u3081RollingHash\u3092\u30A4\
    \u30F3\u30B9\u30BF\u30F3\u30B9\u5316\u3057\u3066\u304A\u304F\u5FC5\u8981\u304C\
    \u3042\u308B\n         */\n        RHString(RollingHash& rh) : rh(rh), sz(0),\
    \ hash1(0), hash2(0) {}\n        RHString(RollingHash& rh, size_t sz, unsigned\
    \ long long hash1, unsigned long long hash2) : rh(rh), sz(sz), hash1(hash1), hash2(hash2)\
    \ {}\n        RHString(const RHString& o) : rh(o.rh), sz(o.sz), hash1(o.hash1),\
    \ hash2(o.hash2) {}\n        /**\n         * @brief vector\u306A\u3069\u3067\u521D\
    \u671F\u5316\u3059\u308B\n         */\n        template <class R, std::enable_if_t<is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>, std::nullptr_t> = nullptr>\n\
    \        RHString(RollingHash& rh, R&& v) : rh(rh) {\n            using std::begin,\
    \ std::end, std::rbegin, std::rend;\n            sz = std::distance(begin(v),\
    \ end(v));\n            hash1 = rh.build(begin(v), end(v)).back();\n         \
    \   hash2 = rh.build(rbegin(v), rend(v)).back();\n        }\n        /**\n   \
    \      * @brief char\u3084unsigned long long\u306A\u3069\u3067\u521D\u671F\u5316\
    \u3059\u308B\n         */\n        template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n        RHString(RollingHash& rh, T&& x) : rh(rh) {\n          \
    \  sz = 1;\n            hash1 = x;\n            hash2 = x;\n        }\n      \
    \  /**\n         * @brief \u6587\u5B57\u5217(string, const char*, string_view)\u3067\
    \u521D\u671F\u5316\u3059\u308B\n         */\n        RHString(RollingHash& rh,\
    \ std::string_view s) : rh(rh) {\n            sz = std::distance(s.begin(), s.end());\n\
    \            hash1 = rh.build(s.begin(), s.end()).back();\n            hash2 =\
    \ rh.build(s.rbegin(), s.rend()).back();\n        }\n\n        /**\n         *\
    \ @brief \u56DE\u6587\u304B\u5426\u304B\n         */\n        bool is_palindrome()\
    \ const {\n            return hash1 == hash2;\n        }\n        size_t size()\
    \ const {\n            return sz;\n        }\n        void clear() {\n       \
    \     sz = 0;\n            hash1 = 0;\n            hash2 = 0;\n        }\n   \
    \     bool empty() const {\n            return sz == 0;\n        }\n        RHString&\
    \ operator+=(const RHString& o) {\n            assert(&rh == &o.rh);\n       \
    \     rh.expand(sz);\n            rh.expand(o.sz);\n            hash1 = rh.add(rh.mul(hash1,\
    \ rh.power[o.sz]), o.hash1);\n            hash2 = rh.add(hash2, rh.mul(o.hash2,\
    \ rh.power[sz]));\n            sz += o.sz;\n            return *this;\n      \
    \  }\n        /**\n         * @brief \u518D\u4EE3\u5165\u3059\u308B\n        \
    \ * RollingHash\u306F\u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\n         */\n        void assign(const RHString& o) {\n        \
    \    assert(&rh == &o.rh);\n            sz = o.sz;\n            hash1 = o.hash1;\n\
    \            hash2 = o.hash2;\n        }\n        /**\n         * @brief vector\u306A\
    \u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\n         */\n        template <class\
    \ R, std::enable_if_t<is_range_v<R> && !std::is_convertible_v<R, std::string_view>,\
    \ std::nullptr_t> = nullptr>\n        void assign(R&& v) {\n            using\
    \ std::begin, std::end, std::rbegin, std::rend;\n            sz = std::distance(begin(v),\
    \ end(v));\n            hash1 = rh.build(begin(v), end(v)).back();\n         \
    \   hash2 = rh.build(rbegin(v), rend(v)).back();\n        }\n        /**\n   \
    \      * @brief char\u3084unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\
    \u3059\u308B\n         */\n        template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n        void assign(T&& x) {\n            sz = 1;\n            hash1\
    \ = x;\n            hash2 = x;\n        }\n        /**\n         * @brief \u6587\
    \u5B57\u5217(string, const char*, string_view)\u3092\u518D\u4EE3\u5165\u3059\u308B\
    \n         */\n        void assign(std::string_view s) {\n            sz = std::distance(s.begin(),\
    \ s.end());\n            hash1 = rh.build(s.begin(), s.end()).back();\n      \
    \      hash2 = rh.build(s.rbegin(), s.rend()).back();\n        }\n        /**\n\
    \         * @brief \u518D\u4EE3\u5165\u3059\u308B\n         * RollingHash\u306F\
    \u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n   \
    \      */\n        RHString& operator=(const RHString& o) {\n            assign(o);\n\
    \            return *this;\n        }\n        /**\n         * @brief vector\u306A\
    \u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\n         */\n        template <class\
    \ R, std::enable_if_t<is_range_v<R> && !std::is_convertible_v<R, std::string_view>,\
    \ std::nullptr_t> = nullptr>\n        RHString& operator=(R&& v) {\n         \
    \   assign(v);\n            return *this;\n        }\n        /**\n         *\
    \ @brief char\u3084unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\
    \u308B\n         */\n        template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n        RHString& operator=(T&& x) {\n            assign(x);\n \
    \           return *this;\n        }\n        /**\n         * @brief \u6587\u5B57\
    \u5217(string, const char*, string_view)\u3092\u518D\u4EE3\u5165\u3059\u308B\n\
    \         */\n        RHString& operator=(std::string_view s) {\n            assign(s);\n\
    \            return *this;\n        }\n        friend RHString operator+(const\
    \ RHString& t1, const RHString& t2) {\n            RHString ret = t1;\n      \
    \      ret += t2;\n            return ret;\n        }\n        friend bool operator==(const\
    \ RHString& t1, const RHString& t2) {\n            assert(&t1.rh == &t2.rh);\n\
    \            return t1.sz == t2.sz && t1.hash1 == t2.hash1 && t1.hash2 == t2.hash2;\n\
    \        }\n        friend bool operator!=(const RHString& t1, const RHString&\
    \ t2) { return !(t1 == t2); }\n    };\n}  // namespace ugilib::rainbou_kpr\n"
  dependsOn:
  - ugilib/awesome_external_lib/rainbou-kpr/traits.hpp
  isVerificationFile: false
  path: ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp
  requiredBy:
  - ugilib/string/palindrome.hpp
  - tests/awesome_external_lib/rolling_hash.notest.cpp
  timestamp: '2024-05-18 17:31:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string/palindrome.test.cpp
documentation_of: ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp
layout: document
redirect_from:
- /library/ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp
- /library/ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp.html
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3092\u6271\u3046\u30D8\
  \u30C3\u30C0"
---