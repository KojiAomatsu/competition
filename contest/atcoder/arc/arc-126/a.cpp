#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll n2, n3, n4;
    cin >> n2 >> n3 >> n4;
    ll ans = 0;
    ll rest4s = n3 / 2;

    if (rest4s < n4) {
      ans += rest4s;
      n4 -= rest4s;
      rest4s = 0;
    } else if (rest4s == n4) {
      ans += rest4s;
      rest4s = 0;
      n4 = 0;
    } else {
      ans += n4;
      rest4s -= n4;
      n4 = 0;

      if (rest4s < n2 / 2) {
        ans += rest4s;
        n2 -= rest4s * 2;
      } else if (rest4s == n2 / 2) {
        ans += rest4s;
        n2 = 0;
        rest4s = 0;
      } else {
        ans += n2 / 2;
        n2 = 0;
      }
    }

    ll rest2s = n4 / 2;
    ll rest6s = n4 % 2;
    if (rest2s < n2) {
      ans += rest2s;
      n2 -= rest2s;
      if (rest6s <= n2 / 3) {
        ans += rest6s;
        n2 -= rest6s * 3;
      }
    } else if (rest2s == n2) {
      ans += rest2s;
      n2 = 0;
    } else {
      ans += n2;
      n2 = 0;
    }
    ans += n2 / 5;

    cout << ans << endl;
  }
}