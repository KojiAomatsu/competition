#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 二次元累積話

int main() {
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  vector<vector<ll>> DP(H + 1, vector<ll>(W + 1));
  rep(i, 0, H) rep(j, 0, W) { cin >> A[i][j]; }
  rep(i, 1, H + 1) rep(j, 1, W + 1) { DP[i][j] = A[i - 1][j - 1] + DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1]; }

  // get
  // ll sum = DP[H][W] - DP[i][j + K] - DP[i + K][j] + DP[i][j];

  // output
  for (auto vec : DP) {
    for (auto item : vec) {
      cout << item << ", ";
    }
    cout << "." << endl;
  }
}