#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == c && b == d) {
    cout << 0 << endl;
    return 0;
  }
  if (a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3) {
    cout << 1 << endl;
    return 0;
  }
  if ((a + b) % 2 == (c + d) % 2) {
    cout << 2 << endl;
    return 0;
  }
  ll dif = c - a;
  ll dr = b + dif;
  ll dl = b - dif;
  if (abs(dl - d) <= 3 || abs(dr - d) <= 3) {
    cout << 2 << endl;
    return 0;
  }
  if ((abs(c - a) <= 6 && (d - b == 0)) || ((abs(d - b) <= 6) && (c - a == 0))) {
    cout << 2 << endl;
    return 0;
  }
  cout << 3 << endl;
  return 0;
}
