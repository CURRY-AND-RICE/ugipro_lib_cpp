#pragma once

/**
 * @file hashes.hpp
 * @brief ハッシュ構造体の定義
 * @note pair<T1, T2>, iterable<T>に対するハッシュ関数を定義
*/

#include <utility>
using namespace std;

namespace ugilib {
    /**
     * @brief pair<T1, T2>に対するハッシュ関数
     * @tparam T1 pairの1つ目の要素の型
     * @tparam T2 pairの2つ目の要素の型
    */
    struct pair_hash {
        template <class T1, class T2>
        size_t operator () (const pair<T1, T2> &pair) const {
            auto hash1 = hash<T1>{}(pair.first);
            auto hash2 = hash<T2>{}(pair.second);
            return hash1 ^ (hash2 << 1);
        }
    };

    /**
     * @brief iterable<T>に対するハッシュ関数
     * @tparam T iterableの要素の型
     * @note zobrist hashing + DJB2 hashで実装
     * @note 本来ならばzobrist hashingは乱数を用いるが、ここではstd::hashを用いている
    */
    struct zobrist_hash {
        template <class T>
        size_t operator () (const T &iterable) const {
            size_t hash = 0;
            for (const auto &item : iterable) {
                hash ^= std::hash<typename T::value_type>{}(item) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
} // namespace ugilib
