#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll t;
  cin >> t;
  rep(i, 0, t) {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(n);
    rep(j, 0, m) {
      ll ai, bi;
      cin >> ai >> bi;
      ai--;
      bi--;
      edges[ai].push_back(bi);
    }

    vector<ll> cnt(n, 0);
    vector<bool> vis(n, false);
    vector<bool> nomore(n, false);
    queue<P> q; // node, parent
    rep(i, 0, edges[0].size()) { q.push({edges[0][i], 0}); }
    vis[0] = true;
    cnt[0] = 1;
    while (!q.empty()) {
      P nod = q.front();
      q.pop();
      if (cnt[nod.second] == -1) {
        cnt[nod.first] = -1;
      } else if (nod.second == nod.first) {
        cnt[nod.first] == -1;
      } else if (cnt[nod.first] == 1) {
        cnt[nod.first] = 2;
      } else if (cnt[nod.first] == 0) {
        cnt[nod.first] = 1;
      }
      set<ll> tmp_vis;
      for (auto chi : edges[nod.first]) {
        if (vis[chi]) {
          if (nod.first == chi) {
            cnt[nod.first] = -1;
            tmp_vis.insert(nod.first);
            nomore[nod.first] = true;
            continue;
          }
          if (nomore[chi]) {
            continue;
          } else {
            q.push({chi, nod.first});
            cnt[chi] = -1;
            nomore[chi] = true;
          }
        }

        q.push({chi, nod.first});
        tmp_vis.insert(nod.first);
      }

      for (auto vi : tmp_vis) {
        vis[vi] = true;
      }
    }

    for (auto item : cnt) {
      cout << item << " ";
    }
    cout << endl;
  }
}