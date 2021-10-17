#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll t;
  cin >> t;
  rep(i, 0, t) {
    ll r, g, b;
    cin >> r >> g >> b;

    if (r % 3 != g % 3 && r % 3 != b % 3 && g % 3 != b % 3) {
      cout << -1 << endl;
      continue;
    }

    vector<ll> bals = {r, g, b};
    sort(bals.begin(), bals.end());
    ll fir = bals[0];
    ll sec = bals[1];
    ll thi = bals[2];
    ll tar1, tar2;
    if (fir % 3 != sec % 3 && fir % 3 != thi % 3) {
      tar1 = sec;
      tar2 = thi;
    } else {
      tar1 = fir;
      if (fir % 3 == sec % 3) {
        tar2 = sec;
      } else {
        tar2 = thi;
      }
    }
    ll dif = (tar2 - tar1) / 3;
    ll ans = (tar2 - dif) + dif;
    cout << ans << endl;
  }
}