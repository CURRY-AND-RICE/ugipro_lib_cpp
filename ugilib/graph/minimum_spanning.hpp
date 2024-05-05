#pragma once

/**
 * @file minimum_spanning.hpp
 * @brief 最小全域木を求める関数を提供
 *
 * ## 関数一覧
 * - `kruskal(n, edges)` : クラスカル法により最小全域木を求める
*/

#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"
#include <atcoder/dsu>

using namespace std;

namespace ugilib {
    /**
     * @brief クラスカル法により最小全域木を求める
     * @tparam weight_t 辺の重みの型
     * @param n 頂点数
     * @param edges 辺のリスト. ソートするのでコピー渡し
     * @return 最小全域木の重みと含まれる辺のリスト
     * @note 辺のリストは {重み, {頂点1, 頂点2}} の形式で与える
     * @note 辺のリストは重みの昇順にソートされる
     * @note O(E log E). E は辺の数. ボトルネックはソート
    */
    template <typename weight_t>
    tuple<weight_t, vector<pair<int, int>>> kruskal(int n, vector<pair<weight_t, pair<int, int>>> edges) {
        // ソート
        sort(edges.begin(), edges.end());

        // クラスカル法
        // 重みの小さい順に辺を追加していく
        atcoder::dsu uf(n);
        vector<pair<int, int>> mst_edges;
        weight_t res = 0;
        for (auto [w, e] : edges) {
            auto [u, v] = e;
            if (uf.same(u, v)) continue;
            uf.merge(u, v);
            mst_edges.emplace_back(u, v);
            res += w;
            if (uf.size(u) == n) break;
        }

        // 全域木ができなかった場合
        if (uf.size(0) != n) return {-1, {}};
        // 最小全域木の重みと辺のリストを返す
        return {res, mst_edges};
    }
}