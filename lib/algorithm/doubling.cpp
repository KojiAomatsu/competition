#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// doubling ダブリングの実装例
ll N, K;
ll A[220000];
int main() {
  cin >> N >> K;
  rep(i, 0, N) { cin >> A[i]; }

  int logK = 1;
  while ((1LL << logK) <= K)
    logK++;
  vector<vector<ll>> doubling(logK + 2, vector<ll>(N + 2));
  rep(i, 1, N + 1) { doubling[0][i] = A[i - 1]; }
  rep(k, 0, logK) {
    rep(i, 1, N + 1) { doubling[k + 1][i] = doubling[k][doubling[k][i]]; }
  }

  ll now = 1;
  ll pt = 0;
  while (K > 0) {
    if (K & 1) {
      now = doubling[pt][now];
    }
    K = K >> 1;
    pt++;
  }
  cout << now << endl;
}
