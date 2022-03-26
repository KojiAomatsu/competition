#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)
ll mod = 1E9 + 7;

ll dp[11000][110][2]; // i桁まで決まっていてmod jの個数, k: smaller

int main() {
  string K;
  int D;
  cin >> K >> D;
  dp[0][0][0] = 1;
  for (int i = 0; i < K.size(); i++) {
    for (int j = 0; j < D; j++) {
      for (int k = 0; k < 10; k++) {
        dp[i + 1][(j + k) % D][1] += dp[i][j][1];
        dp[i + 1][(j + k) % D][1] %= mod;
        if ((K[i] - '0') > k) dp[i + 1][(j + k) % D][1] += dp[i][j][0];
        if ((K[i] - '0') == k) dp[i + 1][(j + k) % D][0] += dp[i][j][0];
        dp[i + 1][(j + k) % D][1] %= mod;
      }
    }
  }
  ll ans = dp[K.size()][0][1] + dp[K.size()][0][0];
  ans %= mod;
  ans += mod - 1;
  ans %= mod;
  cout << ans << endl;
}