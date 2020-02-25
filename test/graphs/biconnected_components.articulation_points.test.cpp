#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A"
#include "../../graphs/biconnected_components.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    BiconnectedComponents g(n);
    while (m--) {
        int s, t;
        cin >> s >> t;
        g.add_edge(s, t);
    }
    g.build();

    for (int i = 0; i < n; i++) {
        if (g.is_art_point[i]) cout << i << endl;
    }
}