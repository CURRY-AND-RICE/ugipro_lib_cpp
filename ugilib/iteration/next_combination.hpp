#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/definitions.hpp"

using namespace std;

namespace ugilib {
    /**
     * @brief 次の組み合わせを生成する
     * @param indices 現在の組み合わせ
     * @param num_items 全体の要素数
     * @return bool 次の組み合わせが存在するかどうか
     * @details 例えば, indices = {0, 1, 2}, num_items = 5の場合, 次の組み合わせは{0, 1, 3}となる
     * @details これをラップしたものがexec_all_combination
    */
    bool next_combination(vector<size_t> &indices, const size_t &num_items) {
        const int num_pick = indices.size();
        for (signed i = num_pick - 1; i >= 0; i--) {
            if (indices[i] < num_items - num_pick + i) {
                indices[i]++;
                for (size_t j = i + 1; j < num_pick; j++) {
                    indices[j] = indices[j - 1] + 1;
                }
                return true;
            }
        }
        return false;
    }
} // namespace ugilib