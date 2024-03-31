#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/definitions.hpp"
#include "ugilib/iteration/next_combination.hpp"

using namespace std;

namespace ugilib {
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
    template <typename Func>
    void exec_all_combinations(const size_t &num_items, const size_t &num_pick, Func f) {
        vector<size_t> indices(num_pick);
        iota(indices.begin(), indices.end(), 0);
        do {
            bool will_break = f(indices);
            if (will_break) break;
        } while (next_combination(indices, num_items));
    }
}  // namespace ugilib
