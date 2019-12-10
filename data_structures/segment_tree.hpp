#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    int n;
    T init;
    F f;
    vector<T> data;

    SegmentTree() {}
    SegmentTree(
        int n_, F f = [](T a, T b) { return min(a, b); }, T init = INT_MAX,
        vector<T> v = vector<T>())
        : f(f), init(init) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(n * 2 - 1, init);
        if (n_ == v.size()) build(v);
    }
    void build(vector<T> v) {
        for (int i = 0; i < v.size(); ++i) data[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; --i) {
            data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
    void update(int k, T x) {
        k += n - 1;
        data[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = f(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (b <= l || r <= a) return init;
        if (a <= l && r <= b) return data[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
};