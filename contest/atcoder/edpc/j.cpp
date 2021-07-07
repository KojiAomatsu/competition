#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

double dp[330][330][330];
ll cnt[4];

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) {
    cin >> A[i];
    cnt[A[i]]++;
  }

  dp[1][0][0] = (double)N;
  rep(sum, 1, 901) {
    rep(i3, 0, 301) {
      rep(i2, 0, 301) {
        ll i1 = sum - i2 - i3;
        if (i1 < 0 || i1 > 300) continue;
        if (i1 == 1 && i2 == 0 && i3 == 0) continue;
        if (i1 != 0) dp[i1][i2][i3] += (dp[i1 - 1][i2][i3]) * i1 / (double)N;
        if (i2 != 0) dp[i1][i2][i3] += (dp[i1 + 1][i2 - 1][i3]) * i2 / (double)N;
        if (i3 != 0) dp[i1][i2][i3] += (dp[i1][i2 + 1][i3 - 1]) * i3 / (double)N;
        dp[i1][i2][i3] = (1 + dp[i1][i2][i3]) * N / (double)(sum);
      }
    }
  }

  printf("%.11f", dp[cnt[1]][cnt[2]][cnt[3]]);
}