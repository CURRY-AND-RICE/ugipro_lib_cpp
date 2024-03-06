#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"

using namespace std;


/// cut begin
namespace ugilib {
/**
 * @brief 0or1幅優先探索. 01BFS
 * @param n グラフの頂点数
 * @param start 始点
 * @param graph グラフ. vector<pair<int, weight_type>> で隣接頂点とコストを表す. コストは0 or 1
 * @param weight_inf 無限大の値. パスが存在しない場合のコスト
 * @return 始点から各頂点までの最短距離
 * @note O(E+V)
 * @todo 01BFS問題でのテストを書く
*/
template <typename weight_type>
vector<weight_type> bfs01(int n, int start, const vector<vector<pair<int, weight_type>>> &graph, weight_type weight_inf = ugilib::constants::INF<weight_type>) {
    vector<weight_type> costs(n, weight_inf);
    costs[start] = 0;

    deque<int> next_nodes;
    next_nodes.push_back(start);

    while (!next_nodes.empty()) {
        auto node = next_nodes.front(); next_nodes.pop_front();
        auto cost = costs[node];

        for (const auto [next_node, next_cost] : graph[node]) {
            auto new_cost = cost + next_cost;
            if (new_cost < costs[next_node]) {
                costs[next_node] = new_cost;
                // 0or1幅優先探索の場合, コストが0の場合は前から入れ, 1の場合は後ろに入れる
                if (next_cost == 0) next_nodes.push_front(next_node);
                else next_nodes.push_back(next_node);
            }
        }
    }

    return costs;
}
}  // namespace ugilib
