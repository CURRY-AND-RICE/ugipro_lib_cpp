#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"

using namespace std;

namespace ugilib {
    /**
     * @brief 編集距離
     * @tparam T vectorの要素の型. stringだったらvector<char>で渡す
     * @param v1 vector1
     * @param v2 vector2
     * @return vector<vector<ll>> dp[i][j]: v1のi文字目までとv2のj文字目までの編集距離
     * @note O(nm). n = v1.size(), m = v2.size()
     * @details
     * auto dp = edit_distance(v1, v2);
     * cout << dp[v1.size()][v2.size()] << endl;
     * cout << dp.back().back() << endl;
    */
    template <typename T>
    vector<vector<ll>> edit_distance(const vector<T>& v1, const vector<T>& v2) {
        int n = v1.size();
        int m = v2.size();
        // dp[i][j]: v1のi文字目までとv2のj文字目までの編集距離
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));

        // 空文字列との編集距離
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i+1][j+1] = min(dp[i][j+1] + 1, dp[i+1][j] + 1);  // v1 or v2どちらか1文字追加
                if (v1[i] == v2[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);  // v1 and v2両方から1文字追加
                else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 1);  // v1 and v2両方から1文字追加し, 片方を変更する
            }
        }

        return dp;
    }
}  // namespace ugilib
