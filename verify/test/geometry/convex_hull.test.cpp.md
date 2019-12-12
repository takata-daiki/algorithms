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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/geometry/convex_hull.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/geometry/convex_hull.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 01:55:44 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A</a>


## Depends On
* :heavy_check_mark: <a href="../../../library/geometry/geometry.hpp.html">geometry/geometry.hpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include "../../geometry/geometry.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    auto ch = Point::convex_hull(p);
    cout << ch.size() << endl;
    for (auto q : ch) {
        cout << q.x << ' ' << q.y << endl;
    }
}
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

