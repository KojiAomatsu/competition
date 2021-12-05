#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  map<ll, ll> divs;
  rep(i, 1, sqrt(N) + 1) { divs[i] = N / i; }
  ll ans = 0;
  ll cur = 1;
  rep(i, 0, N) {
    ll tmp = N / cur;
    ll limit = divs[tmp];
    if (limit == 0) {
      ans += tmp;
      cur++;
      continue;
    }
    ans += (limit - cur + 1) * tmp;
    cur = limit + 1;
    if (cur > N) break;
  }
  cout << ans << endl;
}