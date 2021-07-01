#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B;
  cin >> A, B;
  ll dif = B - A;
  vector<ll> isPrime(72, true);
  rep(i, 2, 10) {
    for (ll j = 2; i * j < 72; j++) {
      isPrime[i * j] = false;
    }
  }
  vector<ll> primes;
  rep(i, 2, 72) {
    if (isPrime[i]) primes.push_back(i);
  }

  ll npri = primes.size();
  vector<vector<bool>> divs(dif + 1, vector<bool>(npri));
  rep(i, 0, dif + 1) {
    ll num = A + i;
    rep(j, 0, npri) { divs[i][j] = num % primes[j] == 0; }
  }

  vector<vector<ll>> dp(dif + 1 + 1, vector<ll>(npri, 0));
  vector<ll> g(dif + 1 + 1);
  rep(i, 0, dif + 1) {
    rep(j, 0, npri) {
      if (divs[i][j]) {
        if (dp[i][j] == 0) {
          dp[i + 1][j] = 1;
          continue;
        }
      }
    }
  }
}
