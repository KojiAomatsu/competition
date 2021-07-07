#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll d[500][500];
ll inf = 110110110110110110;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  vector<ll> B(M);
  vector<ll> C(M);
  rep(i, 0, 500) {
    rep(j, 0, 500) { d[i][j] = inf; }
  }
  rep(i, 0, M) {
    cin >> A[i] >> B[i] >> C[i];
    d[A[i] - 1][B[i] - 1] = C[i];
  }

  ll ans = 0;
  for (int k = 0; k < N; k++) {     // 経由する頂点
    for (int i = 0; i < N; i++) {   // 始点
      for (int j = 0; j < N; j++) { // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        if (d[i][j] != inf && i != j) {
          ans += d[i][j];
        }
      }
    }
  }
  cout << ans << endl;
}