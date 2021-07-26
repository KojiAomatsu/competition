#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 998244353;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<P> lefts;
  vector<P> rights;
  set<ll> vali;
  rep(i, 0, K) {
    char ci;
    ll ki;
    cin >> ci >> ki;
    if (ci == 'L') {
      lefts.push_back({i + 1, ki});
      vali.insert(ki);
    } else {
      rights.push_back({i + 1, ki});
      vali.insert(ki);
    }
  }
  if (vali.size() != K) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  rep(i, 1, N + 1) {
    if (vali.find(i) != vali.end()) {
      continue;
    }

    ll cnt = 0;
    for (auto lef : lefts) {
      if (lef.second < i) {
        cnt++;
      }
    }
    for (auto rig : rights) {
      if (rig.second > i) {
        cnt++;
      }
    }
    ans *= cnt;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}