#include <bits/stdc++.h>
#include "ugilib/graph/dijkstra.hpp"

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"

using namespace std;

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

    auto &&costs = ugilib::dijkstra(V, r, graph);
    rep(i, V) {
        if (costs[i] == INF) cout << "INF\n";
        else cout << costs[i] << '\n';
    }

    return 0;
}
