#pragma once

/**
 * @file topological_sort.hpp
 * @brief トポロジカルソート，入次数計算関数の定義
*/

#include <bits/stdc++.h>
using namespace std;

namespace ugilib {
    /**
     * @brief DAGの各頂点の入次数を計算する
     * @tparam T 整数型
     * @param g 有向グラフ
     * @return vector<T> 入次数リスト
     * @note O(V + E)
     */
    template <typename T>
    vector<T> calc_indegrees(const vector<vector<T>> &g) {
        static_assert(is_integral<T>::value, "T must be integral type");
        vector<T> indeg(g.size(), 0);
        for (const vector<T> &edges_from_u : g) {
            for (const T &v : edges_from_u) {
                indeg[v]++;
            }
        }
        return indeg;
    }

    /**
     * @brief DAGのトポロジカルソート
     * @tparam T 整数型
     * @param g DAG
     * @return vector<T> トポロジカルソート結果
     * @note O(V + E)
    */
    template <typename T>
    vector<T> topological_sort(const vector<vector<T>> &g) {
        static_assert(is_integral<T>::value, "T must be integral type");
        // 入次数の計算
        vector<T> indegs = ugilib::calc_indegrees(g);

        // トポロジカル順序を決定する
        vector<T> topology;
        queue<T> start_nodes;
        for (size_t i = 0; i < indegs.size(); i++) {
            if (indegs[i] == 0) start_nodes.push(i);
        }
        while (!start_nodes.empty()) {
            // 入次数0の頂点の順序を確定
            T node = start_nodes.front(); start_nodes.pop();
            topology.push_back(node);

            // 頂点・辺を削除する
            for (const T &next : g[node]) {  // この頂点から出る全ての辺を削除
                if (--indegs[next] == 0) {  // それによって入次数が0になったら
                    start_nodes.push(next);  // 順序を確定できる
                }
            }
        }

        assert(topology.size() == g.size());  // DAGでない場合はトポロジカルソートできない
        return topology;
    }
}  // namespace ugilib