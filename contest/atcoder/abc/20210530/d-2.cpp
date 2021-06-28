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
    ll DP[N][N] = {};
    rep(i, 0, N) rep(j, 0, N) { bits[i][j] = A[i][j] >= cur ? 1 : 0; }

    rep(i, 0, N) {
      ll cur_i[N] = {};
      rep(j, 0, N) {
        cur_i[i] = cur_i[i] + bits[i][j];
        DP[i][j] = cur_i[i];
      }
    }
    rep(j, 0, N) {
      ll cur_j[N] = {};
      cur_j[j] = DP[0][j];
      rep(i, 1, N) {
        cur_j[j] = cur_j[j] + DP[i][j];
        DP[i][j] = cur_j[j];
      }
    }

    ll mini = 100000000001;
    rep(i, 0, N - K + 1) rep(j, 0, N - K + 1) {
      ll sum = DP[i + K - 1][j + K - 1];
      if (i == 0 && j == 0) {
        mini = min(mini, sum);
        continue;
      }
      if (i > 0 && j == 0) {
        sum -= DP[i - 1][j + K - 1];
        mini = min(mini, sum);
        continue;
      }
      if (j > 0 && i == 0) {
        sum -= DP[i + K - 1][j - 1];
        mini = min(mini, sum);
        continue;
      }
      sum = sum - DP[i - 1][j + K - 1] - DP[i + K - 1][j - 1] + DP[i - 1][j - 1];
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