#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

char hw[11][11];

int main() {
  ll H, W;
  cin >> H >> W;
  rep(i, 0, H) {
    string s;
    cin >> s;
    rep(j, 0, W) { hw[i][j] = s[j]; }
  }

  ll cnt = 0;
  ll cur_black = 0;
  rep(i, 0, H - 1) rep(j, 0, W - 1) {
    if (hw[i][j] == '#') cur_black++;
    if (hw[i + 1][j] == '#') cur_black++;
    if (hw[i][j + 1] == '#') cur_black++;
    if (hw[i + 1][j + 1] == '#') cur_black++;
    if (cur_black % 2 == 1) {
      cnt++;
    }
    cur_black = 0;
  }
  cout << cnt << endl;
}
