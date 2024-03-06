#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A"


#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"
#include "ugilib/base/definitions.hpp"
#include "ugilib/bits/bit_exhaustive_search.hpp"

using namespace std;

// speed up
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// reader
struct rd {
    static ll i() {ll i; cin >> i; return i;}  // long long
    static ld d() {ld d; cin >> d; return d;}  // long double
    static string s() {string s; cin >> s; return s;}  // string
    static char c() {char c; cin >> c; return c;}  // char
    static vector<ll> vi(int n) {vector<ll> v(n); rep(i, n) cin >> v[i]; return v;}  // vector<long long>
    static vector<pair<ll, ll>> g(int n) {vector<pair<ll, ll>> v(n); rep(i, n) cin >> v[i].first >> v[i].second; return v;}  // vector<pair<long long, long long>>
    // tuple
    template<typename... Args> static tuple<Args...> t() {
        tuple<Args...> values;
        apply([](auto&... args) { ((cin >> args), ...); }, values);
        return values;
    }
};

// debug print utility
namespace deb {
    #include <cxxabi.h>
    // demangle type name
    string demangle(const char* name) {
        int status = -4;
        unique_ptr<char, void(*)(void*)> res{
            abi::__cxa_demangle(name, NULL, NULL, &status),
            free
        };
        return (status == 0) ? string(res.get()) : name ;
    }
    // meta functions for type traits
    template<typename T>
    constexpr bool isArithmeticContainer() { return is_arithmetic<typename T::value_type>::value; }
    // for SFINAE
    template<typename T, typename = void> struct has_key_and_mapped_type : false_type {};
    template<typename T> struct has_key_and_mapped_type<T, void_t<typename T::key_type, typename T::mapped_type>> : true_type {};
    // for map or unordered_map
    template<typename T>
    constexpr bool isMapLike() { return has_key_and_mapped_type<T>::value; }

    // for values
    template<typename T, typename enable_if<is_arithmetic<T>::value, nullptr_t>::type = nullptr>
    void p(const T& x) { cout << x << " "; }
    // for pairs
    template <typename T, typename S>
    void p(const pair<T, S>& _p){ p(_p.first); p(_p.second); cout << endl; }
    // for containers
    template<typename T,  typename enable_if<!is_arithmetic<T>::value, nullptr_t>::type = nullptr>
    void p(const T& container) {
        // map and unordered_map
        if constexpr (isMapLike<T>()) {
            cout << demangle(typeid(T).name()) << ":" << endl;
            for (const auto& kv : container) {
                cout << "[" << kv.first << "] => ";
                p(kv.second);
                if constexpr (is_arithmetic_v<typename T::mapped_type>) cout << endl;
            }
        // vector or set or others
        } else {
            if constexpr (!isArithmeticContainer<T>()) cout << demangle(typeid(T).name()) << ":" << endl;
            for (auto it = begin(container); it != end(container); ++it) {
                p(*it);
            }
            if constexpr (isArithmeticContainer<T>()) cout << endl;
        }
    }
};  // namespace deb

int main() {
    // speed up io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // code
    ll n = rd::i();
    auto a = rd::vi(n);
    ll q = rd::i();
    auto m = rd::vi(q);

    unordered_set<ll> numbers;
    auto f = [&](const auto &&bits) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (bits[i]) sum += a[i];
        }
        numbers.insert(sum);
        return false;
    };
    ugilib::bit_exhaustive_search(n, f);

    rep(i, q) {
        if (numbers.find(m[i]) != numbers.end()) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
