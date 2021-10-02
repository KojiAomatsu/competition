#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll dig = to_string(N).size();
  ll ans = 0;
  rep(i, 1, dig) {
    rep(j, 1, i + 1) {
      if (j == i) {
        ans += j;
      } else {
        ans += j * 9 * pow(10, max(i - j - 1, 0ll));
      }
    }
  }

  ll mx = 1 * pow(10, dig);
  rep(j, 1, dig + 1) {
    mx -= 8 * pow(10, dig - j);
    if (dig == j) {
      ll al = 0;
      rep(t, 0, dig) { al += pow(10, t); }
      if (N >= al) {
        ans += j;
      }
      break;
    }
    if (mx <= N) {
      if (j != dig) {
        ans += j * 9 * pow(10, max(dig - j - 1, 0ll));
      }
    } else {
      ll upper = mx - 8 * pow(10, dig - j - 1);
      ll lower = mx - 9 * pow(10, dig - j - 1);
      if (N >= upper) {
        ans += j * (N - upper + 1);
        ans += j * pow(10, dig - j - 1);
      } else if (N < lower) {
        ll al = 0;
        rep(t, 1, dig + 1) {
          if (t <= j) al += pow(10, dig - t);
        }
        if (N >= al) {
          ans += j * (N - al + 1);
        }
      } else if (N >= lower) {
        ans += j * pow(10, dig - j - 1);
      }
    }
  }
  cout << ans << endl;
}