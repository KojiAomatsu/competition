#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, X;
  cin >> N >> X;
  vector<ll> V(N);
  vector<ll> P(N);
  rep(i, 0, N) { cin >> V[i] >> P[i]; }
  ll cur = 0;
  rep(i, 0, N) {
    cur += V[i] * P[i];
    if (cur > X * 100) {
      cout << (i + 1) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
