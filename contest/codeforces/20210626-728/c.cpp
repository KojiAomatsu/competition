#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num, vector<ll> li) {
  ll ans = 0;
  sort(li.begin(), li.end());
  vector<ll> sums(num);
  ll cur = 0;
  rep(i, 0, num) {
    cur += li[i];
    sums[i] = cur;
  }
  rep(i, 1, num) { ans -= sums[i] * (num - i + 1); }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<ll> li(le);
    rep(j, 0, le) { cin >> li[j]; }
    cout << solve(le, li) << endl;
  }
}