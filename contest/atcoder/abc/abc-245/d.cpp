#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N + 1);
  rep(i, 0, N + 1) { cin >> A[i]; }
  reverse(A.begin(), A.end());
  vector<ll> C(N + M + 1);
  rep(i, 0, N + M + 1) { cin >> C[i]; }
  reverse(C.begin(), C.end());
  vector<ll> B(M + 1);
  rep(i, 0, M + 1) {
    ll bi = C[i] / A[0];
    rep(j, 0, N + 1) { C[i + j] -= bi * A[j]; }
    B[i] = bi;
  }
  reverse(B.begin(), B.end());
  for (auto item : B) {
    cout << item << " ";
  }
  cout << endl;
}