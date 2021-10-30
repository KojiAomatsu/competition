#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> B(N, vector<ll>(M));
  rep(i, 0, N) {
    rep(j, 0, M) { cin >> B[i][j]; }
  }

  bool fl = true;
  ll lt = B[0][0];
  ll rt = B[0][M - 1];
  ll ltm = (lt - 1) % 7 + 1;
  ll rtm = (rt - 1) % 7 + 1;
  if (ltm > rtm) {
    cout << "No" << endl;
    return 0;
  } else if (ltm == rtm && lt != rt) {
    cout << "No" << endl;
    return 0;
  }

  rep(i, 0, N) {
    rep(j, 0, M) {
      if (fl == false) {
        break;
      }
      ll colled = i * 7 + j;
      if (B[i][j] == lt + colled) {
        continue;
      } else {
        fl = false;
        break;
      }
    }
  }

  cout << (fl ? "Yes" : "No") << endl;
}