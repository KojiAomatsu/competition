#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)
ll mod = 1E9 + 7;

ll dp[2220000]; // iまで決めた時にjの女性が残っている場合の数

int main() {
  ll N;
  cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  rep(i, 0, N) rep(j, 0, N) { cin >> A[i][j]; }
  ll initial = 0;
  for (int i = 0; i < N; i++) {
    initial = (initial << 1) + 1;
  }
  dp[initial] = 1;
  for (ll j = 1 << N; j >= 1; j--) {
    rep(k, 0, N) {
      int bc = __builtin_popcount(j);
      int i = N - bc;
      if (A[i][k]) {
        if (j & (1 << k)) {
          dp[j & ~(1 << k)] += dp[j];
          dp[j & ~(1 << k)] %= mod;
        }
      }
    }
  }
  cout << dp[0] << endl;
}