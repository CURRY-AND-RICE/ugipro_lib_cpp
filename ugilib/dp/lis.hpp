#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/constants.hpp"
using namespace std;

namespace ugilib {
    /**
     * @brief 最長増加部分列
     * @tparam T vectorの要素の型
     * @param A vector
     * @param inf 無限大
     * @return pair<size_t, vector<T>> (最長増加部分列の長さ, 最長増加部分列(一意ではない))
     * @note O(n log n). n = A.size()
    */
    template <typename T>
    pair<size_t, vector<T>> longest_increasing_subsequence(const vector<T> &A, const T inf = ugilib::constants::INF<T>) {
        static_assert(is_signed<T>::value, "T must be signed type.");  // Tは符号付き型である必要がある
        // dp[i]: 長さがiであるような増加部分列の最後の要素の最小値
        vector<T> dp(A.size() + 1, inf);  // 1-indexed
        vector<size_t> indices(A.size());  // indices[i]: A[i]がdpのどこに入るか
        dp[0] = -1;
        for (size_t i = 0; i < A.size(); i++) {
            size_t idx = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
            dp[idx] = A[i];
            indices[i] = idx;
        }

        // infの手前まで部分増加列の最終要素が入っている
        const size_t lis_length = find(dp.begin(), dp.end(), inf) - dp.begin() - 1;
        // 部分増加列の復元
        vector<T> lis(lis_length);
        size_t target = lis_length;
        for (int i = A.size() - 1; i >= 0; i--) if (indices[i] == target) lis[--target] = A[i];

        return {lis_length, lis};
    }
}  // namespace ugilib
