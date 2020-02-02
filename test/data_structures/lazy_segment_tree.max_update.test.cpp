#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F"
#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../monoids/max.hpp"
#include "../../monoids/change.hpp"
#include "../../monoids/max_change_action.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 1 << 31 | 1);
    LazySegmentTree<max_monoid<int>, change_monoid<int>, max_change_action<int>> seg(begin(a), end(a));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, t++;
        if (com) {
            cout << -seg.query(s, t) << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, -x);
        }
    }
}