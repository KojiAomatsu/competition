#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> edges(N);
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    edges[ai].push_back(bi);
  }
  atcoder::dsu ds(N);
  vector<ll> ans;
  ans.push_back(0);
  ll cnt = 0;
  for (int i = N - 1; i > 0; i--) {
    if (edges[i].size() == 0) {
      cnt++;
    } else {
      bool once_merged = false;
      for (auto e : edges[i]) {
        if (ds.same(i, e)) {
          continue;
        } else {
          if (once_merged) {
            cnt--;
          }
          ds.merge(i, e);
          once_merged = true;
        }
      }
    }
    ans.push_back(cnt);
  }
  reverse(ans.begin(), ans.end());
  for (auto a : ans) {
    cout << a << endl;
  }
}