#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
constexpr function<T(T, T)> ex_assign(T initE) {
    return [&initE](const T& x, const T& y) -> const T {
        return (y == initE) ? x : y;
    };
}
template <typename T>
constexpr function<T(T, int)> ex_multiplies(T initE) {
    return [&initE](const T& x, size_t y) -> const T {
        return (x == initE) ? x : x * y;
    };
}
template <typename T, typename E>
struct LazySegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    using P = function<E(E, int)>;

    int n;
    T initT;
    E initE;
    F f;
    G g;
    H h;
    P p;
    vector<T> data;
    vector<E> lazy;

    LazySegmentTree() {}
    LazySegmentTree(int n_, F f, G g, H h, P p, T initT = INT_MAX,
                    E initE = INT_MAX, vector<T> v = vector<T>())
        : f(f), g(g), h(h), p(p), initT(initT), initE(initE) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(n * 2 - 1, initT);
        lazy.assign(n * 2 - 1, initE);
        if (n_ == v.size()) build(v);
    }
    void build(vector<T> v) {
        for (int i = 0; i < v.size(); ++i) data[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; --i) {
            data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
    inline void eval(int len, int k) {
        if (lazy[k] == initE) return;
        if (k * 2 + 1 < n * 2 - 1) {
            lazy[k * 2 + 1] = h(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = h(lazy[k * 2 + 2], lazy[k]);
        }
        data[k] = g(data[k], p(lazy[k], len));
        lazy[k] = initE;
    }
    T update(int a, int b, E x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(r - l, k);
        if (b <= l || r <= a) return data[k];
        if (a <= l && r <= b) {
            lazy[k] = h(lazy[k], x);
            return g(data[k], p(lazy[k], r - l));
        }
        T vl = update(a, b, x, k * 2 + 1, l, (l + r) / 2);
        T vr = update(a, b, x, k * 2 + 2, (l + r) / 2, r);
        return data[k] = f(vl, vr);
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(r - l, k);
        if (b <= l || r <= a) return initT;
        if (a <= l && r <= b) return data[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
};
//
// e.g.
//      |     f     |   g   |   h   |   p    |  initT  | initE |
// -----+-----------+-------+-------+--------+---------+-------+
//  RMQ | min / max |       |       | (mult) | INF / 0 |       |
//  RSQ | plus      |       |       | (mult) | 0       |       |
//  RUQ |           | (ass) | (ass) | (mult) |         | INF   |
//  RAQ |           | plus  | plus  | (mult) |         | 0     |
//
//  (ass)  := ex_assign;
//  (mult) := ex_multiplies;
//
const int initT = 0;
const int initE = 1e9;
const LazySegmentTree<int, int>::F f = plus<int>();
const LazySegmentTree<int, int>::G g = ex_assign<int>(initE);
const LazySegmentTree<int, int>::H h = ex_assign<int>(initE);
const LazySegmentTree<int, int>::P p = ex_multiplies<int>(initE);