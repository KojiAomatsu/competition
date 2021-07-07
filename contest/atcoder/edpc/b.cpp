#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> h(N);
  rep(i, 0, N) { cin >> h[i]; }
  vector<ll> dp(N);
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  rep(i, 2, N) {
    ll mi = 100000000000;
    rep(j, 1, K + 1) {
      if (i - j < 0) {
        break;
      }
      mi = min(mi, abs(h[i] - h[i - j]) + dp[i - j]);
    }
    dp[i] = mi;
  }
  cout << dp[N - 1] << endl;
}