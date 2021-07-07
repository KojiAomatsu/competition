#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[110][100100]; // i までを使って重さwまでの価値の最大値

int main() {
  ll N, W;
  cin >> N >> W;
  vector<ll> w(N);
  vector<ll> v(N);
  rep(i, 0, N) { cin >> w[i] >> v[i]; }
  rep(i, 0, N) {
    rep(j, 0, W + 1) { dp[i + 1][j] = dp[i][j]; }
    rep(j, 0, W + 1) {
      if (j - w[i] >= 0) {
        dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
      }
    }
  }

  ll mx = 0;
  rep(i, 0, W + 1) { mx = max(mx, dp[N][i]); }
  cout << mx << endl;
}