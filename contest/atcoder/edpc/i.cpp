#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

double dp[3000][6060]; // iまでを使ってj-3000個の差がある確率

int main() {
  ll N;
  cin >> N;
  vector<double> p(N);
  rep(i, 0, N) { cin >> p[i]; }

  ll ori = 3000;
  dp[0][3000] = 1.0;
  rep(j, 0, 6010) {
    rep(i, 0, N) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    }
  }
  double ans = 0;
  rep(j, (N / 2) + 1, N + 1) { ans += dp[N][3000 + j]; }

  printf("%.12f", ans);
}