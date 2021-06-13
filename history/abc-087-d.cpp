#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  map<ll, vector<pair<ll, ll>>> childs; // pair first number second distance
  rep(i, 0, M) {
    ll li, ri, di;
    cin >> li >> ri >> di;
    childs[li].push_back({ri, di});
    childs[ri].push_back({li, -di});
  }
  bool vis[N + 1] = {};

  rep(i, 1, N + 1) {
    queue<pair<ll, ll>> q; // num, parent
    map<ll, ll> dist;
    if (!vis[i]) {
      q.push({i, 0});
      dist[i] = 0;
    }
    while (q.empty() == false) {
      auto top = q.front();
      q.pop();
      vis[top.first] = true;
      for (auto chi : childs[top.first]) {
        if (dist.count(chi.first) != 0) {
          if (dist[chi.first] != dist[top.first] + chi.second) {
            std::cout << "No" << endl;
            return 0;
          }
        }
        if (vis[chi.first] == false) {
          q.push({chi.first, top.first});
          dist[chi.first] = dist[top.first] + chi.second;
          vis[chi.first] = true;
        }
      }
    }
  }
  std::cout << "Yes" << endl;
}