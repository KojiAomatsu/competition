#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)
ll mod = 998244353;

int get_digit(ll num) {
  int digit = 0;
  while (num != 0) {
    num /= 10;
    digit++;
  }
  return digit;
}

int main() {
  ll N;
  cin >> N;
  ll all_sum;
  if (N % 2 == 0) {
    all_sum = ((N / 2) % mod) * ((N + 1) % mod);
  } else {
    all_sum = (((N + 1) / 2) % mod) * (N % mod);
  }
  all_sum %= mod;

  ll all_mins = 0;
  int dig = get_digit(N);
  rep(i, 1, dig) {
    ll border = pow(10ll, i);
    if (border > N) break;
    ll min_part = ((border - 1) % mod * (min((N - border + 1), 9 * border) % mod));
    min_part %= mod;
    all_mins += min_part;
    all_mins %= mod;
  }
  ll ans = all_sum + (mod - all_mins);
  ans %= mod;
  cout << ans << endl;
}