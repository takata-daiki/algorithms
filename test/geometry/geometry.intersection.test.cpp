#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B"
#include "../../geometry/geometry.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        vector<Point> p(4);
        for (int i = 0; i < 4; i++) cin >> p[i];
        cout << Point::intersect(p[0], p[1], p[2], p[3]) << endl;
    }
}