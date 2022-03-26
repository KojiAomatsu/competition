#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

bool solve(ll a, ll s) {
  ll rest = s - 2 * a;

  if (rest < 0) return false;
  for (int i = 0; i < 60; i++) {
    if (rest & (1ll << i)) {
      if (a & (1ll << i)) return false;
    }
  }
  return true;
}

int main() {
  ll T;
  cin >> T;
  rep(i, 0, T) {
    ll a, s;
    cin >> a >> s;
    cout << (solve(a, s) ? "Yes" : "No") << endl;
  }
}