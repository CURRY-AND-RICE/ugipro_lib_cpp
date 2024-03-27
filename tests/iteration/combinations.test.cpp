#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_B"

#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"
#include "ugilib/base/definitions.hpp"
#include "ugilib/iteration/combinations.hpp"

using namespace std;

// debug settings
// #define DEBUG
#ifdef DEBUG
// debug input
string _INPUT = R"(
5
1 2 3 4 5
)";
auto _cin = stringstream(_INPUT.substr(1)); // remove '\n' at _INPUT[0]
#else
// standard input
auto& _cin = cin;
#endif

// speed up
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// reader
struct rd {
    // T
    template<typename T> static T i() { T x; _cin >> x; return x; }  // T item
    // vector<T>
    template<typename T> static vector<T> v(int n) {vector<T> v(n); rep(i, n) _cin >> v[i]; return v;}  // vector<T>
    // vector<pair<T, T>>
    template<typename T> static vector<pair<T, T>> vp(int n) {vector<pair<T, T>> v(n); rep(i, n) _cin >> v[i].first >> v[i].second; return v;}  // vector<pair<T, T>>
    // tuple
    template<typename... Args> static tuple<Args...> t() {
        tuple<Args...> values;
        apply([](auto&... args) { ((_cin >> args), ...); }, values);
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
    auto& cin = _cin;
    // speed up io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // code
    while (true) {
        auto [n, x] = rd::t<int, int>();
        if (n == x && x == 0) break;

        int ans = 0;
        auto f = [&](const vector<size_t> &indices) {
            int y = 0;
            for (const auto i : indices) y += i+1;  // [0, n-1]のインデックスが渡されるので，それぞれ1を足して[1, n]にする
            if (y == x) ans += 1;
            return false;
        };
        ugilib::exec_all_combinations(n, 3, f);
        cout << ans << endl;
    }

    return 0;
}
