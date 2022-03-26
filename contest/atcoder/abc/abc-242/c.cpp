#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 998244353;
int main() {
  ll N;
  cin >> N;
  vector<ll> dp(10, 0);
  rep(i, 1, 10) { dp[i] = 1; }
  rep(i, 1, N) {
    vector<ll> nDP(10);
    rep(j, 1, 10) {
      nDP[j] += dp[j];
      if (j > 1) {
        nDP[j - 1] += dp[j];
      }
      if (j < 9) {
        nDP[j + 1] += dp[j];
      }
    }
    rep(j, 1, 10) { nDP[j] %= mod; }
    dp = nDP;
  }
  ll ans = 0;
  rep(i, 1, 10) {
    ans += dp[i];
    ans %= mod;
  }
  cout << ans << endl;
}