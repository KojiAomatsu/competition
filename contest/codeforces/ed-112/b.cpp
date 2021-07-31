#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num, vector<ll> li) {
  ll ans = 0;

  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll w, h, x1, y1, x2, y2, a, b;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> a >> b;
    ll dx = x2 - x1;
    ll dy = y2 - y1;

    ll ans = 1E12;

    if (dx + a <= w) {
      ll cnt = 0;
      if (0 <= x1 && x1 <= a && 0 <= y1 && y1 <= b) {
        ans = min(ans, a - x1);
        cnt++;
      }
      if (0 <= x1 && x1 <= a && h - b <= y2 && y2 <= h) {
        ans = min(ans, a - x1);
        cnt++;
      }
      if (w - a <= x2 && x2 <= w && 0 <= y1 && y1 <= b) {
        ans = min(ans, x2 - (w - a));
        cnt++;
      }
      if (w - a <= x2 && x2 <= w && h - b <= y2 && y2 <= h) {
        ans = min(ans, x2 - (w - a));
        cnt++;
      }
      if (cnt != 4) {
        ans = 0;
      }
    }
    if (dy + b <= h) {
      ll cnt = 0;
      if (0 <= x1 && x1 <= a && 0 <= y1 && y1 <= b) {
        ans = min(ans, b - y1);
        cnt++;
      }
      if (0 <= x1 && x1 <= a && h - b <= y2 && y2 <= h) {
        ans = min(ans, y2 - (h - b));
        cnt++;
      }
      if (w - a <= x2 && x2 <= w && 0 <= y1 && y1 <= b) {
        ans = min(ans, b - y1);
        cnt++;
      }
      if (w - a <= x2 && x2 <= w && h - b <= y2 && y2 <= h) {
        ans = min(ans, y2 - (h - b));
        cnt++;
      }
      if (cnt != 4) {
        ans = 0;
      }
    }

    if (ans == 1E12) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}