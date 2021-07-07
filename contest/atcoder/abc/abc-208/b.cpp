#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll factorial(ll a) {
  if (a <= 1) {
    return 1;
  } else {
    return a * factorial(a - 1);
  }
}

int main() {
  ll P;
  cin >> P;
  vector<ll> coins(10);
  rep(i, 1, 11) { coins[i - 1] = factorial(i); }
  reverse(coins.begin(), coins.end());

  ll ans = 0;
  ll cur = 0;
  while (P > 0) {
    ll di = P / coins[cur];
    ll rem = P % coins[cur];
    if (di >= 100) {
      P = P - coins[cur] * 100;
      cur++;
      ans += 100;
      continue;
    }
    P = rem;
    cur++;
    ans += di;
  }
  cout << ans << endl;
}