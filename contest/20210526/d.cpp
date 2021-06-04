#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 経路をメモしながらDPで部分集合の和を一致させる問題

int main() {
  ll N;
  cin >> N;

  vector<ll> li(N);

  for (auto &ele : li) {
    cin >> ele;
  }

  map<ll, ll> dp;
  vector<vector<vector<vector<ll>>>> ans_dp(
      N + 1, vector<vector<vector<ll>>>(200, vector<vector<ll>>({})));
  ans_dp[0][0] = {{}};
  rep(i, 0, N) {
    rep(j, 0, 200) {
      if (ans_dp[i][j].size() == 0)
        continue;
      auto cell = ans_dp[i + 1][j];
      cell.insert(cell.end(), ans_dp[i][j].begin(), ans_dp[i][j].end());
      ans_dp[i + 1][j] =
          vector(cell.begin(), cell.begin() + min(3, int(cell.size())));

      vector<vector<ll>> tmp = ans_dp[i][j];
      for (auto &arr : tmp) {
        arr.push_back(i + 1);
      }
      auto new_cell = ans_dp[i + 1][(j + li[i]) % 200];
      new_cell.insert(new_cell.end(), tmp.begin(), tmp.end());
      ans_dp[i + 1][(j + li[i]) % 200] = vector(
          new_cell.begin(), new_cell.begin() + min(3, int(new_cell.size())));
    }
  }
  if (ans_dp[N][0].size() >= 3) {
    cout << "Yes" << endl;
    cout << ans_dp[N][0][1].size();
    for (auto ele : ans_dp[N][0][1]) {
      cout << " " << ele;
    }
    cout << endl;
    cout << ans_dp[N][0][2].size();
    for (auto ele : ans_dp[N][0][2]) {
      cout << " " << ele;
    }
    cout << endl;
    return 0;
  }
  rep(i, 1, 200) {
    if (ans_dp[N][i].size() >= 2) {
      cout << "Yes" << endl;
      cout << ans_dp[N][i][0].size();
      for (auto ele : ans_dp[N][i][0]) {
        cout << " " << ele;
      }
      cout << endl;
      cout << ans_dp[N][i][1].size();
      for (auto ele : ans_dp[N][i][1]) {
        cout << " " << ele;
      }
      cout << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
