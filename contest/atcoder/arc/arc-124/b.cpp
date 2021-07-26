#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  vector<ll> b(N);
  rep(i, 0, N) { cin >> a[i]; }
  rep(i, 0, N) { cin >> b[i]; }
  set<ll> ans;
  rep(i, 0, N) {
    map<ll, ll> cas;
    rep(j, 0, N) {
      if (i == j) continue;
      cas[b[j]]++;
    }
    ll x = a[0] ^ b[i];
    bool ok = true;
    rep(j, 1, N) {
      ll tar = a[j] ^ x;
      if (!(cas[tar])) {
        ok = false;
        break;
      }
      cas[tar]--;
    }
    if (ok) {
      ans.insert(x);
    }
  }
  cout << ans.size() << endl;
  for (auto an : ans) {
    cout << an << endl;
  }
}