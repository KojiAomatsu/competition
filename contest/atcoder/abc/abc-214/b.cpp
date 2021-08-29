#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll S, T;
  cin >> S >> T;
  ll ans = 0;
  rep(sum, 0, S + 1) {
    rep(i, 0, sum + 1) {
      rep(j, 0, sum + 1) {
        ll k = sum - i - j;
        if (k < 0) continue;
        if (i * j * k <= T) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}