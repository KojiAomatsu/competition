#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll L, Q;
  cin >> L >> Q;

  map<ll, ll> startlen;
  startlen[0] = L;

  rep(i, 0, Q) {
    int ci, xi;
    cin >> ci >> xi;
    if (ci == 1) {
      auto it = startlen.upper_bound(xi);
      it--;
      ll ke = (*it).first;
      ll le = (*it).second;
      startlen[ke] = xi - ke;
      startlen[xi] = le - xi + ke;
    } else {
      auto it = startlen.upper_bound(xi);
      it--;
      cout << (*it).second << endl;
    }
  }
}