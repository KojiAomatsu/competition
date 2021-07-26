#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num, string s) {
  string cp = s;
  sort(cp.begin(), cp.end());
  ll ans = 0;
  rep(i, 0, num) {
    if (s[i] != cp[i]) ans++;
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    string s;
    cin >> le >> s;
    cout << solve(le, s) << endl;
  }
}