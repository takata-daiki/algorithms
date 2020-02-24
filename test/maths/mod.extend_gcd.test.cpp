#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"
#include "../../maths/mod.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int x, y;
    ModInt::extgcd(a, b, x, y);
    cout << x << ' ' << y << endl;
}