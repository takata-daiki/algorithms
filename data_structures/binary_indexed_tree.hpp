#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
    vector<T> data;
    BinaryIndexedTree(int n) : data(n + 1, 0) {}
    inline T sum(int k) {
        T s = 0;
        for (int i = k + 1; i > 0; i -= i & -i) s += data[i];
        return s;
    }
    inline void add(int k, T x) {
        for (int i = k + 1; i < (int)data.size(); i += i & -i) data[i] += x;
    }
};