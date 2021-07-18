#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num, vector<ll> li) {
  ll ans = 0;
  ans += num;          // length 1
  ans += num - 1;      // length 2
  rep(i, 0, num - 2) { // length 3
    ll ai = li[i + 1] - li[i];
    ll aj = li[i + 1] - li[i + 2];
    if (ai * aj > 0) ans++;
  }
  rep(i, 0, num - 3) { // length 4
    ll ai = li[i] - li[i + 1];
    ll aj = li[i] - li[i + 2];
    if (ai * aj < 0) {
      ll bi = li[i + 3] - li[i + 1];
      ll bj = li[i + 3] - li[i + 2];
      if (bi * bj < 0) ans++;
    }
  }

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