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


# :warning: others/compress_2d.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/compress_2d.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:56:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

int compress2D(int n, vector<int>& vs, vector<int>& vt) {
    vector<int> v;
    v.push_back(-1);
    REP(i, n) REP(d, 2) {
        v.push_back(vs[i] + d);
        v.push_back(vt[i] + d);
    }
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    REP(i, n) {
        vs[i] = lower_bound(begin(v), end(v), vs[i]) - begin(v);
        vt[i] = lower_bound(begin(v), end(v), vt[i]) - begin(v);
    }
    return v.size();
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "others/compress_2d.hpp"
#include <bits/stdc++.h>
using namespace std;

int compress2D(int n, vector<int>& vs, vector<int>& vt) {
    vector<int> v;
    v.push_back(-1);
    REP(i, n) REP(d, 2) {
        v.push_back(vs[i] + d);
        v.push_back(vt[i] + d);
    }
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    REP(i, n) {
        vs[i] = lower_bound(begin(v), end(v), vs[i]) - begin(v);
        vt[i] = lower_bound(begin(v), end(v), vt[i]) - begin(v);
    }
    return v.size();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

