#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<ll> build(ll N, string s) {
  ll first = pow(2, N - 1);
  ll powed = first * 2;
  ll num = powed - 1;
  vector<ll> dp(num + 1);
  for (ll i = first; i < powed; i++) {
    if (s[i - 1] == '0' || s[i - 1] == '1') {
      dp[i] = 1;
    } else {
      dp[i] = 2;
    }
  }
  for (ll i = first - 1; i > 0; i--) {
    if (s[i - 1] == '1') {
      dp[i] = dp[i * 2];
    } else if (s[i - 1] == '0') {
      dp[i] = dp[i * 2 + 1];
    } else {
      dp[i] = dp[i * 2] + dp[i * 2 + 1];
    }
  }
  return dp;
}

int main() {
  ll N;
  string s;
  cin >> N >> s;
  ll q;
  cin >> q;
  reverse(s.begin(), s.end());
  ll first = pow(2, N - 1);
  ll powed = first * 2;
  ll num = powed - 1;
  auto dp = build(N, s);
  rep(i, 0, q) {
    ll idx;
    char c;
    cin >> idx >> c;
    s[powed - idx - 1] = c;

    ll target_num = powed - idx;
    if (target_num >= first) {
      if (c == '0' || c == '1') {
        dp[target_num] = 1;
      } else {
        dp[target_num] = 2;
      }
      target_num = target_num / 2;
      if (s[target_num - 1] == '1') {
        dp[target_num] = dp[target_num * 2];
      } else if (s[target_num - 1] == '0') {
        dp[target_num] = dp[target_num * 2 + 1];
      } else {
        dp[target_num] = dp[target_num * 2] + dp[target_num * 2 + 1];
      }
      target_num = target_num / 2;
    }
    while (target_num > 0) {
      if (s[target_num - 1] == '1') {
        dp[target_num] = dp[target_num * 2];
      } else if (s[target_num - 1] == '0') {
        dp[target_num] = dp[target_num * 2 + 1];
      } else {
        dp[target_num] = dp[target_num * 2] + dp[target_num * 2 + 1];
      }
      target_num = target_num / 2;
    }

    cout << dp[1] << endl;
  }
}