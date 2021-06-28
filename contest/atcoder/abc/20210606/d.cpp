#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> T(N);
  ll sum = 0;
  rep(i, 0, N) {
    cin >> T[i];
    sum += T[i];
  }
  if (N == 1) {
    cout << T[0] << endl;
  }
  bool dp[N + 1][sum + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  rep(i, 0, N) {
    rep(j, 0, sum) {
      dp[i + 1][j] |= dp[i][j];
      if (j >= T[i]) {
        dp[i + 1][j] |= dp[i][j - T[i]];
      }
    }
  }
  if (sum % 2 == 0) {
    for (ll j = sum / 2; j < sum + 1; j++) {
      rep(i, 0, N) {
        if (dp[i + 1][j]) {
          cout << j << endl;
          return 0;
        }
      }
    }
  } else {
    for (ll j = (sum / 2) + 1; j < sum + 1; j++) {
      rep(i, 0, N) {
        if (dp[i + 1][j]) {
          cout << j << endl;
          return 0;
        }
      }
    }
  }
}