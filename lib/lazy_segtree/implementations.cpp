#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/lazysegtree>

using namespace std;
using namespace atcoder;

using ll = long long;
const ll INF = 1LL << 60;

namespace segtree_min {
    using S = ll;
    S op(S a, S b) { return min(a, b); }
    S e() { return INF;}

    vector<S> initializer{1, 2, 3, 4, 5};
    segtree<S, segtree_sum::op, segtree_sum::e> seg(initializer);
};

namespace segtree_sum {
    using S = ll;
    S op(S a, S b) { return a + b; }
    S e() { return 0;}

    vector<S> initializer{1, 2, 3, 4, 5};
    segtree<S, segtree_sum::op, segtree_sum::e> seg(initializer);
};

namespace lazy_segtree_range_update {
    using S = ll;
    using F = ll;
    const F ID = INF;

    S op(S a, S b) { return 0; }  // no prod query
    S e() { return (1LL<<31) - 1; }  // intial value
    S mapping(F f, S s) { return (f != ID) ? f : s; }
    F composition(F f, F lazy) { return (f != ID) ? f : lazy; }
    F id() { return ID; }

    int n = 5;
    lazy_segtree<S, op, e, F, mapping, composition, id> lst(n);
};

namespace lazy_segtree_range_add {
    using S = ll;
    using F = ll;

    S op(S a, S b) { return 0; }  // no prod query
    S e() { return 0; }  // intial value
    S mapping(F f, S x) { return f + x; }
    F composition(F f, F g) { return f + g; }
    F id() { return 0; }

    int n = 5;
    lazy_segtree<S, op, e, F, mapping, composition, id> lst(n);
};

// range minimum query and range update query
namespace lazy_segtree_rmq_ruq {
    using S = ll;
    using F = ll;
    const F ID = INF;

    S op(S a, S b) { return (a < b) ? a : b; }  // min query
    S e() { return (1LL<<31) - 1; }  // initial value
    S mapping(F f, S x) { return (f == ID) ? x : f; }
    F composition(F f, F g) { return (f == ID) ? g : f; }
    F id() { return ID; }

    int  n = 5;
    lazy_segtree<S, op, e, F, mapping, composition, id> lst(n);
}

// range sum query and range add query
namespace lazy_segtree_rsq_raq {
    struct S {
        ll value;
        ll size;
    };
    using F = ll;
    S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }  // sum query
    S e() { return {0, 0}; }  // initial value
    S mapping(F f, S x) {  // lazy add
        x.value += f * x.size;
        return x;
    }
    F composition(F f, F g) { return f + g;}
    F id() { return 0; }

    vector<S> initializer{{0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}};
    lazy_segtree<S, op, e, F, mapping, composition, id> lst(initializer);
}

// range minimum query and range add query
namespace lazy_segtree_rmq_raq {
    using S = ll;
    using F = ll;
    S op(S a, S b) { return (a < b) ? a : b; }  // min query
    S e() { return INF; }  // initial value
    S mapping(F f, S x) { return f + x; }  // add to minimum
    F composition(F f, F g) { return f + g; }
    F id() { return 0; }

    vector<S> initializer{0, 0, 0, 0, 0};
    lazy_segtree<S, op, e, F, mapping, composition, id> lst(initializer);
}

// range sum query and range update query
namespace lazy_segtree_rsq_ruq {
    struct S {
        ll value;
        ll size;
    };
    using F = ll;
    const F ID = INF;
    S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
    S e() { return {0, 0}; }
    S mapping(F f, S x) {
        if (f != ID) x.value = f * x.size;
        return x;
    }
    F composition(F f, F g) { return (f == ID) ? g : f; }
    F id() { return ID; }

    vector<S> initializer{{0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}};
    lazy_segtree<S, op, e, F, mapping, composition, id> lst(ini);
}
