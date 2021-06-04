#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    cout << c << endl;
    return 0;
  }
  if (b == c) {
    cout << a << endl;
    return 0;
  }
  if (c == a) {
    cout << b << endl;
    return 0;
  }
  cout << 0 << endl;
}