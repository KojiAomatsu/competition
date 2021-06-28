#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M, T;
  cin >> N >> M >> T;
  ll mx = N;
  vector<ll> A(M);
  vector<ll> B(M);
  ll pt = 0;
  rep(i, 0, M) {
    cin >> A[i] >> B[i];
    N -= A[i] - pt;
    pt = A[i];
    if (N <= 0) {
      cout << "No" << endl;
      return 0;
    } else {
      N = min(mx, N + B[i] - pt);
      pt = B[i];
    }
  }
  N -= T - pt;
  if (N <= 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}