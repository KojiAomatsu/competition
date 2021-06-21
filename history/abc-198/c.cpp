#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll R, X, Y;
  cin >> R >> X >> Y;

  if (R * R > X * X + Y * Y) {
    cout << 2 << endl;
    return 0;
  }

  ll ans = ceil(sqrt(X * X + Y * Y) / R);
  cout << ans << endl;
}
