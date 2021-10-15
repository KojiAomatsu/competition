#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 998244353;

template <typename... Args>
auto printll(Args... xs) -> decltype(std::initializer_list<ll>{xs...}, std::declval<void>()) {
  for (auto &&x : {xs...}) {
    cout << x << " ";
  }
  cout << endl;
}

ll dp[3300][3300]; // i 番目が j のときの場合の数

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) { cin >> B[i]; }

  rep(j, 0, 3100) { dp[N][j] = 1; }
  rep(i, 0, N) {
    ll idx = N - i - 1;
    ll al = 0;
    for (ll j = B[idx]; j >= 0; j--) {
      if (j < A[idx]) {
        dp[idx][j] = al;
        continue;
      }
      dp[idx][j] = al + dp[idx + 1][j];
      al += dp[idx + 1][j];
      al %= mod;
    }
  }
  ll ans = 0;
  if (N == 1) {
    ans = B[0] - A[0] + 1;
  } else {
    rep(j, A[0], B[0] + 1) {
      ans += dp[1][j];
      ans %= mod;
    }
  }
  cout << ans << endl;
}
