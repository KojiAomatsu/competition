#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> li(N, 0);
  vector<ll> comp(N, 0);
  rep(i, 0, N) {
    ll num;
    cin >> num;
    li[i] = num + i;
  }
  rep(i, 0, N) {
    ll num;
    cin >> num;
    comp[i] = num + i;
  }

  ll swaps = 0;
  for (ll i = 0; i < N; i++) {
    ll ans = comp[0];
    auto pos = find(li.begin(), li.end(), ans);
    if (pos == li.end()) {
      cout << -1 << endl;
      return 0;
    }
    auto idx = pos - li.begin();
    swaps += idx;
    li.erase(pos);
    comp.erase(comp.begin());
  }
  cout << swaps << endl;
}
