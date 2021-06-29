#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll sum[3010];
ll dp[3010][3010];
ll memo[3010][3010];

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) { sum[i + 1] += sum[i] + A[i]; }

  rep(i, 1, N + 1) {
    dp[i][1] = 1;
    rep(j, 2, i + 1) { dp[i][j] = memo[j][sum[i] % j]; }

    memo[2][sum[i] % 2] += dp[i][1];
    rep(j, 2, i + 1) {
      memo[j + 1][sum[i] % (j + 1)] += dp[i][j];
      memo[j + 1][sum[i] % (j + 1)] %= (ll)(1E9 + 7);
    }
  }

  ll ans = 0;
  rep(i, 1, N + 1) {
    ans += dp[N][i];
    ans %= (ll)(1E9 + 7);
  }
  cout << ans << endl;
}
