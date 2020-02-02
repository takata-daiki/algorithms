#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F"
#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../monoids/min.hpp"
#include "../../monoids/change.hpp"
#include "../../monoids/min_change_action.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    LazySegmentTree<min_monoid<int>, change_monoid<int>, min_change_action<int>> seg(n);
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, t++;
        if (com) {
            cout << seg.query(s, t) << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, x);
        }
    }
}