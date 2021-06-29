#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  vector<ll> B = A;
  rep(i, 0, N - 1) { B[i + 1] += B[i]; }
  vector<ll> C = B;
  rep(i, 0, N - 1) { C[i + 1] += C[i]; }
  ll ans = 0;
  ll mxs = 0;
  ll mxss = 0;
  rep(i, 0, N - 1) {
    mxs = max(mxs, B[i]);
    if (C[i] >= mxss) {
      ans = C[i] + mxs;
      mxss = C[i];
    }
  }
  ans = max(ans, C[N - 1]);
  cout << ans << endl;
}
