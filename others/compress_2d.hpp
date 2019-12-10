#pragma once
#include <bits/stdc++.h>
using namespace std;

int compress2D(int n, vector<int>& vs, vector<int>& vt) {
    vector<int> v;
    v.push_back(-1);
    REP(i, n) REP(d, 2) {
        v.push_back(vs[i] + d);
        v.push_back(vt[i] + d);
    }
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    REP(i, n) {
        vs[i] = lower_bound(begin(v), end(v), vs[i]) - begin(v);
        vt[i] = lower_bound(begin(v), end(v), vt[i]) - begin(v);
    }
    return v.size();
}