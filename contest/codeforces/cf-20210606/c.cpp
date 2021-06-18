#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num, vector<ll> li) {
  ll ans = 0;

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
    cout << calc(le, li) << endl;
  }
}