#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num, vector<ll> li) {
  ll ans = 0;
  rep(i, 0, num) {
    ll ai = li[i];
    ll div = (i + 1) / ai;
    ll rem = (i + 1) % ai;
    ll st = div * ai + (ai - rem) % ai;
    if (i + 1 >= st) {
      st += ai;
    }
    for (ll j = st; j < num + 1; j += ai) { // j は 1 index
      ll aj = li[j - 1];
      if (ai * aj == i + 1 + j) {
        ans++;
      }
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
