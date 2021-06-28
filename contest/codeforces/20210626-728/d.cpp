#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  map<ll, vector<ll>> edges;
  rep(i, 0, N - 1) {
    ll a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  map<ll, ll> sizes;
  for (auto e : edges) {
    sizes[e.first] = e.second.size();
  }

  rep(i, 1, N + 1) {
    bool vis[N + 1];
    stack<P> st; // num, depth, deno;
    map<ll, ll> si = sizes;
    // void dfs(ll num) {
    //   vis[num] = true;
    //   con.push_back(num);
    //   auto es = edges[num];
    //   for (auto e : es) {
    //     if (!vis[e]) {
    //       st.push(e);
    //       vis[e] = true;
    //       par[e] = num;
    //     }
    //   }
    //   while (!st.empty()) {
    //     auto top = st.top();
    //     st.pop();
    //     dfs(top);
    //   }
    // };
  }
}