#pragma once
#include <bits/stdc++.h>
using namespace std;

struct RollingHash {
    static int SIZE;
    static vector<uint64_t> mod;
    static vector<uint64_t> base;
    int n;
    vector<vector<unsigned>> h, pw;

    RollingHash(const string& s) : n(s.length()) {
        h.assign(SIZE, vector<unsigned>(n + 1, 0));
        pw.assign(SIZE, vector<unsigned>(n + 1, 1));
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < n; j++) {
                h[i][j + 1] = (h[i][j] * base[i] + s[j]) % mod[i];
                pw[i][j + 1] = pw[i][j] * base[i] % mod[i];
            }
        }
    }

    inline unsigned get(int l, int r, int k) const {
        return (h[k][r] + (mod[k] - h[k][l]) * pw[k][r - l]) % mod[k];
    }

    bool match(int l1, int r1, int l2, int r2) const {
        for (int i = 0; i < SIZE; i++) {
            if (get(l1, r1, i) != get(l2, r2, i)) return false;
        }
        return true;
    }

    int lcp(int i, int j) {
        int ok = 0;
        int ng = min(n - i, n - j) + 1;
        while (ng - ok > 1) {
            int m = (ok + ng) / 2;
            (match(i, i + m, j, j + m) ? ok : ng) = m;
        }
        return ok;
    }
};
int RollingHash::SIZE = 2;
vector<uint64_t> RollingHash::mod = {1000000007, 1000000009};
vector<uint64_t> RollingHash::base = {1009, 1007};