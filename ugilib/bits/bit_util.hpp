#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"

using namespace std;

namespace ugilib {
/**
 * @brief num_to_bits
 * @param num an integer to be converted to bits
 * @param digit the number of bits
 * @return vector<bool> bits of num
 * @details convert an integer to bits
*/
vector<bool> num_to_bits(const ll num, const size_t &digit) {
    vector<bool> bits(digit);
    for (int i = 0; i < digit; i++) {
        bits[i] = (num >> i) & 1U;
    }
    return bits;
}

/**
 * @brief bits_to_num
 * @param bits a vector of bits
 * @return ll an integer of bits
 * @details convert bits to an integer
*/
ll bits_to_num(const vector<bool> &bits) {
    ll num = 0;
    for (int i = 0; i < bits.size(); i++) {
        num += bits[i] << i;
    }
    return num;
}
}  // namespace ugilib
