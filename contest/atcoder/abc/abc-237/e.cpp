#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> H(N);
  rep(i, 0, N) { cin >> H[i]; }
  vector<vector<pair<ll, ll>>> edges(N);
  rep(i, 0, M) {
    ll ui, vi;
    cin >> ui >> vi;
    ui--;
    vi--;
    edges[ui].push_back(make_pair(vi, max(0ll, H[vi] - H[ui])));
    edges[vi].push_back(make_pair(ui, max(0ll, H[ui] - H[vi])));
  }

  // 負の辺があるダイクストラの例 dijkstra
  // ポテンシャルを用いた距離に変換している
  ll ans = 0;
  priority_queue<P, vector<P>, greater<P>> pq; // cost, to;
  vector<ll> dist(N, INT64_MAX);
  dist[0] = 0;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    P top = pq.top();
    pq.pop();
    ll v = top.second;
    ll c = top.first;
    if (dist[v] < c) continue;
    ans = max(ans, -(dist[v] + H[v] - H[0]));
    for (auto ed : edges[v]) {
      ll to = ed.first;
      ll co = ed.second;
      if (dist[to] > dist[v] + co) {
        dist[to] = dist[v] + co;
        pq.push(make_pair(dist[v] + co, to));
      }
    }
  }
  cout << ans << endl;
}

/*
ll calcCost(int from, int to) {
  if (from > to) {
    return to - from;
  } else {
    return (to - from) * 2;
  }
}

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> H(N);
  rep(i, 0, N) { cin >> H[i]; }
  vector<vector<pair<ll, ll>>> edges(N);
  rep(i, 0, M) {
    ll ui, vi;
    cin >> ui >> vi;
    ui--;
    vi--;
    edges[ui].push_back(make_pair(vi, calcCost(H[ui], H[vi])));
    edges[vi].push_back(make_pair(ui, calcCost(H[vi], H[ui])));
  }

  ll ans = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<ll> dist(N, INT64_MAX);
  dist[0] = 0;
  pq.push(make_pair(0, 0)); // cost, to;
  while (!pq.empty()) {
    P top = pq.top();
    pq.pop();
    ll v = top.second;
    ll c = top.first;
    ans = max(ans, -c);
    if (dist[v] < c) continue;
    for (auto ed : edges[v]) {
      ll to = ed.first;
      ll co = ed.second;
      if (dist[to] > dist[v] + co) {
        dist[to] = dist[v] + co;
        pq.push(make_pair(dist[v] + co, to));
      }
    }
  }
  cout << ans << endl;
}
*/