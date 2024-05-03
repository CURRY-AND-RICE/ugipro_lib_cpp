#pragma once

/**
 * @file coord_compress.hpp
 * @brief 座標圧縮の実装
*/

#include <bits/stdc++.h>
using namespace std;

namespace ugilib {
    /**
     * @brief 座標圧縮
     * @tparam T 座標圧縮したい型
     * @param v 圧縮したい配列
     * @param descending trueの場合、降順に圧縮する
     * @return unordered_map<T, ll> 元の値から圧縮した値へのマップ
     * @note 圧縮後の値は0-indexed
     * @note O(NlogN)
    */
    template <typename T>
    unordered_map<T, int> compress(const vector<T>& v, const bool descending = false) {
        // ソート
        vector<T> sorted_unique_v(v.begin(), v.end());  // コピー
        if (descending) {
            sort(sorted_unique_v.rbegin(), sorted_unique_v.rend());
        } else {
            sort(sorted_unique_v.begin(), sorted_unique_v.end());
        }
        // ユニークにする. ソート済みが前提
        auto end_unique = unique(sorted_unique_v.begin(), sorted_unique_v.end());  // ユニーク要素を前に詰める
        sorted_unique_v.erase(end_unique, sorted_unique_v.end());  // 重複要素を削除
        // 圧縮
        unordered_map<T, int> compressed;
        rep(i, sorted_unique_v.size()) {
            compressed[sorted_unique_v[i]] = i;
        }
        return compressed;
    }
} // namespace ugilib
