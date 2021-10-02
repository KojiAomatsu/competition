#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[11][110000]; // 上から j 桁が決定しているときに最後が i になる場合の数
ll mod = 998244353;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }

  dp[A[0]][1] = 1;

  rep(j, 1, N) {    // j 個確定している
    rep(i, 0, 10) { // 最後が i である
      ll nex = A[j];
      ll nf = (i + nex) % 10;
      ll ng = (i * nex) % 10;
      dp[nf][j + 1] += dp[i][j];
      dp[nf][j + 1] %= mod;
      dp[ng][j + 1] += dp[i][j];
      dp[ng][j + 1] %= mod;
    }
  }

  rep(i, 0, 10) { cout << dp[i][N] << endl; }
}