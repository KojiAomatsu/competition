#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  ll pt_select_a = b / (a - 1);
  ll ans = 0;
  while (x <= pt_select_a) {
    if (x * a >= y) break;
    x *= a;
    ans++;
  }
  if (x < y) {
    ans += (y - 1 - x) / b;
  }
  cout << ans << endl;
}