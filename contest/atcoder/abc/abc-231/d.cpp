#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  atcoder::dsu d(N);
  bool ans = true;
  map<int, int> mp;
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    mp[ai]++;
    mp[bi]++;
    if (mp[ai] > 2 || mp[bi] > 2) {
      ans = false;
    }
    if (d.same(ai, bi)) {
      ans = false;
    } else {
      d.merge(ai, bi);
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
}