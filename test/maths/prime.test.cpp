#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009"
#include <bits/stdc++.h>

#include "../../maths/prime.hpp"
using namespace std;

int main() {
    auto prime = sieve_of_eratosthenes(1e6);
    for (int n; cin >> n;) {
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (prime[i]) ans++;
        }
        cout << ans << endl;
    }
}