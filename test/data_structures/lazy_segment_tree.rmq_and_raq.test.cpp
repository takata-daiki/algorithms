#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"
#include "../../data_structures/segtrees/lazy_segment_tree.hpp"
#include "../../data_structures/segtrees/monoids/plus.hpp"
#include "../../data_structures/segtrees/monoids/min.hpp"
#include "../../data_structures/segtrees/monoids/plus_min_action.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> tmp(n, 0);
    LazySegmentTree<min_monoid<int>, plus_monoid<int>, plus_min_action<int>> seg(begin(tmp), end(tmp));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t;
        t++;
        if (com) {
            cout << seg.query(s, t) << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, x);
        }
    }
}