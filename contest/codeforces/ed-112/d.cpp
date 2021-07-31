#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string rs = s;
  reverse(rs.begin(), rs.end());
  vector<ll> dp(n);
  vector<ll> rdp(n);
  rep(i, 1, n) {
    if (i == 1) {
      if (s[i - 1] == s[i]) {
        dp[1] = 1;
        s[i] = 'a' + (s[i - 1] - 'a' + 1) % 3;
        continue;
      } else {
        dp[1] = 0;
        continue;
      }
    } else { // i > 1
      if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
        dp[i] = dp[i - 1] + 1;
        s[i] = 'a' + (3 - ((s[i - 1] - 'a') + (s[i - 2] - 'a'))) % 3;
        continue;
      } else {
        dp[i] = dp[i - 1];
        continue;
      }
    }
  }

  swap(s, rs);
  rep(i, 1, n) {
    if (i == 1) {
      if (s[i - 1] == s[i]) {
        rdp[1] = 1;
        s[i] = 'a' + (s[i - 1] - 'a' + 1) % 3;
        continue;
      } else {
        rdp[1] = 0;
        continue;
      }
    } else { // i > 1
      if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
        rdp[i] = rdp[i - 1] + 1;
        s[i] = 'a' + (3 - ((s[i - 1] - 'a') + (s[i - 2] - 'a'))) % 3;
        continue;
      } else {
        rdp[i] = rdp[i - 1];
        continue;
      }
    }
  }

  rep(i, 0, m) {
    ll li, ri;
    cin >> li >> ri;
    li--;
    ri--;
    ll ans1 = dp[ri] - dp[li];
    ll ans2 = rdp[n - 1 - li] - rdp[n - 1 - ri];
    cout << min(ans1, ans2) << endl;
  }
}