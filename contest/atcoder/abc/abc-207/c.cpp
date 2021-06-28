#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> t(N);
  vector<double> l(N);
  vector<double> r(N);
  rep(i, 0, N) {
    cin >> t[i];
    double li, ri;
    cin >> li;
    if ((t[i] - 1) / 2 == 0) {
      l[i] = li;
    } else {
      l[i] = li + 0.01;
    }
    cin >> ri;
    if (t[i] % 2 == 1) {
      r[i] = ri;
    } else {
      r[i] = ri - 0.01;
    }
  }
  ll ans = 0;
  rep(i, 0, N) {
    rep(j, i + 1, N) {
      if (l[i] <= l[j] && r[i] >= l[j]) {
        ans++;
        continue;
      }
      if (l[i] <= r[j] && r[i] >= r[j]) {
        ans++;
        continue;
      }
      if (l[i] >= l[j] && l[i] <= r[j]) {
        ans++;
        continue;
      }
      if (r[i] >= l[j] && r[i] <= r[j]) {
        ans++;
        continue;
      }
    }
  }
  cout << ans << endl;
}