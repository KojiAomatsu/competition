#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll X) {
  if (X < 4) return 1;

  int cnt = 0;
  ll tmp = X;
  while (tmp > 1) {
    tmp = sqrt(tmp);
    cnt++;
  }

  // cnt > 2 が保証される
}

int main() {
  ll T;
  cin >> T;
  rep(i, 0, T) {
    ll X;
    cin >> X;
    ll ans = solve(X);
    cout << ans << endl;
  }
}