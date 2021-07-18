#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<string> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  string corr = A[0];
  ll part = 1;
  ll oppo = 0;
  rep(i, 1, N) {
    ll difc = 0;
    rep(j, 0, M) {
      if (corr[j] != A[i][j]) {
        difc++;
      }
    }
    if (difc % 2 == 0) {
      part++;
    } else {
      oppo++;
    }
  }
  ll ans = N * (N - 1) / 2;
  ans -= part * (part - 1) / 2;
  ans -= oppo * (oppo - 1) / 2;
  cout << ans << endl;
}