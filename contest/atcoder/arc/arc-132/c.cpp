#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 998244353;
ll dp[550][550][20]; // iまで決めた時に、j番目の候補がk個削れている時の場合の数（i < j）

int main() {
  ll n, d;
  cin >> n >> d;
  vector<ll> a(n);
  rep(i, 0, n) { cin >> a[i]; }
  vector<ll> cands;
  vector<ll> mis;
  rep(i, 0, n) {
    if (a[i] == -1) {
      mis.push_back(i);
      continue;
    }
    cands.push_back(a[i] - 1);
    if (abs(a[i] - (i + 1)) > d) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (cands.size() == 0) {
    cout << 1 << endl;
    return 0;
  }
  sort(cands.begin(), cands.end());
  rep(t, 0, mis.size()) {
    ll idx = mis[t];
    auto u = upper_bound(cands.begin(), cands.end(), idx + d);
    auto l = lower_bound(cands.begin(), cands.end(), idx - d);
    ll num = (ll)(u - cands.begin()) - (ll)(l - cands.begin());
  }
}