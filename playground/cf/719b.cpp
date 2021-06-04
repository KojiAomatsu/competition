#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll SameDigits(int digits, int num) {
  ll ans = 0;
  for (ll i = 0; i < digits; i++) {
    ans += num * pow(10, i);
  }
  return ans;
}

ll calc(ll num) {
  ll ans = 0;
  rep(i, 1, 10) { ans += min(num / SameDigits(i, 1), 9LL); }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll tmp;
    cin >> tmp;
    cout << calc(tmp) << endl;
  }
}
