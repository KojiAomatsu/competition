#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[110000];

int main() {
  ll N, X;
  cin >> N >> X;
  vector<ll> Ls(N);
  vector<vector<ll>> As(N);
  rep(i, 0, N) {
    cin >> Ls[i];
    rep(j, 0, Ls[i]) {
      ll ai;
      cin >> ai;
      As[i].push_back(ai);
    }
  }

  map<ll, ll> cnt;
  cnt[X] = 1;
  rep(i, 0, N) {
    map<ll, ll> tmp;
    rep(j, 0, Ls[i]) {
      ll num = As[i][j];
      for (auto c : cnt) {
        if (c.first % num == 0) {
          tmp[c.first / num] += c.second;
        }
      }
    }
    cnt = tmp;
  }

  cout << cnt[1] << endl;
}
