#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == c) {
    cout << 0 << endl;
    return 0;
  }
  double k = double(d + b) / (c - a);
  double y = d - c * k;
  printf("%.8f", -y / k);
}
