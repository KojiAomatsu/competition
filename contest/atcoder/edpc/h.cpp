#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

char hw[1100][1100];
ll dp[1100][1100];

int main() {
  ll H, W;
  cin >> H >> W;
  rep(i, 0, H) {
    string s;
    cin >> s;
    rep(j, 0, W) { hw[i][j] = s[j]; }
  }

  rep(sum, 3, H + W + 1) {
    dp[1][1] = 1;
    rep(i, 1, H + 1) {
      ll j = sum - i;
      if (j < 1 || j > W) {
        continue;
      }
      if (hw[i - 1][j - 1] == '#') {
        dp[i][j] = 0;
      } else {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % (ll)(1E9 + 7);
      }
    }
  }

  cout << dp[H][W] << endl;
}