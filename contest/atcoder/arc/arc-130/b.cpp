#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll H, W, C, Q;
  cin >> H >> W >> C >> Q;
  vector<tuple<ll, ll, ll>> tncs;
  rep(i, 0, Q) {
    ll ti, ni, ci;
    cin >> ti >> ni >> ci;
    tncs.push_back({ti, ni, ci});
  }
  reverse(tncs.begin(), tncs.end());

  ll numsr = 0;
  vector<bool> doner(H + 1, false);
  ll numsc = 0;
  vector<bool> donec(W + 1, false);

  vector<ll> ans(C + 1);
  rep(i, 0, Q) {
    auto [ti, ni, ci] = tncs[i];
    if (ti == 1) {
      if (doner[ni]) {
        continue;
      }
      doner[ni] = true;
      ans[ci] += W - numsc;
      numsr++;
    } else {
      if (donec[ni]) {
        continue;
      }
      donec[ni] = true;
      ans[ci] += H - numsr;
      numsc++;
    }
  }
  rep(i, 1, C + 1) { cout << ans[i] << " "; }
}