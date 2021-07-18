#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 998244353;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  sort(A.begin(), A.end());

  vector<ll> asum(N + 1);
  rep(i, 0, N) { asum[i + 1] = (asum[i] * 2 + A[i]) % mod; }
  ll sm = 0;
  rep(i, 0, N) {
    sm += A[i] * A[i] % mod;
    sm %= mod;
  }

  rep(i, 1, N) {
    sm += asum[i] * A[i] % mod;
    sm %= mod;
  }

  cout << sm << endl;
}