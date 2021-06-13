#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 1000000007;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  if (N == 1) {
    cout << A[0] << endl;
    return 0;
  }

  // 組み合わせの数 下i桁以降
  vector<ll> pat(N);
  // 総和 下i桁以降
  vector<ll> sum(N);
  pat[0] = 1;
  sum[0] = A[N - 1];
  pat[1] = 2;
  sum[1] = (2 * A[N - 2]) % mod;

  rep(i, 2, N) {
    ll num = A[N - 1 - i];
    ll num_next = A[N - i];
    ll one = ((num * pat[i - 1]) % mod + sum[i - 1]) % mod;
    ll two = (((num - num_next) * pat[i - 2]) % mod + sum[i - 2]) % mod;
    sum[i] = (one + two) % mod;
    pat[i] = (pat[i - 1] + pat[i - 2]) % mod;
  }
  cout << (sum.back() + mod) % mod << endl;
}