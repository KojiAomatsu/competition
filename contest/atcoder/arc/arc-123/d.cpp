#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll ai, aj, ak;
  cin >> ai >> aj >> ak;
  ll di, dj;
  di = aj - ai;
  dj = ak - aj;
  ll ans = 0;
  while (di != dj) {
    if (di > dj) {
      ans += di - dj;
      break;
    } else {
      ll dif = (dj - di) / 2;
      if ((dj - di) % 2 == 1) {
        dif++;
      }
      di = di + dif;
      dj = dj - dif;
      ans += dif;
    }
  }
  cout << ans << endl;
}