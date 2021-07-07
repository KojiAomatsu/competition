#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[3300][3300];

int main() {
  string s, t;
  cin >> s >> t;

  ll ns = s.size();
  ll nt = t.size();
  rep(i, 0, ns) {
    rep(j, 0, nt) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  string ans = "";
  ll cur = dp[ns][nt];
  ll cur_j = nt;
  for (ll i = ns; i >= 1; i--) {
    for (ll j = nt; j >= 1; j--) {
      if (cur_j < j) {
        continue;
      }
      if (dp[i - 1][j - 1] == cur) {
        cur_j = j - 1;
        break;
      }
      if (dp[i][j - 1] == cur) {
        cur_j = j - 1;
        continue;
      }
      if (dp[i - 1][j] == cur) {
        break;
      }
      if (dp[i][j] == cur) {
        ans += s[i - 1];
        cur_j--;
        cur--;
        break;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}