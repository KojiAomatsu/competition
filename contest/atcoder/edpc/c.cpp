#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[3][110000];

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N + 1);
  vector<ll> b(N + 1);
  vector<ll> c(N + 1);
  rep(i, 1, N + 1) { cin >> a[i] >> b[i] >> c[i]; }

  rep(i, 1, N + 1) {
    dp[0][i] = max(dp[1][i - 1] + a[i], dp[2][i - 1] + a[i]);
    dp[1][i] = max(dp[0][i - 1] + b[i], dp[2][i - 1] + b[i]);
    dp[2][i] = max(dp[0][i - 1] + c[i], dp[1][i - 1] + c[i]);
  }
  cout << max({dp[0][N], dp[1][N], dp[2][N]}) << endl;
}