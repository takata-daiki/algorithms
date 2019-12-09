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


# :heavy_check_mark: test/data_structures/union_find.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/unionfind](https://judge.yosupo.jp/problem/unionfind)


## Dependencies
* :heavy_check_mark: [data_structures/union_find.hpp](../../../library/data_structures/union_find.hpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>

#include "../../data_structures/union_find.hpp"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t) {
            cout << uf.same(u, v) << endl;
        } else {
            uf.unite(u, v);
        }
    }
}
```
{% endraw %}

[Back to top page](../../../index.html)

