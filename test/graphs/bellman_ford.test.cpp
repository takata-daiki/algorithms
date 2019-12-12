#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include "../../graphs/bellman_ford.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    BellmanFord<int> g(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }
    bool neg_cycle;
    auto dist = g.build(r, neg_cycle);
    if (neg_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < v; i++) {
        const int NO_PATH = BellmanFord<int>::INF + BellmanFord<int>::INF;
        if (dist[i] == NO_PATH) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}