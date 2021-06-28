#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> sums(N);
  ll cur = 0;
  rep(i, 0, N) {
    cin >> A[i];
    cur += A[i];
    sums[i] = cur;
  }
  ll ans = 0;
  rep(i, 0, N) { ans += (N - 1) * A[i] * A[i]; }
  rep(i, 0, N - 1) { ans -= 2 * sums[i] * A[i + 1]; }

  cout << ans << endl;
}
