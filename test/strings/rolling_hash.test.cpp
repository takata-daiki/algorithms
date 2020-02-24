#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"
#include "../../strings/rolling_hash.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, p;
    cin >> t >> p;
    int lt = t.length();
    int lp = p.length();
    RollingHash rh(t + p);
    for (int i = 0; i < lt - lp + 1; i++) {
        if (rh.match(i, i + lp, lt, lt + lp)) cout << i << endl;
    }
}