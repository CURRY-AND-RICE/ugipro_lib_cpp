#include <bits/stdc++.h>
using namespace std;

// 和集合
template <typename SetType>
SetType set_union(const SetType& s1, const SetType& s2) {
    SetType result(s1);
    result.insert(s2.begin(), s2.end());
    return result;
}

// 積集合
template <typename SetType>
SetType set_intersection(const SetType& s1, const SetType& s2) {
    SetType intersection;
    for (const auto& e : s1) {
        if (s2.find(e) != s2.end()) {
            intersection.insert(e);
        }
    }
    return intersection;
}

// 差集合
template <typename SetType>
SetType set_difference(const SetType& s1, const SetType& s2) {
    SetType difference;
    for (const auto& e : s1) {
        if (!s2.contains(e)) {
            difference.insert(e);
        }
    }
    return difference;
}
