#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

char hw[110][110];

int main() {
  ll H, W, X, Y;
  cin >> H >> W >> X >> Y;
  rep(i, 1, H + 1) {
    string s;
    cin >> s;
    rep(j, 1, W + 1) { hw[i][j] = s[j - 1]; }
  }

  ll cnt = 0;
  rep(dis, 0, W) {
    if (Y - dis >= 1) {
      if (hw[X][Y - dis] == '.') {
        cnt++;
      } else {
        break;
      }
    }
  }
  rep(dis, 0, W) {
    if (Y + dis <= W) {
      if (hw[X][Y + dis] == '.') {
        cnt++;
      } else {
        break;
      }
    }
  }
  rep(dis, 0, H) {
    if (X - dis >= 1) {
      if (hw[X - dis][Y] == '.') {
        cnt++;
      } else {
        break;
      }
    }
  }
  rep(dis, 0, H) {
    if (dis + X <= H) {
      if (hw[X + dis][Y] == '.') {
        cnt++;
      } else {
        break;
      }
    }
  }
  cout << cnt - 3 << endl;
}
