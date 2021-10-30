#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  rep(i, 0, H) {
    rep(j, 0, W) { cin >> A[i][j]; }
  }

  rep(i, 0, H - 1) rep(j, 0, W - 1) {
    rep(di, 1, H) rep(dj, 1, W) {
      ll ni = i + di;
      ll nj = j + dj;
      if (ni >= H || nj >= W) {
        break;
      }
      if (A[i][j] + A[ni][nj] <= A[i][nj] + A[ni][j]) {
        continue;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}