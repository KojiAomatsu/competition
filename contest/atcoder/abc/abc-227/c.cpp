#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll cnt = 0;
  rep(i, 1, N) {
    if (i * i * i > N) break;
    rep(j, i, N) {
      ll mn = j;
      if (i * j * mn > N) break;
      ll mx = N / (i * j);
      cnt += (mx - mn + 1);
    }
  }
  cout << cnt << endl;
  return 0;
}