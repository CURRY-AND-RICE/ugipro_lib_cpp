#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"
#include "ugilib/bit/bit_util.hpp"

using namespace std;

namespace ugilib {
    /**
     * @brief 巡回セールスマン問題を解くDP
     * @param n 都市数
     * @param start 始点
     * @param graph グラフ. vector<pair<int, weight_t>> で隣接頂点とコストを表す
     * @param weight_inf 無限大の値. パスが存在しない場合のコスト
     * @return 始点から各頂点を一度だけ通って戻ってくる最小コスト
     * @note O(2^n * n^2)
    */
    template <typename weight_t>
    weight_t tsp_bitDP(int n, int start, const vector<vector<pair<int, weight_t>>> &graph, const weight_t weight_inf = ugilib::constants::INF<weight_t>) {
        const int num_states = (1 << n);
        // dp[これまでに取った都市集合. [0, 2^n-1]][現在地. [0, n-1]]
        vector<vector<weight_t>> dp(num_states, vector<weight_t>(n, weight_inf));
        dp[0][start] = 0;

        // 全状態についてDPする
        for (int i = 0; i < num_states; i++) {
            // 状態をビット表現する
            auto bits = ugilib::num_to_bits(i, n);
            // 今どの都市にいるか
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == weight_inf) continue;  // この状態に辿り着かない場合
                // 次どの都市に行くか
                for (const auto [node, cost] : graph[j]) {
                    if (bits[node]) continue;  // 訪問済み
                    // 訪問する
                    bits[node] = true;
                    auto &dest = dp[ugilib::bits_to_num(bits)][node];
                    dest = min(dest, dp[i][j] + cost);
                    bits[node] = false;
                }
            }
        }

        return dp[num_states-1][start];  // 全状態訪問後にstartに戻って来る最小コスト
    }
}  // namespace ugilib
