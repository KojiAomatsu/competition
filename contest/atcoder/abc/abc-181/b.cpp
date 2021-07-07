#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  ll ans = 0;
  rep(i, 0, N) {
    cin >> A[i] >> B[i];
    ans += (B[i] + A[i]) * (B[i] - A[i] + 1LL) / 2LL;
  }
  cout << ans << endl;
}