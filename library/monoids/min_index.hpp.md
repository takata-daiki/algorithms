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


# :heavy_check_mark: monoids/min_index.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/min_index.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 22:28:03+09:00




## Required by

* :heavy_check_mark: <a href="../graphs/lowest_common_ancestor.hpp.html">graphs/lowest_common_ancestor.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/graphs/lowest_common_ancestor.test.cpp.html">test/graphs/lowest_common_ancestor.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_index_monoid {
    using P = pair<T, int>;
    using value_type = P;
    P identity() { return make_pair(numeric_limits<T>::max(), INT_MAX); }
    P merge(P a, P b) { return min(a, b); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/min_index.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_index_monoid {
    using P = pair<T, int>;
    using value_type = P;
    P identity() { return make_pair(numeric_limits<T>::max(), INT_MAX); }
    P merge(P a, P b) { return min(a, b); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

