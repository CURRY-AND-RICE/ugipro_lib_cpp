#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"

using namespace std;


/// cut begin
namespace ugilib {
/**
 * @brief ダイクストラ法
 * @param n グラフの頂点数
 * @param start 始点
 * @param graph グラフ. vector<pair<int, ll>> で隣接頂点とコストを表す
 * @return 始点から各頂点までの最短距離
 * @note O((E+V)logV)
*/
template<typename weight_type>
vector<weight_type> dijkstra(int n, int start, const vector<vector<pair<int, weight_type>>>& graph) {
    vector<weight_type> costs(n, INF);
    costs[start] = 0;

    priority_queue<pair<weight_type, int>, vector<pair<weight_type, int>>, greater<>> next_nodes;
    next_nodes.push({0, start});

    while (!next_nodes.empty()) {
        auto [cost, node] = next_nodes.top(); next_nodes.pop();
        if (cost > costs[node]) continue;

        for (auto [next_node, next_cost] : graph[node]) {
            auto new_cost = cost + next_cost;
            if (new_cost < costs[next_node]) {
                costs[next_node] = cost + next_cost;
                next_nodes.push({costs[next_node], next_node});
            }
        }
    }

    return costs;
}
} // namespace ugilib
/// cut end
