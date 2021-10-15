#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

template <typename... Args>
auto printll(Args... xs) -> decltype(std::initializer_list<ll>{xs...}, std::declval<void>()) {
  for (auto &&x : {xs...}) {
    cout << x << " ";
  }
  cout << endl;
}

ll dp[110][110000]; // i までは行ったj個の場合の数
ll mod = 1E9 + 7;

int main() {
  ll N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }

  dp[0][0] = 1;
  rep(i, 0, N) {
    vector<ll> sums(K + 1 + 1); // i のときのdp[i][*]の累積和
    rep(m, 0, K + 1) {
      sums[m + 1] = sums[m] + dp[i][m];
      sums[m + 1] %= mod;
    }
    rep(j, 0, K + 1) {
      dp[i + 1][j] = sums[j + 1] - sums[max(0ll, j - A[i])] + mod;
      dp[i + 1][j] %= mod;
    }
  }

  cout << dp[N][K] << endl;

  return 0;
}
