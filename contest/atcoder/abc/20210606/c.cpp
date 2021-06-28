#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> edges(M);
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    edges[i] = {ai, bi};
  }
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0)); // i -> j にいけたら1, 無理なら0.
  rep(i, 1, N + 1) { dp[i][i] = 1; }

  for (auto edge : edges) {
    ll ai = edge.first;
    ll bi = edge.second;
    for (ll i = 1; i < N + 1; i++) {
      if (dp[i][ai] == 1) {
        if (dp[i][bi] == 0) {
          rep(k, 0, N) {
            ll flag = dp[bi][k + 1];
            if (flag == 1) {
              dp[i][k + 1] = 1;
            }
          }
        }
        dp[i][bi] = 1;
      }
    }
  }

  ll ret = 0;
  rep(i, 0, N + 1) rep(j, 0, N + 1) { ret += dp[i][j]; }

  cout << ret << endl;
}