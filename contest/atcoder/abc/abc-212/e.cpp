#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[5500][5500]; // 0 から i までに j 日の片道旅
ll mod = 998244353;

int main() {
  ll N, M, K;
  cin >> N >> M >> K;
  vector<vector<bool>> okedges(N, vector<bool>(N, true));
  vector<vector<ll>> ngedges(N);

  rep(i, 0, M) {
    ll ui, vi;
    cin >> ui >> vi;
    ui--;
    vi--;
    okedges[ui][vi] = false;
    okedges[vi][ui] = false;
    ngedges[ui].push_back(vi);
    ngedges[vi].push_back(ui);
  }

  rep(i, 1, N) {
    if (okedges[0][i]) {
      dp[i][1] = 1;
    }
  }

  rep(j, 2, K) { // j 日の片道旅
    ll all_ways = 0;
    rep(i, 0, N) {
      all_ways += dp[i][j - 1];
      all_ways %= mod;
    }
    rep(i, 0, N) {
      dp[i][j] = all_ways;

      auto vs = ngedges[i];
      for (auto v : vs) {
        dp[i][j] -= dp[v][j - 1];
        dp[i][j] += mod;
        dp[i][j] %= mod;
      }
      dp[i][j] -= dp[i][j - 1];
      dp[i][j] += mod;
      dp[i][j] %= mod;
    }
  }

  ll ans = 0;
  rep(j, 1, (K + 1) / 2) {
    rep(i, 0, N) {
      ans += dp[i][j] * dp[i][K - j] % mod;
      ans %= mod;
    }
  }
  cout << ans << endl;
}