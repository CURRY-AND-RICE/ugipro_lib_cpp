#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/13/ALDS1_13_C"

#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"
#include "ugilib/base/definitions.hpp"
#include "ugilib/std_util/hashes.hpp"

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

const int SIDE = 4;
const int DEPTH_LIMIT = 45;
using Board = array<array<short, SIDE>, SIDE>;

// A-star algorithm
int main() {
    auto& cin = _cin;
    // speed up io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // code
    Board initial;
    Board ideal;
    short sy, sx;
    rep(i, 4) rep(j, 4) {
        cin >> initial[i][j];
        ideal[i][j] = (SIDE*i + j + 1) % 16;

        if (initial[i][j] == 0) {
            sy = i;
            sx = j;
        }
    }

    // A*スコア、盤面、コスト、ゼロ位置y, x
    using elements = tuple<short, Board, short, short, short>;
    priority_queue<elements, vector<elements>, greater<>> pq;
    unordered_map<Board, short, ugilib::array_hash> costs;
    pq.push({0, initial, 0, sy, sx});
    costs[initial] = 0;

    int ans = -1;
    pair<short, short> dyxs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!pq.empty()) {
        auto [score, board, cost, zy, zx] = pq.top();
        pq.pop();

        if (costs[board] > cost) continue;
        if (board == ideal) {
            ans = cost;
            break;
        }

        for (auto [dy, dx] : dyxs) {
            short ny = zy + dy;
            short nx = zx + dx;
            if (ny < 0 || SIDE <= ny || nx < 0 || SIDE <= nx) continue;

            swap(board[zy][zx], board[ny][nx]);
            if (costs.count(board) == 0 || costs[board] > cost + 1) {
                costs[board] = cost + 1;
                short h = 0;
                rep(i, 4) rep(j, 4) {
                    if (board[i][j] == 0) continue;
                    short num = board[i][j];
                    short ideal_y = (num - 1) / 4;
                    short ideal_x = (num - 1) % 4;
                    h += abs((short)i - ideal_y) + abs((short)j - ideal_x);
                }
                pq.push({cost + 1 + h, board, cost + 1, ny, nx});
            }
            swap(board[zy][zx], board[ny][nx]);
        }
    }

    assert(ans != -1);
    cout << ans << endl;

    return 0;
}
