#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll find_mid(vector<ll> ve) {
  sort(ve.begin(), ve.end());
  return ve[ve.size() / 2];
}

int main() {
  ll N, K;
  cin >> N >> K;
  vector<vector<ll>> park(N, vector<ll>(N));
  rep(i, 0, N) {
    rep(j, 0, N) { cin >> park[j][i]; }
  }

  vector<vector<vector<ll>>> dp(N - K + 1, vector<vector<ll>>(N - K + 1));
  ll cur_min_mid = 1100100100100;

  rep(t, 0, N - K + 1) {
    vector<ll> range;
    rep(i, 0, K) {
      rep(j, 0, K) { range.push_back(park[i + t][j]); }
    }
    dp[t][0] = range;
    cur_min_mid = min(find_mid(range), cur_min_mid);
  }
  if (N == K) {
    cout << cur_min_mid << endl;
    return 0;
  }

  rep(i, 0, N - K + 1) {
    rep(j, 1, N - K + 1) {
      vector<ll> temp_range = dp[i][j - 1];
      rep(t, 0, K) {
        temp_range.erase(temp_range.begin());
        temp_range.push_back(park[i + t][j - 1 + K]);
      }
      cur_min_mid = min(find_mid(temp_range), cur_min_mid);
      dp[i][j] = temp_range;
    }
  }

  cout << cur_min_mid << endl;
}