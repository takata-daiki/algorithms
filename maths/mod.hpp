#pragma once
#include <bits/stdc++.h>
using namespace std;

struct ModInt {
    using M = ModInt;

    static vector<M> fact, finv;
    static long long MOD;
    long long v;

    // normalize: [-MOD, MOD**2] -> [0, MOD)
    ModInt(const long long _v = 0) : v((_v < 0) ? _v % MOD + MOD : _v % MOD) {}

    M operator+(const M& x) const { return M(v + x.v); }
    M operator-(const M& x) const { return M(v - x.v); }
    M operator*(const M& x) const { return M(v * x.v); }
    M operator/(const M& x) const { return M(v * x.inv().v); }
    M& operator+=(const M& x) { return *this = *this + x; }
    M& operator-=(const M& x) { return *this = *this - x; }
    M& operator*=(const M& x) { return *this = *this * x; }
    M& operator/=(const M& x) { return *this = *this / x; }
    bool operator==(const M& x) const { return v == x.v; }
    bool operator!=(const M& x) const { return v != x.v; }
    friend istream& operator>>(istream& input, M& x) {
        return input >> x.v, x = M(x), input;
    }
    friend ostream& operator<<(ostream& output, const M& x) {
        return output << x.v;
    }
    inline M pow(long long n) const {
        M x(v), res(1);
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    inline M inv() const { return this->pow(MOD - 2); }
    static void build(int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i < n + 1; i++) fact[i] = fact[i - 1] * M(i);
        finv.assign(n + 1, fact[n].inv());
        for (int i = n; i > 0; i--) finv[i - 1] = finv[i] * M(i);
    }
    static M comb(int n, int k) {
        if (n < k || k < 0) return M(0);
        return fact[n] * finv[n - k] * finv[k];
    }
    static M extgcd(int a, int b, int& x, int& y) {
        M d(a);
        if (b) {
            d = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
        } else {
            x = 1;
            y = 0;
        }
        return d;
    }
};
vector<ModInt> ModInt::fact = vector<ModInt>();
vector<ModInt> ModInt::finv = vector<ModInt>();
long long ModInt::MOD = 1e9 + 7;