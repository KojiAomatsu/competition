#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 巡回セールスマン問題 実装例

ll dp[220000][20];
ll edges[20][20];

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N);
  vector<ll> Y(N);
  vector<ll> Z(N);
  rep(i, 0, N) { cin >> X[i] >> Y[i] >> Z[i]; }

  rep(i, 0, N) rep(j, 0, N) {
    if (i == j) continue;
    edges[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + max(0LL, Z[j] - Z[i]);
  }

  rep(i, 0, 220000) rep(j, 0, 20) { dp[i][j] = 1E18; }
  rep(i, 0, N) { dp[0][0] = 0; }

  rep(i, 0, 1 << (N - 1)) {
    set<ll> vis;
    set<ll> nonvis;
    rep(j, 0, N - 1) {
      if (i & 1 << j) {
        vis.insert(j + 1);
      } else {
        nonvis.insert(j + 1);
      }
    }
    for (auto nonv : nonvis) {
      dp[i | 1 << (nonv - 1)][nonv] = min(dp[i | 1 << (nonv - 1)][nonv], dp[i][0] + edges[0][nonv]);
      for (auto vi : vis) {
        dp[i | 1 << (nonv - 1)][nonv] = min(dp[i | 1 << (nonv - 1)][nonv], dp[i][vi] + edges[vi][nonv]);
      }
    }
  }

  ll ans = 1E18;
  rep(i, 1, N) { ans = min(ans, dp[(1 << (N - 1)) - 1][i] + edges[i][0]); }
  cout << ans << endl;
}