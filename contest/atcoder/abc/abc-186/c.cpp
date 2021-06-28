#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  rep(num, 1, N + 1) {
    ll cp1 = num;
    ll cp2 = num;
    ll fl = false;
    while (cp1 != 0) {
      ll rem = cp1 % 10;
      if (rem == 7) {
        fl = true;
        break;
      }
      cp1 /= 10;
    }
    while (cp2 != 0) {
      ll rem = cp2 % 8;
      if (rem == 7) {
        fl = true;
        break;
      }
      cp2 /= 8;
    }
    if (!fl) {
      ans++;
    }
  }
  cout << ans << endl;
}