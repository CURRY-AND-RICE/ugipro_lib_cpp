#include <bits/stdc++.h>
#include "ugilib/graph/minimum_spanning.hpp"

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

using namespace std;

int main() {
    // speed up io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // code
    int V, E;
    cin >> V >> E;

    vector<pair<ll, pair<int, int>>> edges;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edges.push_back({w, {s, t}});
    }

    auto [res, mst_edges] = ugilib::kruskal(V, edges);
    cout << res << endl;

    return 0;
}
