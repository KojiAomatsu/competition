#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, A, B, P, Q, R, S;
  cin >> N >> A >> B >> P >> Q >> R >> S;
  vector<vector<char>> ans(Q - P + 1, vector<char>(S - R + 1, '.'));
  rep(i, P, Q + 1) {
    rep(j, R, S + 1) {
      if (abs(i - A) == abs(j - B)) {
        ans[i - P][j - R] = '#';
      }
    }
  }
  for (auto vec : ans) {
    for (auto item : vec) {
      cout << item;
    }
    cout << endl;
  }
}