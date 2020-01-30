#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename MonoidT, typename MonoidE, typename Action>
struct LazySegmentTree {
    using T = typename MonoidT::T;
    using E = typename MonoidE::T;

    const MonoidT mt;
    const MonoidE me;
    const Action act;
    int n, height;
    vector<T> data;
    vector<E> lazy;

    LazySegmentTree() {}
    LazySegmentTree(const int _n, const MonoidT& _mt = MonoidT(),
                    const MonoidE& _me = MonoidE(),
                    const Action& _act = Action())
        : mt(_mt), me(_me), act(_act) {
        n = 1, height = 0;
        while (n < _n) n <<= 1, height++;
        data.assign(n << 1, mt.identity());
        lazy.assign(n << 1, me.identity());
    }
    // with initialization of given data
    template <class InputIterator>
    LazySegmentTree(InputIterator first, InputIterator last,
                    const MonoidT& _mt = MonoidT(),
                    const MonoidE& _me = MonoidE(),
                    const Action& _act = Action())
        : mt(_mt), me(_me), act(_act) {
        int size = distance(first, last);
        n = 1, height = 0;
        while (n < size) n <<= 1, height++;
        data.resize(n << 1, mt.identity());
        lazy.resize(n << 1, me.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = mt.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    inline T action(int k) { return act(lazy[k], data[k]); }
    inline void eval(const int k) {
        if (lazy[k] == me.identity()) return;
        lazy[k << 1] = me.merge(lazy[k << 1], lazy[k]);
        lazy[k << 1 | 1] = me.merge(lazy[k << 1 | 1], lazy[k]);
        data[k] = action(k);
        lazy[k] = me.identity();
    }
    // [a, b)
    void update(const int a, const int b, const E x) {
        assert(0 <= a && a <= b && b <= n);
        for (int i = height; i > 0; i--) {
            eval((a + n) >> i);
            eval((b + n - 1) >> i);
        }
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = me.merge(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = me.merge(lazy[r], x);
        }
        for (int l = (a + n) >> 1; l > 0; l >>= 1) {
            data[l] = mt.merge(action(l << 1), action(l << 1 | 1));
        }
        for (int r = (b + n - 1) >> 1; r > 0; r >>= 1) {
            data[r] = mt.merge(action(r << 1), action(r << 1 | 1));
        }
    }
    // [a, b)
    T query(const int a, const int b) {
        assert(0 <= a && a <= b && b <= n);
        for (int i = height; i > 0; i--) {
            eval((a + n) >> i);
            eval((b + n - 1) >> i);
        }
        T vl = mt.identity(), vr = mt.identity();
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = mt.merge(vl, action(l++));
            if (r & 1) vr = mt.merge(action(--r), vr);
        }
        return mt.merge(vl, vr);
    }
};