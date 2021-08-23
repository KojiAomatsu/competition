
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  ll cur = 1;
  while (true) {
    cur *= 2;
    if (cur > N) break;
    ans += 1;
  }
  cout << ans << endl;
}
