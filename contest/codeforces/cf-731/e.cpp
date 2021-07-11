#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll n, ll k, map<ll, ll> ac) {
  vector<ll> ans(n, 1E18);
  ll cur_tmp = 1E18;
  rep(i, 0, n) {
    cur_tmp++;
    if (ac.count(i)) {
      cur_tmp = min(cur_tmp, ac[i]);
    }
    ans[i] = min(ans[i], cur_tmp);
  }
  cur_tmp = 1E18;
  rep(i, 0, n) {
    ll idx = n - 1 - i;
    cur_tmp++;
    if (ac.count(idx)) {
      cur_tmp = min(cur_tmp, ac[idx]);
    }
    ans[idx] = min(ans[idx], cur_tmp);
  }
  for (auto item : ans) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll n, k;
    cin >> n >> k;
    map<ll, ll> ac;
    vector<ll> a(k);
    rep(j, 0, k) { cin >> a[j]; }
    vector<ll> t(k);
    rep(j, 0, k) { cin >> t[j]; }
    rep(j, 0, k) { ac[a[j] - 1] = t[j]; }
    solve(n, k, ac);
  }
}