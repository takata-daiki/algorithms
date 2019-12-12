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


# :heavy_check_mark: test/graphs/bellman_ford.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graphs/bellman_ford.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-13 03:00:25 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B</a>


## Depends On
* :heavy_check_mark: <a href="../../../library/graphs/bellman_ford.hpp.html">graphs/bellman_ford.hpp</a>


## Code
{% raw %}
```cpp
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
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

