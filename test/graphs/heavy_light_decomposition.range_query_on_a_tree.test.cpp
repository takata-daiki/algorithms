#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E"
#include <bits/stdc++.h>

#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../graphs/heavy_light_decomposition.hpp"
#include "../../monoids/affine.hpp"
#include "../../monoids/sum.hpp"
#include "../../monoids/sum_affine_action.hpp"
using namespace std;
using ll = long long;
using P = pair<ll, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    HeavyLightDecomposition hld(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int c;
            cin >> c;
            hld.add_edge(i, c);
        }
    }
    hld.build();

    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = P(0, 1);
    }
    LazySegmentTree<sum_monoid<ll>, affine_monoid<ll>, sum_affine_action<ll>> seg(begin(a), end(a));
    auto add = [&](int v, int w) {
        hld.for_each_edge(0, v, [&](int l, int r) {
            seg.update(l, r + 1, P(1, w));
            });
    };
    auto get_sum = [&](int u) {
        ll res = 0;
        hld.for_each_edge(0, u, [&](int l, int r) {
            res += seg.query(l, r + 1).first;
            });
        return res;
    };

    int q;
    cin >> q;
    while (q--) {
        int com;
        cin >> com;
        if (com) {
            int u;
            cin >> u;
            cout << get_sum(u) << endl;
        } else {
            int v, w;
            cin >> v >> w;
            add(v, w);
        }
    }
}