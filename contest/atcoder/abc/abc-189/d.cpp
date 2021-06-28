#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[2][100];

int main() {
  ll N;
  cin >> N;
  vector<bool> S(N);
  rep(i, 0, N) {
    string s;
    cin >> s;
    if (s == "AND")
      S[i] = true;
    else
      S[i] = false;
  }
  dp[0][0] = 1;
  dp[1][0] = 1;
  rep(i, 1, N + 1) {
    if (S[i - 1]) {
      dp[0][i] = dp[0][i - 1] * 2 + dp[1][i - 1];
      dp[1][i] = dp[1][i - 1];
    } else {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = dp[0][i - 1] + dp[1][i - 1] * 2;
    }
  }
  cout << dp[1][N] << endl;
}
