#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"

using namespace std;

namespace ugilib {
    /**
     * @brief ダイクストラ法
     * @param n グラフの頂点数
     * @param start 始点
     * @param graph グラフ. vector<pair<int, weight_t>> で隣接頂点とコストを表す
     * @param weight_inf 無限大の値. パスが存在しない場合のコスト
     * @return 始点から各頂点までの最短距離
     * @note O((E+V)logV)
    */
    template<typename weight_t>
    vector<weight_t> dijkstra(int n, int start, const vector<vector<pair<int, weight_t>>>& graph, const weight_t weight_inf = ugilib::constants::INF<weight_t>) {
        vector<weight_t> costs(n, weight_inf);
        costs[start] = 0;

        priority_queue<pair<weight_t, int>, vector<pair<weight_t, int>>, greater<>> next_nodes;
        next_nodes.push({0, start});

        while (!next_nodes.empty()) {
            auto [cost, node] = next_nodes.top(); next_nodes.pop();
            if (cost > costs[node]) continue;

            for (const auto [next_node, next_cost] : graph[node]) {
                auto new_cost = cost + next_cost;
                if (new_cost < costs[next_node]) {
                    costs[next_node] = new_cost;
                    next_nodes.push({costs[next_node], next_node});
                }
            }
        }

        return costs;
    }
} // namespace ugilib
