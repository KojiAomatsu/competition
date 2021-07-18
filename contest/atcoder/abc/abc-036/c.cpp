#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 座標圧縮 実装例

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  map<ll, ll> mp;

  rep(i, 0, N) {
    cin >> A[i];
    mp[A[i]] = 0;
  }

  ll cur = 0;
  for (auto &b : mp) {
    b.second = cur;
    cur++;
  }
  vector<ll> ans(N);
  rep(i, 0, N) { ans[i] = mp[A[i]]; }
  for (auto item : ans) {
    cout << item << endl;
  }
}