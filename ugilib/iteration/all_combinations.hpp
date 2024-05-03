#pragma once

/**
 * @file all_combinations.hpp
 * @brief 全ての順列/組み合わせに対する処理を簡略化する関数
 *
 * ## 関数一覧
 * - `exec_all_combinations(num_items, num_pick, f)` : 全ての組み合わせに対して指定された関数を実行します.
 * - `exec_all_permutations(num_items, num_pick, f)` : 全ての順列に対して指定された関数を実行します.
 */

#include <bits/stdc++.h>
#include "ugilib/base/definitions.hpp"
#include "ugilib/iteration/next_combination.hpp"

using namespace std;

namespace ugilib {
    /**
     * @brief 全てのCombinationに対して関数を実行する
     * @tparam Func 実行操作のラムダ式
     * @param num_items 選択対象全体の要素数
     * @param num_pick 選択する要素数
     * @param f 実行する関数. trueを返すと探索を打ち切る
     * @return 途中で探索を打ち切った場合はtrue, それ以外はfalse
     * @details ラムダ式には選択した要素のインデックスが昇順で渡される
     * @details num_items個の中からnum_pick個選ぶ組み合わせを全探索し, それぞれに対して関数fを実行する
     * @example
     * auto f = [&](const vector<size_t> &indices) {
     *    for (const auto &i : indices) {
     *       cout << i << " ";
     *    }
     *    cout << endl;
     *    return false;
     * };
     * exec_all_combination(5, 3, f);
    */
    template <typename Func>
    bool exec_all_combinations(const size_t &num_items, const size_t &num_pick, Func f) {
        vector<size_t> indices(num_pick);
        iota(indices.begin(), indices.end(), 0);
        do {
            bool will_break = f(indices);
            if (will_break) return true;
        } while (next_combination(indices, num_items));
        return false;
    }

    /**
     * @brief 全てのPermutationに対して関数を実行する. 順列に存在しうる要素数より, 実際の要素数が小さくても実行可能
     * @tparam Func 実行操作のラムダ式
     * @param num_items 選択対象全体の要素数
     * @param num_pick 選択する要素数
     * @param f 実行する関数. trueを返すと探索を打ち切る
     * @return 途中で探索を打ち切った場合はtrue, それ以外はfalse
     * @details ラムダ式には選択した要素のインデックスの順列が渡される
     * @details num_items個の中からnum_pick個選ぶ順列を全探索し, それぞれに対して関数fを実行する
     * @details next_permutation との違いは, 選択対象全体の要素数よりも実際に選択する要素数が少ない場合でも実行可能な点
     * @details num_items choose num_pick の組み合わせを全探索する
     * @example
     * auto f = [&](const vector<size_t> &indices) {
     *   for (const auto &i : indices) {
     *      cout << i << " ";
     *   }
     *   cout << endl;
     *   return false;
     * };
     * exec_all_permutations(5, 3, f);
    */
    template <typename Func>
    bool exec_all_permutations(const size_t &num_items, const size_t &num_pick, Func f) {
        // 全要素からnum_pick個だけ選ばれる
        vector<bool> mask(num_items, false);
        fill(mask.begin(), mask.begin() + num_pick, true);  // 選ばれる要素のマスク

        // 途中終了フラグ
        bool will_break = false;
        do {
            // maskする
            vector<size_t> permutation;
            for (int i = 0; i < mask.size(); i++) {
                if (mask[i]) permutation.push_back(i);
            }

            // mask要素で順列全てに対して操作を行う
            do {
                will_break = f(permutation);
                if (will_break) return true;  // 途中終了
            } while (next_permutation(permutation.begin(), permutation.end()));
        } while (prev_permutation(mask.begin(), mask.end()));

        return false;  // 全探索終了
    }
}  // namespace ugilib
