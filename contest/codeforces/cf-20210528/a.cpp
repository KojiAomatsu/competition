#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<ll> calc(ll num, vector<ll> li) {
  vector<ll> tmp;
  sort(li.begin(), li.end());
  tmp = li;
  tmp.push_back(li[0]);

  ll diff = 0; // 差を貯める
  ll prev;
  vector<ll> ans; // 答えを置いていく
  ans.push_back(tmp[0]);
  prev = tmp[0];
  tmp.erase(tmp.begin());
  rep(i, 1, num + 1) {
    ll val = tmp[0];
    if (val - prev == diff) {
      if (i == num) {
        ans[0] = ans[ans.size() - 1];
        ans[ans.size() - 1] = val;
        break;
      }
      ans.push_back(tmp[1]);
      prev = tmp[1];
      diff = tmp[1] - prev;
      tmp.erase(tmp.begin() + 1);
    } else {
      if (i == num)
        break;
      ans.push_back(val);
      diff = val - prev;
      prev = val;
      tmp.erase(tmp.begin());
    }
  }
  if (ans[0] == ans[ans.size() - 1]) {
    ans[0] = tmp[0];
  }

  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(p, 0, N) {
    ll tmp1;
    cin >> tmp1;
    vector<ll> li(tmp1 * 2);
    for (auto &ele : li)
      cin >> ele;
    rep(k, 0, tmp1 * 2) { cout << calc(tmp1 * 2, li)[k] << " "; }
    cout << endl;
  }
}