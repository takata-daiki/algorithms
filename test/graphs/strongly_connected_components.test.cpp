#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C"
#include "../../graphs/strongly_connected_components.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    StronglyConnectedComponents g(n);
    while (m--) {
        int s, t;
        cin >> s >> t;
        g.add_edge(s, t);
    }
    g.build();

    vector<int> idx(n);
    for (int i = 0; i < (int)g.scc.size(); i++) {
        for (auto&& x : g.scc[i]) idx[x] = i;
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (idx[u] == idx[v]) << endl;
    }
}