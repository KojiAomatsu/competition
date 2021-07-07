#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num) {
  vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
  vector<P> tos = {{4, 2}, {8, 2}, {9, 3}, {16, 2}, {25, 5}, {27, 3}, {32, 2}, {49, 7}, {64, 2}, {81, 3}};
  ll rem = num;
  ll ans = 0;
  ll cur = 1;
  ll cur_tos = 0;
  rep(i, 0, primes.size()) {
    if (primes[i] > tos[cur_tos].first) {
      cur *= tos[cur_tos].second;
      ans += ((rem - num / cur) * tos[cur_tos].first % (ll)(1E9 + 7));
      ans %= (ll)(1E9 + 7);

      cur_tos++;
      rem = num / cur;
      if (rem == 0) {
        break;
      }
    }
    cur *= primes[i];
    ans += ((rem - num / cur) * primes[i] % (ll)(1E9 + 7));
    ans %= (ll)(1E9 + 7);
    rem = num / cur;
    if (rem == 0) {
      break;
    }
  }

  return ans;
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