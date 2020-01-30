---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: geometry/geometry.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed7daeb157cd9b31e53896ad3c771a26">geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometry/geometry.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 01:55:44+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/geometry/geometry.convex_hull.test.cpp.html">test/geometry/geometry.convex_hull.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/geometry.intersection.test.cpp.html">test/geometry/geometry.intersection.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/geometry/geometry.parallel_orthogonal.test.cpp.html">test/geometry/geometry.parallel_orthogonal.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Point {
    using P = Point;

    static double EPS;
    double x;
    double y;
    double z;

    Point(const double _x = 0.0, const double _y = 0.0, const double _z = 0.0)
        : x(_x), y(_y), z(_z) {}

    // NOTICE: if you use 3d vector, change THIS!!
    friend istream& operator>>(istream& input, P& p) {
        return input >> p.x >> p.y, p.z = 0, input;
    }
    friend ostream& operator<<(ostream& output, const P& p) {
        return output << '(' << p.x << ", " << p.y << ')';
    }
    P operator+(const P& p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y, z - p.z); }
    P operator*(const double k) const { return P(x * k, y * k, z * k); }
    P operator/(const double k) const { return P(x / k, y / k, z / k); }
    P& operator+=(const P& p) { return *this = *this + p; }
    P& operator-=(const P& p) { return *this = *this - p; }
    P& operator*=(const double k) { return *this = *this * k; }
    P& operator/=(const double k) { return *this = *this / k; }
    bool operator<(const P& p) const { return lt(z, p.z); }
    bool operator==(const P& p) const {
        return eq(x, p.x) && eq(y, p.y) && eq(z, p.z);
    }
    bool operator>(const P& p) const { return !(*this < p || *this == p); }
    inline double abs() const { return sqrt(norm()); }
    inline double norm() const { return x * x + y * y + z * z; };
    inline double dot(const P& p) const { return x * p.x + y * p.y + z * p.z; }
    inline P cross(const P& p) const {
        double a = y * p.z - z * p.y;
        double b = z * p.x - x * p.z;
        double c = x * p.y - y * p.x;
        return P(a, b, c);
    }
    inline bool is_orthogonal(const P& p) const { return eq(dot(p), 0.0); }
    inline bool is_parallel(const P& p) const {
        return cross(p) == P(0.0, 0.0, 0.0);
    }
    static bool eq(const double a, const double b) {
        return std::abs(a - b) < EPS;
    }
    static bool lt(const double a, const double b) {
        return a - b < -EPS;
    }
    static bool le(const double a, const double b) {
        return a - b < EPS;
    }
    static int ccw(P a, P b, P c) {
        b -= a;
        c -= a;
        if (b.cross(c) > P(0.0, 0.0, 0.0)) return +1;  // counter clockwise
        if (b.cross(c) < P(0.0, 0.0, 0.0)) return -1;  // clockwise
        if (lt(b.dot(c), 0.0)) return +2;              // on line back
        if (lt(b.norm(), c.norm())) return -2;         // on line front
        return 0;                                      // on segment
    }
    static bool intersect(const P& a1, const P& a2, const P& b1, const P& b2) {
        return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
               ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
    }
    static vector<P> convex_hull(vector<P> ps) {
        int n = ps.size(), k = 0;
        sort(begin(ps), end(ps), [](const P& a, const P& b) {
            return (!eq(a.y, b.y)) ? lt(a.y, b.y) : lt(a.x, b.x);
        });
        vector<P> ch(n * 2);
        for (int i = 0; i < n; ch[k++] = ps[i++]) {
            while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) == -1) k--;
        }
        for (int i = n - 2, t = k; i >= 0; ch[k++] = ps[i--]) {
            while (k >= t + 1 && ccw(ch[k - 2], ch[k - 1], ps[i]) == -1) k--;
        }
        ch.resize(k - 1);
        return ch;
    }
};
double Point::EPS = 1e-10;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "geometry/geometry.hpp"
#include <bits/stdc++.h>
using namespace std;

struct Point {
    using P = Point;

    static double EPS;
    double x;
    double y;
    double z;

    Point(const double _x = 0.0, const double _y = 0.0, const double _z = 0.0)
        : x(_x), y(_y), z(_z) {}

    // NOTICE: if you use 3d vector, change THIS!!
    friend istream& operator>>(istream& input, P& p) {
        return input >> p.x >> p.y, p.z = 0, input;
    }
    friend ostream& operator<<(ostream& output, const P& p) {
        return output << '(' << p.x << ", " << p.y << ')';
    }
    P operator+(const P& p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y, z - p.z); }
    P operator*(const double k) const { return P(x * k, y * k, z * k); }
    P operator/(const double k) const { return P(x / k, y / k, z / k); }
    P& operator+=(const P& p) { return *this = *this + p; }
    P& operator-=(const P& p) { return *this = *this - p; }
    P& operator*=(const double k) { return *this = *this * k; }
    P& operator/=(const double k) { return *this = *this / k; }
    bool operator<(const P& p) const { return lt(z, p.z); }
    bool operator==(const P& p) const {
        return eq(x, p.x) && eq(y, p.y) && eq(z, p.z);
    }
    bool operator>(const P& p) const { return !(*this < p || *this == p); }
    inline double abs() const { return sqrt(norm()); }
    inline double norm() const { return x * x + y * y + z * z; };
    inline double dot(const P& p) const { return x * p.x + y * p.y + z * p.z; }
    inline P cross(const P& p) const {
        double a = y * p.z - z * p.y;
        double b = z * p.x - x * p.z;
        double c = x * p.y - y * p.x;
        return P(a, b, c);
    }
    inline bool is_orthogonal(const P& p) const { return eq(dot(p), 0.0); }
    inline bool is_parallel(const P& p) const {
        return cross(p) == P(0.0, 0.0, 0.0);
    }
    static bool eq(const double a, const double b) {
        return std::abs(a - b) < EPS;
    }
    static bool lt(const double a, const double b) {
        return a - b < -EPS;
    }
    static bool le(const double a, const double b) {
        return a - b < EPS;
    }
    static int ccw(P a, P b, P c) {
        b -= a;
        c -= a;
        if (b.cross(c) > P(0.0, 0.0, 0.0)) return +1;  // counter clockwise
        if (b.cross(c) < P(0.0, 0.0, 0.0)) return -1;  // clockwise
        if (lt(b.dot(c), 0.0)) return +2;              // on line back
        if (lt(b.norm(), c.norm())) return -2;         // on line front
        return 0;                                      // on segment
    }
    static bool intersect(const P& a1, const P& a2, const P& b1, const P& b2) {
        return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
               ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
    }
    static vector<P> convex_hull(vector<P> ps) {
        int n = ps.size(), k = 0;
        sort(begin(ps), end(ps), [](const P& a, const P& b) {
            return (!eq(a.y, b.y)) ? lt(a.y, b.y) : lt(a.x, b.x);
        });
        vector<P> ch(n * 2);
        for (int i = 0; i < n; ch[k++] = ps[i++]) {
            while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) == -1) k--;
        }
        for (int i = n - 2, t = k; i >= 0; ch[k++] = ps[i--]) {
            while (k >= t + 1 && ccw(ch[k - 2], ch[k - 1], ps[i]) == -1) k--;
        }
        ch.resize(k - 1);
        return ch;
    }
};
double Point::EPS = 1e-10;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

