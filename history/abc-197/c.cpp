#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  ll mi = 1E12;
  ll cur_or = 0;
  ll cur_xor = 0;
  for (ll i = 0; i < 1 << (N - 1); i++) {
    cur_xor = 0;
    cur_or = A[0];
    rep(j, 0, N - 1) {
      bool flag = (i & 1 << (N - 2 - j));
      if (flag) {
        cur_xor ^= cur_or;
        cur_or = 0;
      }
      cur_or |= A[j + 1];
    }
    cur_xor ^= cur_or;

    mi = min(mi, cur_xor);
  }

  cout << mi << endl;
}
