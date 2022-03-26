#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) { cin >> B[i]; }
  ll ap = A[0];
  ll bp = B[0];
  rep(i, 0, N) {
    ll app = ap;
    ll bpp = bp;
    if (abs(A[i] - app) <= K || abs(A[i] - bpp) <= K) {
      ap = A[i];
    } else {
      ap = -1E9 - 10;
    }
    if (abs(B[i] - app) <= K || abs(B[i] - bpp) <= K) {
      bp = B[i];
    } else {
      bp = -1E9 - 10;
    }
  }
  bool ans = ap > 0 || bp > 0;
  cout << (ans ? "Yes" : "No") << endl;
}