#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  vector<ll> B(M);
  rep(i, 0, M) { cin >> A[i] >> B[i]; }
  ll K;
  cin >> K;
  vector<ll> C(K);
  vector<ll> D(K);
  rep(i, 0, K) { cin >> C[i] >> D[i]; }

  ll mx = 0;
  for (ll msk = 0; msk < 1 << K; msk++) {
    map<ll, bool> dish;

    rep(i, 0, K) {
      if (msk & 1 << i) {
        dish[C[i]] = true;
      } else {
        dish[D[i]] = true;
      }
    }
    ll cnt = 0;
    rep(i, 0, M) {
      if (dish[A[i]] && dish[B[i]]) cnt++;
    }
    mx = max(mx, cnt);
  }
  cout << mx << endl;
}
