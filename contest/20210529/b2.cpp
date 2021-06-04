#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dis(vector<ll> r, vector<ll> g) {
  ll mi = 1000100100100100100;
  ll gn = g.size();
  ll rn = r.size();
  if (gn == 0 || rn == 0)
    return mi;
  for (auto a : r) {
    ll i = lower_bound(g.begin(), g.end(), a) - g.begin();
    if (gn > i) {
      mi = min(mi, abs(a - g[i]));
    }
    if (i > 0)
      mi = min(mi, abs(a - g[i - 1]));
  }
  return mi;
};

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

  sort(even_vec.begin(), even_vec.end());
  sort(odd1_vec.begin(), odd1_vec.end());
  sort(odd2_vec.begin(), odd2_vec.end());

  ll cur_mini;
  cur_mini = dis(odd1_vec, odd2_vec);

  if (even_vec.size() == 0) {
    cout << cur_mini << endl;
    return 0;
  }
  ll oe1_cur_mini;
  oe1_cur_mini = dis(odd1_vec, even_vec);

  ll oe2_cur_mini;
  oe2_cur_mini = dis(odd2_vec, even_vec);

  ll ans;
  ans = min(cur_mini, oe1_cur_mini + oe2_cur_mini);
  cout << ans << endl;
  return 0;
}