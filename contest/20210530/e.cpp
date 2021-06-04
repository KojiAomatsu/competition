#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> pos;
  rep(i, 0, M) {
    ll x, y;
    cin >> x >> y;
    pos.push_back({x, y});
  }

  sort(pos.begin(), pos.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.first < b.first; });

  set<ll> s = {N};
  set<ll> new_s;
  set<ll> del_s;
  ll cur_x = 0;
  rep(i, 0, M) {
    ll x = pos[i].first;
    ll y = pos[i].second;
    if (x != cur_x) {
      cur_x = x;
      for (auto ele : new_s) {
        s.insert(ele);
      }
      for (auto ele : del_s) {
        s.erase(ele);
      }
      new_s.clear();
      del_s.clear();
    }
    if ((s.count(y - 1)) || (s.count(y + 1))) {
      new_s.insert(y);
    } else if (s.count(y)) {
      del_s.insert(y);
    }
  }
  for (auto ele : new_s) {
    s.insert(ele);
  }
  for (auto ele : del_s) {
    s.erase(ele);
  }
  cout << s.size() << endl;
}
