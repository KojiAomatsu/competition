#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[10010][10010];

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  ll mx = 0;
  rep(i, 0, N) {
    dp[i][i] = A[i];
    mx = max(mx, A[i]);
  }
  rep(width, 1, N) {
    rep(l, 0, N) {
      ll r = l + width;
      if (r >= N) break;
      dp[l][r] = min(dp[l][r - 1], A[r]);
      mx = max(mx, dp[l][r] * (width + 1));
    }
  }

  cout << mx << endl;
}
