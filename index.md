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
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# C++ Competitive Programming Library

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions) <a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

## Library Files
### data_structures
* :warning: <a href="library/data_structures/binary_indexed_tree.hpp.html">data_structures/binary_indexed_tree.hpp</a>
* :warning: <a href="library/data_structures/kd_tree.hpp.html">data_structures/kd_tree.hpp</a>
* :warning: <a href="library/data_structures/lazy_segment_tree.hpp.html">data_structures/lazy_segment_tree.hpp</a>
* :warning: <a href="library/data_structures/segment_tree.hpp.html">data_structures/segment_tree.hpp</a>
* :warning: <a href="library/data_structures/union_find.hpp.html">data_structures/union_find.hpp</a>


### geometry
* :warning: <a href="library/geometry/geometry.hpp.html">geometry/geometry.hpp</a>


### graphs
* :warning: <a href="library/graphs/bellman_ford.hpp.html">graphs/bellman_ford.hpp</a>
* :warning: <a href="library/graphs/biconnected_components.hpp.html">graphs/biconnected_components.hpp</a>
* :warning: <a href="library/graphs/dijkstra.hpp.html">graphs/dijkstra.hpp</a>
* :warning: <a href="library/graphs/dinic.hpp.html">graphs/dinic.hpp</a>
* :warning: <a href="library/graphs/ford_fulkerson.hpp.html">graphs/ford_fulkerson.hpp</a>
* :warning: <a href="library/graphs/heavy_light_decomposition.hpp.html">graphs/heavy_light_decomposition.hpp</a>
* :warning: <a href="library/graphs/kruskal.hpp.html">graphs/kruskal.hpp</a>
* :warning: <a href="library/graphs/lowest_common_ancestor.hpp.html">graphs/lowest_common_ancestor.hpp</a>
* :warning: <a href="library/graphs/primal_dual.hpp.html">graphs/primal_dual.hpp</a>
* :warning: <a href="library/graphs/strongly_connected_components.hpp.html">graphs/strongly_connected_components.hpp</a>


### maths
* :warning: <a href="library/maths/mod.hpp.html">maths/mod.hpp</a>
* :warning: <a href="library/maths/prime.hpp.html">maths/prime.hpp</a>


### others
* :warning: <a href="library/others/compress.hpp.html">others/compress.hpp</a>
* :warning: <a href="library/others/compress_2d.hpp.html">others/compress_2d.hpp</a>
* :warning: <a href="library/others/debug.hpp.html">others/debug.hpp</a>
* :warning: <a href="library/others/split.hpp.html">others/split.hpp</a>


### strings
* :warning: <a href="library/strings/rolling_hash.hpp.html">strings/rolling_hash.hpp</a>


## Verify Files
* :warning: <a href="verify/test/data_structures/binary_indexed_tree.test.cpp.html">test/data_structures/binary_indexed_tree.test.cpp</a>
* :warning: <a href="verify/test/data_structures/union_find.test.cpp.html">test/data_structures/union_find.test.cpp</a>
* :warning: <a href="verify/test/geometry/convex_hull.test.cpp.html">test/geometry/convex_hull.test.cpp</a>
* :warning: <a href="verify/test/geometry/intersection.test.cpp.html">test/geometry/intersection.test.cpp</a>
* :warning: <a href="verify/test/geometry/parallel_orthogonal.test.cpp.html">test/geometry/parallel_orthogonal.test.cpp</a>
* :warning: <a href="verify/test/graphs/dijkstra.test.cpp.html">test/graphs/dijkstra.test.cpp</a>
* :warning: <a href="verify/test/maths/mod_combination.test.cpp.html">test/maths/mod_combination.test.cpp</a>
* :warning: <a href="verify/test/maths/sieve_of_eratosthenes.test.cpp.html">test/maths/sieve_of_eratosthenes.test.cpp</a>
* :warning: <a href="verify/test/strings/rolling_hash.test.cpp.html">test/strings/rolling_hash.test.cpp</a>


