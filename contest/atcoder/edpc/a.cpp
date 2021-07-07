#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> h(N);
  rep(i, 0, N) { cin >> h[i]; }

  vector<ll> dp(N);
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  rep(i, 2, N) { dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]); }
  cout << dp[N - 1] << endl;
}