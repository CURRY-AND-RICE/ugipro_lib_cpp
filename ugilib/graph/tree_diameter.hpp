#pragma once

/**
 * @file tree_diameter.hpp
 * @brief 木の直径を求める関数の定義
 */

#include <bits/stdc++.h>

namespace ugilib {
    using namespace std;
    /**
     * @brief 各頂点の距離を求めるDFS. farthest_node_from() で使用
     */
    template <typename node_t>
    void dfs_dist(node_t node, node_t parent, vector<int>& dists, const vector<vector<node_t>>& edges) {
        if (parent == -1) dists[node] = 0;
        else dists[node] = dists[parent] + 1;

        for (auto next : edges[node]) {
            if (next == parent) continue;
            dfs_dist(next, node, dists, edges);
        }
    }

    /**
     * @brief start から最も遠い頂点とその距離を求める
     * @tparam node_t 頂点の型
     * @param start 開始頂点
     * @param edges 木の隣接リスト
     * @return pair<node_t, int> 最も遠い頂点とその距離
     * @note O(V)
     */
    template <typename node_t>
    pair<node_t, int> farthest_node_from(node_t start, vector<vector<node_t>>& edges) {
        vector<int> dists(edges.size(), -1);

        dfs_dist(start, -1, dists, edges);
        auto farthest_node = max_element(dists.begin(), dists.end()) - dists.begin();
        return {farthest_node, dists[farthest_node]};
    }

    /**
     * @brief 木の直径を求める
     * @tparam node_t 頂点の型
     * @param edges 木の隣接リスト
     * @return int 木の直径
     * @note O(V)
     */
    template <typename node_t>
    int tree_diameter(vector<vector<node_t>>& edges) {
        auto [start, _] = farthest_node_from(0, edges);
        auto [end, diameter] = farthest_node_from(start, edges);
        return diameter;
    }
}  // namespace ugilib