#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, A, X, Y;
  cin >> N >> A >> X >> Y;
  ll ans = min(A, N) * X;
  ans += max(N - A, 0ll) * Y;
  cout << ans << endl;
}