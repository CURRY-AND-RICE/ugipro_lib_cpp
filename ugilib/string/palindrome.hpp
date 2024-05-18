#pragma once

#include <bits/stdc++.h>
#include "ugilib/awesome_external_lib/rainbou-kpr/rolling-hash.hpp"

namespace ugilib {
    using namespace std;
    /**
     * @brief 列の[l, r)が回文かどうかを判定する
     * @param rh ハッシュ生成に使ったRollingHash
     * @param forward_hash 順方向のハッシュ
     * @param backward_hash 逆方向のハッシュ
     * @param l 左端
     * @param r 右端
     * @return 回文ならtrue. 範囲が不正な場合や回文ではない場合にfalseを返す
     * @note O(1)
    */
    bool is_palindrome_lr(ugilib::rainbou_kpr::RollingHash &rh, const vector<unsigned long long> &forward_hash, const vector<unsigned long long> &backward_hash, const int l, const int r) {
        const int s_size = forward_hash.size() - 1;

        if (l < 0 || s_size < r) return false;  // 0-indexed, [l, r)
        if (r <= l) return false;

        // 範囲が奇数の場合は中央をスキップ
        bool is_range_odd = (r - l) % 2 == 1;

        // 範囲を計算
        int mid = (l + r) / 2;
        pair<int, int> left = {l, mid};  // [l, mid)
        pair<int, int> right = {mid + is_range_odd, r};  // [mid, r)

        // ハッシュ値を取得
        unsigned long long left_hash = rh.query(forward_hash, left.first, left.second);
        unsigned long long right_hash = rh.query(backward_hash, s_size - right.second, s_size - right.first);

        return left_hash == right_hash;
    }
}
