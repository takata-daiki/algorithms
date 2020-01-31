#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"
#include "../../data_structures/segtrees/lazy_segment_tree.hpp"
#include "../../data_structures/segtrees/monoids/sum.hpp"
#include "../../data_structures/segtrees/monoids/affine.hpp"
#include "../../data_structures/segtrees/monoids/sum_affine_action.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

int main() {
    int n, q;
    cin >> n >> q;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = P(0, 1);
    }
    
    LazySegmentTree<sum_monoid<ll>, affine_monoid<ll>, sum_affine_action<ll>> seg(begin(a), end(a));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, s--;
        if (com) {
            cout << seg.query(s, t).first << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, P(1, x));
        }
    }
}