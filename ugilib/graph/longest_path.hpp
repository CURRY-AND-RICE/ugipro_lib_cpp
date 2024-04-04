#pragma once

/**
 * @file longest_path.hpp
 * @brief DAGの最長パス長を求める関数の定義
 * @note トポロジカルソート結果を使うが，uginilib/graph/topological_sort.hpp に topological_sort() が定義されている
*/

#include <bits/stdc++.h>
using namespace std;

namespace ugilib {
    /**
     * @brief DAGの最長パス長を求める
     * @tparam T 整数型
     * @param g DAG
     * @param topology トポロジカルソート結果. ugilib/graph/topological_sort.hpp の topological_sort() を使う
     * @return T 最長パス長
     * @note O(V + E)
     * @note グラフdpの一種
    */
    template <typename T>
    T longest_path_length(const vector<vector<T>> &g, const vector<T> &topology) {
        static_assert(is_integral<T>::value, "T must be integral type");
        // ノードに入る辺の元のノードを記録する
        vector<vector<T>> sources(g.size());
        for (size_t i = 0; i < g.size(); i++) {
            for (const T &next : g[i]) {
                sources[next].push_back(i);
            }
        }

        // トポロジカル順序で処理する
        vector<T> lengths(g.size(), 0);  // その頂点に到達するまでの最長パスの長さ
        for (const T &node : topology) {
            for (const T &source : sources[node]) {
                lengths[node] = max(lengths[node], lengths[source] + 1);
            }
        }

        return *max_element(lengths.begin(), lengths.end());
    }
}  // namespace ugilib