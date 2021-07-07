#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[110][101000]; // i までを使って価値vにする最小の重さ

int main() {
  ll N, W;
  cin >> N >> W;
  vector<ll> w(N);
  vector<ll> v(N);
  rep(i, 0, N) { cin >> w[i] >> v[i]; }
  rep(i, 0, N) {
    rep(j, 0, 100001) {
      if (i == 0) {
        if (j == 0) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = 1100100100;
        }
      }
    }
    rep(j, 0, 100001) {
      dp[i + 1][j] = dp[i][j];
      if (j - v[i] >= 0) {
        dp[i + 1][j] = min(dp[i][j - v[i]] + w[i], dp[i][j]);
      }
    }
  }

  for (ll j = 100000; j >= 0; j--) {
    ll wei = dp[N][j];
    if (wei <= W) {
      cout << j << endl;
      return 0;
    }
  }
}