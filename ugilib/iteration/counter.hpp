#pragma once
#include <bits/stdc++.h>
#include "ugilib/base/definitions.hpp"

using namespace std;

namespace ugilib {
    /**
     * @brief イテレータの範囲に含まれる要素の出現回数をカウントする
     * @tparam Iterator イテレータの型
     * @param first イテレータの先頭
     * @param last イテレータの終端
     * @return unordered_map<要素の型, 出現回数> の形式で出現回数を返す
    */
    template <typename Iterator, typename _Hash = std::hash<typename std::iterator_traits<Iterator>::value_type>>
    unordered_map<typename std::iterator_traits<Iterator>::value_type, ll, _Hash> count_elements_as_unordered(Iterator first, Iterator last) {
        unordered_map<typename std::iterator_traits<Iterator>::value_type, ll, _Hash> counter;
        for (auto it = first; it != last; ++it) {
            counter[*it]++;
        }
        return counter;
    }

    /**
     * @brief イテレータの範囲に含まれる要素の出現回数をカウントする
     * @tparam Iterator イテレータの型
     * @param first イテレータの先頭
     * @param last イテレータの終端
     * @return map<要素の型, 出現回数> の形式で出現回数を返す
    */
    template <typename Iterator, typename _Compare = less<typename std::iterator_traits<Iterator>::value_type>>
    map<typename std::iterator_traits<Iterator>::value_type, ll, _Compare> count_elements_as_ordered(Iterator first, Iterator last) {
        map<typename std::iterator_traits<Iterator>::value_type, ll, _Compare> counter;
        for (auto it = first; it != last; ++it) {
            counter[*it]++;
        }
        return counter;
    }
} // namespace ugilib
