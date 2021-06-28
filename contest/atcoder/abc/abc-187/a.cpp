#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll a, b;
  cin >> a >> b;
  ll suma = 0;
  ll sumb = 0;
  rep(i, 0, 3) {
    suma += a % 10;
    sumb += b % 10;
    a /= 10;
    b /= 10;
  }
  cout << max(suma, sumb) << endl;
}
