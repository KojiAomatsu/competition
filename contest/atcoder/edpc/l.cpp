#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[3300][3300]; // start, end, x - y

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) {
    if ((N - 1) % 2 == 0) {
      // first
      dp[i][i] = A[i];
    } else {
      // second
      dp[i][i] = -1 * A[i];
    }
  }
  rep(le, 1, N) {
    rep(i, 0, N) {
      ll j = i + le;
      if (j >= N) break;
      if ((N - (le + 1)) % 2 == 0) {
        // first
        dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j]);
      } else {
        // second
        dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j]);
      }
    }
  }
  cout << dp[0][N - 1] << endl;
}