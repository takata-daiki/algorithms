#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct KdSegmentTree {
    using P = pair<int, int>;

    int n;
    vector<vector<T>> data;

    KdSegmentTree() {}
    KdSegmentTree(int n_, vector<T> v) {
        n = 1;
        while (n < n_) n *= 2;
        data.resize(2 * n - 1);
        build(v);
    }
    void build(vector<T> v) {
        for (int i = 0; i < v.size(); ++i) data[i + n - 1].push_back(v[i]);
        for (int i = n - 2; i >= 0; --i) {
            int lch = i * 2 + 1;
            int rch = i * 2 + 2;
            data[i].resize(data[lch].size() + data[rch].size());
            merge(begin(data[lch]), end(data[lch]), begin(data[rch]),
                  end(data[rch]), begin(data[i]));
        }
    }
    void query(int a, int b, int y0, int y1, vector<int>& res, int k = 0,
               int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            auto lb = lower_bound(begin(data[k]), end(data[k]), P{y0, -1});
            auto ub = upper_bound(begin(data[k]), end(data[k]), P{y1, n});
            for (auto itr = lb; itr != ub; ++itr) {
                res.push_back(itr->second);
            }
            return;
        }
        query(a, b, y0, y1, res, k * 2 + 1, l, (l + r) / 2);
        query(a, b, y0, y1, res, k * 2 + 2, (l + r) / 2, r);
    }
};

struct KdTree {
    using P = pair<int, int>;

    int n;
    vector<int> xs;
    vector<P> ys;
    vector<pair<int, P>> ps;
    KdSegmentTree<P> seg;

    KdTree(int n) : n(n), xs(n), ys(n), ps(n) {}

    void build() {
        sort(begin(ps), end(ps));
        for (int i = 0; i < n; ++i) tie(xs[i], ys[i]) = ps[i];
        seg = KdSegmentTree<P>(n, ys);
    }
    void add_point(int x, int y, int i) { ps[i] = {x, {y, i}}; }
    vector<int> query(int sx, int tx, int sy, int ty) {
        vector<int> res;
        int l = distance(begin(xs), lower_bound(begin(xs), end(xs), sx));
        int r = distance(begin(xs), upper_bound(begin(xs), end(xs), tx));
        seg.query(l, r, sy, ty, res);
        sort(begin(res), end(res));
        return res;
    }
};