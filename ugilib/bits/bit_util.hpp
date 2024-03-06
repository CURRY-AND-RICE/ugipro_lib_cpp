#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"

using namespace std;

namespace ugilib {
/**
 * @brief 数値 -> ビット配列
 * @param num ビット配列にするための数値
 * @param digit ビット数
 * @return vector<bool> 変換されたビット配列. 0番目が一番下の桁
 * @details 数値を指定桁のビット配列に変換する
*/
vector<bool> num_to_bits(const ll num, const size_t &digit) {
    vector<bool> bits(digit);
    for (int i = 0; i < digit; i++) {
        bits[i] = (num >> i) & 1U;
    }
    return bits;
}

/**
 * @brief ビット配列 -> 数値
 * @param bits 数値にするためのビット配列. 0番目が一番下の桁
 * @return ll 変換された数値
 * @details ビット配列を数値に戻す. num_to_bitsの逆変換
*/
ll bits_to_num(const vector<bool> &bits) {
    ll num = 0;
    for (int i = 0; i < bits.size(); i++) {
        num += bits[i] << i;
    }
    return num;
}
}  // namespace ugilib
