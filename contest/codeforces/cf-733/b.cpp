#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<vector<ll>> solve(ll h, ll w) {
  vector<vector<ll>> ans;
  if (h % 2 == 1) {
    rep(i, 0, h) {
      vector<ll> tmp;
      if (i == 0 || i == h - 1) {
        rep(j, 0, w) {
          if (j % 2 == 0) {
            tmp.push_back(1);
          } else {
            tmp.push_back(0);
          }
        }
      } else {
        rep(j, 0, w) {
          if (i % 2 == 0 && (j == 0 || j == w - 1)) {
            tmp.push_back(1);
          } else {
            tmp.push_back(0);
          }
        }
      }
      ans.push_back(tmp);
    }
  } else {
    rep(i, 0, h) {
      vector<ll> tmp;
      if (i == 0) {
        rep(j, 0, w) {
          if (j % 2 == 0) {
            tmp.push_back(1);
          } else {
            tmp.push_back(0);
          }
        }
      } else if (i == h - 1) {
        rep(j, 0, w) {
          if (j % 2 == 0 && j != 0) {
            tmp.push_back(1);
          } else {
            tmp.push_back(0);
          }
        }
      } else {
        rep(j, 0, w) {
          if ((i % 2 == 0 && j == 0) || (i % 2 == 0 && j == w - 1 && i < h - 2)) {
            tmp.push_back(1);
          } else {
            tmp.push_back(0);
          }
        }
      }
      ans.push_back(tmp);
    }
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll h, w;
    cin >> h >> w;
    auto v = solve(h, w);
    for (auto vec : v) {
      for (auto item : vec) {
        cout << item << "";
      }
      cout << endl;
    }
    cout << endl;
  }
}