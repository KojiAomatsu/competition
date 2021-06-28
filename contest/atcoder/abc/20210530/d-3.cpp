#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  ll A[N][N];
  rep(i, 0, N) {
    rep(j, 0, N) { cin >> A[i][j]; }
  }

  ll left = 0;
  ll right = 1000000001;
  while (left + 1 < right) {
    ll cur = (left + right) / 2;
    ll bits[N][N] = {};
    ll DP[N + 1][N + 1] = {};
    rep(i, 0, N) rep(j, 0, N) { bits[i][j] = A[i][j] >= cur ? 1 : 0; }
    rep(i, 1, N + 1) rep(j, 1, N + 1) {
      DP[i][j] = bits[i - 1][j - 1] + DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1];
    }
    ll mini = 100000000001;
    rep(i, 0, N - K + 1) rep(j, 0, N - K + 1) {
      ll sum = DP[i + K][j + K] - DP[i][j + K] - DP[i + K][j] + DP[i][j];
      mini = min(mini, sum);
      continue;
    }

    if (mini >= (K * K / 2) + 1) {
      left = cur;
    } else {
      right = cur;
    }
  }
  cout << left << endl;
}