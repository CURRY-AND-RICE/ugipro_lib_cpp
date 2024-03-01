#pragma once
#include <utility>
using namespace std;

namespace ugilib {
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2> &pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ (hash2 << 1);
    }
};
} // namespace ugilib
