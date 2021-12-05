#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, D;
  cin >> N >> D;
  vector<P> LR(N);
  rep(i, 0, N) {
    ll Li, Ri;
    cin >> Li >> Ri;
    LR[i] = {Li, Ri};
  }
  sort(LR.begin(), LR.end(), [](P l, P r) {
    if (l.second != r.second) {
      return l.second < r.second;
    } else {
      return l.first < r.first;
    }
  });

  ll lastpow = 0;
  ll powcount = 0;
  rep(i, 0, LR.size()) {
    auto [l, r] = LR[i];
    if (lastpow >= l) {
      continue;
    } else {
      ll powend = r + D - 1;
      lastpow = powend;
      powcount++;
    }
  }
  cout << powcount << endl;
}
