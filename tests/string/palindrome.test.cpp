#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"
#include "ugilib/base/definitions.hpp"
#include "ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp"
#include "ugilib/string/palindrome.hpp"
// #include "atcoder/segtree.hpp"

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
    // for string
    void p(const string& s) { cout << s << endl; }
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
    string s = rd::i<string>();

    ugilib::rainbou_kpr::RollingHash rh;
    vector<unsigned long long> forward_hash = rh.build(s.begin(), s.end());
    vector<unsigned long long> backward_hash = rh.build(s.rbegin(), s.rend());

    for (int i = 0; i < 2*s.size() - 1; i++) {
        int center = i / 2;
        int is_range_odd = i % 2 == 0;  // 中心が特定の値の時はそれをスキップする

        int ok = 0;
        int ng = s.size();
        while (ok + 1 < ng) {
            int mid = (ok + ng) / 2;

            int left = center - (mid - 1 + is_range_odd);
            int right = center + mid + 1;

            if (ugilib::is_palindrome_lr(rh, forward_hash, backward_hash, left, right)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        int length = ok * 2 + 1 * is_range_odd;
        cout << length << " \n"[i+1 == 2*s.size() - 1];
    }
}

// セグ木に載せるとO(N log^2 N)でクエリを処理できる
// でもちゃんとやればO(N log N)でできる
/**
ugilib::rainbou_kpr::RollingHash rh;
using S = ugilib::rainbou_kpr::RHString;
S op(S a, S b) {
    return a + b;
}
S e() {
    return S(rh);
}

int main() {
    auto& cin = _cin;
    // speed up io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // code
    string s = rd::i<string>();
    vector<S> initializer;
    for (char c : s) {
        initializer.emplace_back(rh, c);
    }
    atcoder::segtree<S, op, e> sgt(initializer);

    ll N = s.size();
    for (int i = 0; i < 2*N - 1; i++) {
        bool is_interval = (i % 2 == 1);

        int ok = 0;
        int ng = (int)N;
        while (ok + 1 < ng) {
            int mid = (ok + ng) / 2;

            int left = i/2 - mid + is_interval;
            int right = i/2 + mid + 1;
            if (left < 0 || N < right) {
                ng = mid;
            } else if (sgt.prod(left, right).is_palindrome()) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        int length = ok * 2 + (1 ^ is_interval);
        cout << length << " \n"[i+1 == 2*N - 1];
        // cout << "i: " << i << ", length: " << length << endl;
        // cout << "ok: " << ok << ", ng: " << ng << endl;
        // cout << s.substr(i/2 - ok + is_interval, length) << endl;
    }

    return 0;
}
*/