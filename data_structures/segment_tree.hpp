#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;

    const Monoid monoid;
    int n;
    vector<T> data;

    SegmentTree() {}
    SegmentTree(int _n, const Monoid& _monoid = Monoid()) : monoid(_monoid) {
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

    void update(int k, T x) {
        assert(0 <= k && k < n);
        k += n;
        data[k] = x;
        for (int i = k >> 1; i > 0; i >>= 1) {
            data[i] = monoid.merge(data[i << 1], data[i << 1 | 1]);
        }
    }
    // [a, b)
    T query(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        a += n;
        b += n - 1;
        T vl = monoid.identity(), vr = monoid.identity();
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = monoid.merge(vl, data[l++]);
            if (r & 1) vr = monoid.merge(data[--r], vr);
        }
        return monoid.merge(vl, vr);
    }
};