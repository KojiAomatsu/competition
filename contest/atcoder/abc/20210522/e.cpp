#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

std::vector<std::vector<int>> children, li;
std::vector<int> in, out, depth;
int timer;

void dfs(const int u) {
  in[u] = timer++;
  li[depth[u]].push_back(in[u]);
  for (const int v : children[u]) {
    depth[v] = depth[u] + 1;
    dfs(v);
  }
  out[u] = timer++;
}

int main() {
  int N;
  std::cin >> N;
  children = li = std::vector<std::vector<int>>(N);
  in = out = depth = std::vector<int>(N);
  for (int i = 1; i < N; ++i) {
    int p;
    std::cin >> p;
    children[p - 1].push_back(i);
  }
  dfs(0);
  int Q;
  std::cin >> Q;
  while (Q--) {
    int u, d;
    std::cin >> u >> d;
    u -= 1;
    const auto &v = li[d];
    std::cout << std::lower_bound(v.cbegin(), v.cend(), out[u]) -
                     std::lower_bound(v.cbegin(), v.cend(), in[u])
              << '\n';
  }
  return 0;
}
