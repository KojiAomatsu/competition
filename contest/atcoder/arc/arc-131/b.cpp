#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> c(H, vector<ll>(W, 0));
  set<P> uncolored;
  rep(i, 0, H) {
    rep(j, 0, W) {
      char cij;
      cin >> cij;
      if (cij == '.') {
        c[i][j] == 0;
        uncolored.insert({i, j});
      } else {
        c[i][j] = cij - '0';
      }
    }
  }

  vector<pair<ll, ll>> units = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (auto uc : uncolored) {
    vector<ll> usedcolor(6, 0);
    for (auto u : units) {
      ll x = uc.first + u.first;
      ll y = uc.second + u.second;
      if (x < 0 || x >= H || y < 0 || y >= W) {
        continue;
      } else {
        ll cxy = c[x][y];
        usedcolor[cxy]++;
      }
    }
    rep(i, 1, 6) {
      if (usedcolor[i] == 0) {
        c[uc.first][uc.second] = i;
        break;
      }
    }
  }
  for (auto vec : c) {
    for (auto item : vec) {
      cout << item;
    }
    cout << endl;
  }
}
