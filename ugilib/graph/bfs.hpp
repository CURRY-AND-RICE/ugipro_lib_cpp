#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"

using namespace std;


/// cut begin
namespace ugilib {
/**
 * @brief 幅優先探索
 * @param n グラフの頂点数
 * @param start 始点
 * @param graph グラフ. vector<pair<int, weight_type>> で隣接頂点とコストを表す
 * @param weight_inf 無限大の値. パスが存在しない場合のコスト
 * @return 始点から各頂点までの最短距離
 * @note O(E+V)
*/
template <typename weight_type>
vector<weight_type> bfs(int n, int start, const vector<vector<pair<int, weight_type>>> &graph, weight_type weight_inf = ugilib::constants::INF<weight_type>) {
    vector<weight_type> costs(n, weight_inf);
    costs[start] = 0;

    queue<int> next_nodes;
    next_nodes.push(start);

    while (!next_nodes.empty()) {
        auto node = next_nodes.front(); next_nodes.pop();
        auto cost = costs[node];

        for (const auto [next_node, next_cost] : graph[node]) {
            auto new_cost = cost + next_cost;
            if (new_cost < costs[next_node]) {
                costs[next_node] = new_cost;
                next_nodes.push(next_node);
            }
        }
    }

    return costs;
}
}  // namespace ugilib
