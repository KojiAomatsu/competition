#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 1E9 + 7;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> edges(N);
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    edges[ai].push_back(bi);
    edges[bi].push_back(ai);
  }

  vector<ll> dis(N); // 1 からの距離
  vector<ll> ways(N);
  vector<bool> vis(N, false);
  queue<P> q;

  q.push({0, 0});
  dis[0] = 0;
  ways[0] = 1;
  vis[0] = true;
  while (!q.empty()) {
    P nod = q.front();
    q.pop();
    for (auto chi : edges[nod.first]) {
      if (vis[chi]) {
        if (dis[chi] == nod.second + 1) {
          ways[chi] += ways[nod.first];
          ways[chi] %= mod;
        }
        continue;
      }
      q.push({chi, nod.second + 1});
      dis[chi] = nod.second + 1;
      ways[chi] = ways[nod.first];
      vis[chi] = true;
    }
  }

  ways[N - 1] %= mod;

  cout << ways[N - 1] << endl;
}