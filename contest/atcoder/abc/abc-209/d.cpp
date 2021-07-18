#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// BFS 実装例 幅優先探索

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<vector<ll>> edges(N);
  rep(i, 0, N - 1) {
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    edges[ai].push_back(bi);
    edges[bi].push_back(ai);
  }
  vector<ll> dis(N); // 1 からの距離
  vector<bool> vis(N, false);
  queue<P> q;
  q.push({0, 0});
  dis[0] = 0;
  vis[0] = true;
  while (!q.empty()) {
    P nod = q.front();
    q.pop();
    for (auto chi : edges[nod.first]) {
      if (vis[chi]) continue;
      q.push({chi, nod.second + 1});
      dis[chi] = nod.second + 1;
      vis[chi] = true;
    }
  }

  rep(i, 0, Q) {
    ll ci, di;
    cin >> ci >> di;
    ll isTown = (dis[ci - 1] + dis[di - 1]) % 2 == 0;
    cout << (isTown ? "Town" : "Road") << endl;
  }
}