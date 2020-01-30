#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
#include "../../data_structures/binary_indexed_tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    BinaryIndexedTree<long long> bit(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y, x--;
        if (com) {
            cout << bit.sum(y - 1) - bit.sum(x - 1) << endl;
        } else {
            bit.add(x, y);
        }
    }
}