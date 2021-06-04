#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> rs;
  vector<ll> gs;
  vector<ll> bs;
  rep(i, 0, 2 * N) {
    ll cute;
    string color;
    cin >> cute >> color;
    if (color == "R") {
      rs.push_back(cute);
    }
    if (color == "G") {
      gs.push_back(cute);
    }
    if (color == "B") {
      bs.push_back(cute);
    }
  }

  ll size_rs = rs.size();
  ll size_gs = gs.size();
  ll size_bs = bs.size();

  // 全て偶数
  if (size_rs % 2 == 0 && size_gs % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  // 2つ奇数
  vector<ll> even_vec;
  vector<ll> odd1_vec;
  vector<ll> odd2_vec;
  if (size_rs % 2 == 0) {
    even_vec = rs;
    odd1_vec = gs;
    odd2_vec = bs;
  }
  if (size_gs % 2 == 0) {
    even_vec = gs;
    odd1_vec = rs;
    odd2_vec = bs;
  }
  if (size_bs % 2 == 0) {
    even_vec = bs;
    odd1_vec = rs;
    odd2_vec = gs;
  }

  vector<pair<ll, ll>> odds_all;
  rep(i, 0, odd1_vec.size()) { odds_all.push_back({odd1_vec[i], 1}); }
  rep(i, 0, odd2_vec.size()) { odds_all.push_back({odd2_vec[i], 2}); }

  sort(odds_all.begin(), odds_all.end(),
       [](const pair<ll, ll> a, const pair<ll, ll> b) {
         return a.first < b.first;
       });

  ll cur_mini = 20000000000000000; // inf
  ll cur_num = odds_all[0].first;
  ll cur_color = odds_all[0].second;
  rep(i, 1, odds_all.size()) {
    auto item = odds_all[i];
    if (item.second != cur_color) {
      cur_mini = min(cur_mini, abs(cur_num - item.first));
      cur_num = item.first;
      cur_color = item.second;
    } else {
      cur_num = item.first;
      cur_color = item.second;
    }
  }

  if (even_vec.size() == 0) {
    cout << cur_mini << endl;
    return 0;
  }

  vector<pair<ll, ll>> oe1_all;
  rep(i, 0, odd1_vec.size()) { oe1_all.push_back({odd1_vec[i], 1}); }
  rep(i, 0, even_vec.size()) { oe1_all.push_back({even_vec[i], 2}); }

  sort(oe1_all.begin(), oe1_all.end(),
       [](const pair<ll, ll> a, const pair<ll, ll> b) {
         return a.first < b.first;
       });

  ll oe1_cur_mini = 20000000000000000; // inf
  ll oe1_cur_num = oe1_all[0].first;
  ll oe1_cur_color = oe1_all[0].second;
  rep(i, 1, oe1_all.size()) {
    auto item = oe1_all[i];
    if (item.second != oe1_cur_color) {
      oe1_cur_mini = min(oe1_cur_mini, abs(oe1_cur_num - item.first));
      oe1_cur_num = item.first;
      oe1_cur_color = item.second;
    } else {
      oe1_cur_num = item.first;
      oe1_cur_color = item.second;
    }
  }

  vector<pair<ll, ll>> oe2_all;
  rep(i, 0, odd2_vec.size()) { oe2_all.push_back({odd2_vec[i], 1}); }
  rep(i, 0, even_vec.size()) { oe2_all.push_back({even_vec[i], 2}); }

  sort(oe2_all.begin(), oe2_all.end(),
       [](const pair<ll, ll> a, const pair<ll, ll> b) {
         return a.first < b.first;
       });

  ll oe2_cur_mini = 20000000000000000; // inf
  ll oe2_cur_num = oe2_all[0].first;
  ll oe2_cur_color = oe2_all[0].second;
  rep(i, 1, oe2_all.size()) {
    auto item = oe2_all[i];
    if (item.second != oe2_cur_color) {
      oe2_cur_mini = min(oe2_cur_mini, abs(oe2_cur_num - item.first));
      oe2_cur_num = item.first;
      oe2_cur_color = item.second;
    } else {
      oe2_cur_num = item.first;
      oe2_cur_color = item.second;
    }
  }

  ll ans;
  ans = min(cur_mini, oe1_cur_mini + oe2_cur_mini);
  cout << ans << endl;
  return 0;
}