#pragma once
#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <typename T>
struct BinaryIndexedTree {
    int n;
    vector<T> data;

    BinaryIndexedTree(int _n) : n(_n) { data.assign(n + 1, 0); }

    inline void add(int k, T x) {
        assert(0 <= k && k < n);
        for (int i = k + 1; i <= n; i += i & -i) data[i] += x;
    }
    // [0, k)
    inline T sum(int k) {
        assert(0 <= k && k <= n);
        T s = 0;
        for (int i = k; i > 0; i -= i & -i) s += data[i];
        return s;
    }
};