#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> hw(H, vector<ll>(W));
  ll mi = 1000;
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> hw[i][j];
      mi = min(mi, hw[i][j]);
    }
  }

  ll ans = 0;
  rep(i, 0, H) {
    rep(j, 0, W) { ans += hw[i][j] - mi; }
  }
  cout << ans << endl;
}