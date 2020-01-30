#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"
#include "../../data_structures/segtrees/segment_tree.hpp"
#include "../../data_structures/segtrees/monoids/min.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree<min_monoid<int>> seg(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            cout << seg.query(x, y + 1) << endl;
        } else {
            seg.update(x, y);
        }
    }
}