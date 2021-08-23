#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 998244353;

int main() {
  ll N;
  cin >> N;

  ll rt = sqrt(N);

  ll ans = 0;
  rep(i, 1, rt + 1) {
    ll dif = 2 * i;
    ll al = (N - i * i) / dif + 1;
    ans += al % mod;
    ans %= mod;
  }
  cout << ans << endl;
}
