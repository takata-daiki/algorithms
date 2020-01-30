#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Monoid>
struct SegmentTree {
    using T = typename Monoid::T;

    const Monoid monoid;
    int n;
    vector<T> data;

    SegmentTree() {}
    SegmentTree(const int _n, const Monoid& _monoid = Monoid())
        : monoid(_monoid) {
        n = 1;
        while (n < _n) n <<= 1;
        data.assign(n << 1, monoid.identity());
    }
    // with initialization of given data
    template <class InputIterator>
    SegmentTree(InputIterator first, InputIterator last,
                const Monoid& _monoid = Monoid())
        : monoid(_monoid) {
        int size = distance(first, last);
        n = 1;
        while (n < size) n <<= 1;
        data.assign(n << 1, monoid.identity());
        copy(first, last, begin(data) + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }

    void update(const int k, const T x) {
        assert(0 <= k && k < n);
        data[k + n] = x;
        for (int i = (k + n) >> 1; i > 0; i >>= 1) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }
    // [a, b)
    T query(const int a, const int b) {
        assert(0 <= a && a <= b && b <= n);
        T vl = monoid.identity(), vr = monoid.identity();
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid.merge(vl, data[l++]);
            if (r & 1) vr = monoid.merge(data[--r], vr);
        }
        return monoid.merge(vl, vr);
    }
};