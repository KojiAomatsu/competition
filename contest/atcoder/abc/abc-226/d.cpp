#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll gcd(ll x, ll y) {
  x = abs(x);
  y = abs(y);
  if (x == 0) return y;
  return gcd(y % x, x);
}

int main() {
  ll N;
  cin >> N;
  vector<P> cords(N);
  rep(i, 0, N) {
    ll xi, yi;
    cin >> xi >> yi;
    cords[i] = {xi, yi};
  }
  set<P> magics;
  rep(i, 0, N) {
    rep(j, 0, N) {
      if (i == j) continue;
      ll xk = cords[i].first - cords[j].first;
      ll yk = cords[i].second - cords[j].second;
      ll gk = gcd(xk, yk);
      P p = {xk / gk, yk / gk};
      magics.insert(p);
    }
  }
  cout << magics.size() << endl;
}