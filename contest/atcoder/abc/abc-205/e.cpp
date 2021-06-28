#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int modPow(long long a, long long n, long long p) {
  if (n == 0)
    return 1; // 0乗にも対応する場合
  if (n == 1)
    return a % p;
  if (n % 2 == 1)
    return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

int main() {
  ll N, M, K;
  cin >> N >> M >> K;
  vector<ll> dp(1000001, 0);
  rep(i, 1, N) {}
}
