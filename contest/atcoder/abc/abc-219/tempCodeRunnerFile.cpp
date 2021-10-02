#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[500][500][500];

int main() {
  ll N;
  cin >> N;
  ll X, Y;
  cin >> X >> Y;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, 0, N) { cin >> A[i] >> B[i]; }
  ll suma = accumulate(A.begin(), A.end(), 0ll);
  ll sumb = accumulate(B.begin(), B.end(), 0ll);
  if (X > suma || Y > sumb) {
    cout << -1 << endl;
    return 0;
  }

  rep(i, 0, 400) {
    rep(j, 0, 400) {
      rep(k, 0, 400) { dp[i][j][k] = 1E11; }
    }
  }

  rep(i, 0, 400) { dp[i][0][0] = 0; }

  rep(i, 0, N) {
    rep(j, 0, X) {
      rep(k, 0, Y) {
        if (j < A[i] && k < B[i]) {
          dp[i + 1][j][k] = min(dp[i][j][k], 1ll);
        } else if (j >= A[i] && k >= B[i]) {
          dp[i + 1][j][k] = min(dp[i][j - A[i]][k - B[i]] + 1, dp[i][j][k]);
        } else if (j >= A[i]) {
          dp[i + 1][j][k] = min(dp[i][j - A[i]][0] + 1, dp[i][j][k]);
        } else if (k >= B[i]) {
          dp[i + 1][j][k] = min(dp[i][0][k - B[i]] + 1, dp[i][j][k]);
        }
      }
    }
  }

  cout << dp[N][X][Y] << endl;
}