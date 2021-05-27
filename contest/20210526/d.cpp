#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;

  vector<ll> li(N);

  for (auto &ele : li) {
    cin >> ele;
  }

  map<ll, ll> dp;
  dp[0] = 0;
  vector<vector<vector<vector<ll>>>> ans_dp(
      N, vector<vector<vector<ll>>>(200, vector<vector<ll>>()));
  rep(i, 0, N) {
    map<ll, ll> new_dp = dp;
    for (auto el : dp) {
      if (new_dp.count((el.first + li[i]) % 200) == 0) {
        new_dp[(el.first + li[i]) % 200] = 1;
        ans_dp[i][(el.first + li[i]) % 200] = {{i + 1}};
      } else {
        new_dp[(el.first + li[i]) % 200] += 1;
        auto tmp = ans_dp[i][el.first];
        for (auto ele : tmp) {
          ele.push_back(i + 1);
        }
        ans_dp[i][(el.first + li[i]) % 200] = tmp;
      }
    }
    dp = new_dp;
  }

  ll ans;
  for (auto ele : dp) {
    if (ele.second > 1) {
      cout << "Yes" << endl;
      ans = ele.second;
      goto out_of_loop;
    }
  }
  cout << "No" << endl;
  return 0;
out_of_loop:
  vector<ll> x = ans_dp[N - 1][ans][0];
  // vector<ll> y = ans_dp[N - 1][ans][1];
  cout << "x";
  for (auto item : x) {
    cout << " " << item;
  }
  cout << endl;
  // cout << "y";
  // for (auto item : y) {

  //   cout << " " << item;
  // }
  // cout << endl;
  return 0;
}
