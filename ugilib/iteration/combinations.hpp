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

/**
 * @brief num_items個の中からnum_pick個選ぶ組み合わせを全探索し, それぞれに対して関数fを実行する
 * @tparam Func ラムダ式
 * @param num_items 選択対象全体の要素数
 * @param num_pick 選択する要素数
 * @param f 実行する関数. trueを返すと探索を打ち切る
 * @details ラムダ式には選択した要素のインデックスが昇順で渡される
 * @example
 * auto f = [&](const vector<size_t> &indices) {
 *    for (const auto &i : indices) {
 *       cout << i << " ";
 *   }
 *  cout << endl;
 * return false;
 * };
 * exec_all_combination(5, 3, f);
*/
template<typename Func>
void exec_all_combinations(const size_t &num_items, const size_t &num_pick, Func f) {
    vector<size_t> indices(num_pick);
    iota(indices.begin(), indices.end(), 0);
    do {
        bool will_break = f(indices);
        if (will_break) break;
    } while (next_combination(indices, num_items));
}
}  // namespace ugilib
