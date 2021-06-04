#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<vector<ll>> res(ll num) {
  ll num_of_iteration = num / 2;
  vector<vector<ll>> res;
  rep(i, 0, num_of_iteration) {
    ll first_ele = i * 2 + 1;
    ll second_ele = i * 2 + 2;
    res.push_back({1, first_ele, second_ele});
    res.push_back({2, first_ele, second_ele});
    res.push_back({1, first_ele, second_ele});
    res.push_back({1, first_ele, second_ele});
    res.push_back({2, first_ele, second_ele});
    res.push_back({1, first_ele, second_ele});
  }
  return res;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll tmp1;
    cin >> tmp1;
    vector<ll> li(tmp1); // throw away.
    rep(j, 0, tmp1) { cin >> li[i]; }

    auto ans = res(tmp1);
    cout << ans.size() << endl;
    for (auto vec : ans) {
      cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
    }
  }
}