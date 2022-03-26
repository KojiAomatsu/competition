#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, L, W;
  cin >> N >> L >> W;
  vector<ll> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  a.push_back(L);
  ll cur = 0;
  ll ans = 0;
  for (auto ai : a) {
    if (cur >= ai) {
      cur = ai + W;
      continue;
    }
    ll tmp = (ai - cur) / W;
    if ((ai - cur) % W != 0) {
      tmp++;
    }
    ans += tmp;
    cur = ai + W;
  }
  cout << ans << endl;
}