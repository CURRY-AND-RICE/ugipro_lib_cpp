#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/definitions.hpp"

namespace ugilib {
    /**
     * @brief 二つの長方形の重なりを判定
     * @param a 長方形1の座標 (ymin, xmin, ymax, xmax)
     * @param b 長方形2の座標 (ymin, xmin, ymax, xmax)
     * @return 重なっているかどうか. 点で接している場合もtrue
     * @details 4つの座標は閉区間で表す. つまり，(ymin, xmin)も(ymax, xmax)も長方形に含まれる
    */
    template <typename T>
    bool is_overlapping(const std::array<T, 4> &a, const std::array<T, 4> &b) {
        auto [ymin1, xmin1, ymax1, xmax1] = a;
        auto [ymin2, xmin2, ymax2, xmax2] = b;
        return (xmin1 <= xmax2 && xmax1 >= xmin2 && ymin1 <= ymax2 && ymax1 >= ymin2);
    }
} // namespace ugilib
