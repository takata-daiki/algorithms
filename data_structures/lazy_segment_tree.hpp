#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename MonoidT, typename MonoidU, typename Action>
struct LazySegmentTree {
    using T = typename MonoidT::value_type;
    using U = typename MonoidU::value_type;

    const MonoidT monoid_t;
    const MonoidU monoid_u;
    const Action act;
    int n, height;
    vector<T> data;
    vector<U> lazy;

    LazySegmentTree() {}
    LazySegmentTree(const int _n, const MonoidT& _monoid_t = MonoidT(),
                    const MonoidU& _monoid_u = MonoidU(),
                    const Action& _act = Action())
        : monoid_t(_monoid_t), monoid_u(_monoid_u), act(_act) {
        n = 1, height = 0;
        while (n < _n) n <<= 1, height++;
        data.assign(n << 1, monoid_t.identity());
        lazy.assign(n << 1, monoid_u.identity());
    }
    // with initialization of given data
    template <class InputIterator>
    LazySegmentTree(InputIterator first, InputIterator last,
                    const MonoidT& _monoid_t = MonoidT(),
                    const MonoidU& _monoid_u = MonoidU(),
                    const Action& _act = Action())
        : monoid_t(_monoid_t), monoid_u(_monoid_u), act(_act) {
        int size = distance(first, last);
        n = 1, height = 0;
        while (n < size) n <<= 1, height++;
        data.resize(n << 1, monoid_t.identity());
        lazy.resize(n << 1, monoid_u.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid_t.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    inline T action(int k) { return act(data[k], lazy[k]); }
    inline void eval(const int k) {
        if (lazy[k] == monoid_u.identity()) return;
        lazy[k << 1] = monoid_u.merge(lazy[k << 1], lazy[k]);
        lazy[k << 1 | 1] = monoid_u.merge(lazy[k << 1 | 1], lazy[k]);
        data[k] = action(k);
        lazy[k] = monoid_u.identity();
    }
    // [a, b)
    void update(const int a, const int b, const U x) {
        assert(0 <= a && a <= b && b <= n);
        for (int i = height; i > 0; i--) {
            eval((a + n) >> i);
            eval((b + n - 1) >> i);
        }
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = monoid_u.merge(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = monoid_u.merge(lazy[r], x);
        }
        for (int l = (a + n) >> 1; l > 0; l >>= 1) {
            data[l] = monoid_t.merge(action(l << 1), action(l << 1 | 1));
        }
        for (int r = (b + n - 1) >> 1; r > 0; r >>= 1) {
            data[r] = monoid_t.merge(action(r << 1), action(r << 1 | 1));
        }
    }
    // [a, b)
    T query(const int a, const int b) {
        assert(0 <= a && a <= b && b <= n);
        for (int i = height; i > 0; i--) {
            eval((a + n) >> i);
            eval((b + n - 1) >> i);
        }
        T vl = monoid_t.identity(), vr = monoid_t.identity();
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid_t.merge(vl, action(l++));
            if (r & 1) vr = monoid_t.merge(action(--r), vr);
        }
        return monoid_t.merge(vl, vr);
    }
};