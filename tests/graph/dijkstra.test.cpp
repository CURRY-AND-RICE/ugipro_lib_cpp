#include <bits/stdc++.h>
#include "lib/graph/dijkstra.cpp"

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)  // rep macro
#define all(v) begin(v), end(v)  // all iterator
#define ur auto&&  // universal reference. care needed

// const ll INF = 1LL << 60;  // infinity

int main() {
    // speed up io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // code
    ll V, E, r;
    cin >> V >> E >> r;

    vector<vector<pair<int, ll>>> graph(V);

    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back({t, d});
    }

    auto &&costs = dijkstra(V, r, graph);
    rep(i, V) {
        if (costs[i] == INF) cout << "INF\n";
        else cout << costs[i] << '\n';
    }

    return 0;
}
