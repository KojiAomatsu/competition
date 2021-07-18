#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num) {
  ll rt = sqrt(num);
  if (num - rt * rt > 0) rt++;
  return rt;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    cout << solve(le) << endl;
  }
}