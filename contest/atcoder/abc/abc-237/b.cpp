#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i, 0, H) {
    rep(j, 0, W) { cin >> A[i][j]; }
  }
  rep(j, 0, W) {
    rep(i, 0, H) { cout << A[i][j] << ' '; }
    cout << endl;
  }
}