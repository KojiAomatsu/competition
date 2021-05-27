#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  map<ll, ll> dp;
  dp[0] = 0;
  dp[3] = 3;
  map<ll, ll> new_dp;
  new_dp = dp;
  for (auto ele : dp) {
    new_dp[ele.first + ele.second] += 1;
  }
  new_dp[4] = 3;
  dp = new_dp;
  for (auto item : dp) {
    cout << item.first << " " << item.second << ", ";
  }
  cout << endl;
}
