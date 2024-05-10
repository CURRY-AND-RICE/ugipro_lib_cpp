#pragma once

/**
 * @file hashes.hpp
 * @brief ハッシュ構造体の定義
 * @note pair<T1, T2>, iterable<T>に対するハッシュ関数を定義
*/

#include <utility>
#include <type_traits>
using namespace std;

namespace ugilib {
    /**
     * @brief pair<T1, T2>に対するハッシュ関数
     * @tparam T1 pairの1つ目の要素の型
     * @tparam T2 pairの2つ目の要素の型
    */
    struct pair_hash {
        template <class T1, class T2>
        size_t operator() (const pair<T1, T2> &pair) const {
            auto hash1 = hash<T1>{}(pair.first);
            auto hash2 = hash<T2>{}(pair.second);
            return hash1 ^ (hash2 << 1);
        }
    };

    /**
     * @brief Iterableに対するハッシュ関数
     * @tparam Iterable イテラブルなコンテナ
    */
    struct array_hash {
        /**
         * @brief イテラブル型のハッシュ計算
         * @tparam T イテラブルの要素の型
         * @param value イテラブルの要素
         * @return size_t ハッシュ値
         * @note 再帰的呼び出しで算術型に辿り着いた場合のハッシュ
        */
        template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
        size_t operator() (const T& value) const {
            size_t hash = 0;
            hash ^= std::hash<T>{}(value) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            return hash;
        }

        /**
         * @brief イテレータ特性を持たないarray<T, N>に対する特殊化
         * @tparam T arrayの要素の型
         * @tparam N arrayの要素数
         * @param array array
         * @return size_t ハッシュ値
        */
        template <typename T, size_t N>
        size_t operator() (const array<T, N> &array) const {
            size_t hash = 0;
            for (const auto& item : array) {
                hash ^= (*this)(item) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }

        /**
         * @brief イテラブル型のハッシュ計算
         * @tparam Iterable イテラブルなコンテナ
         * @param iterable イテラブル
         * @return size_t ハッシュ値
         * @note 再帰的呼び出しを行い、多次元コンテナに対してもハッシュ可能
        */
        template <typename Iterable, std::enable_if_t<!std::is_arithmetic_v<Iterable> &&
                                                    std::is_same_v<typename std::iterator_traits<typename Iterable::iterator>::iterator_category, std::input_iterator_tag>, int> = 0>
        size_t operator() (const Iterable &iterable) const {
            size_t hash = 0;
            for (const auto &item : iterable) {
                hash ^= (*this)(item) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
} // namespace ugilib
