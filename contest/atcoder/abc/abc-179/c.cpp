#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  rep(A, 1, N) {
    ll B = (N - 1) / A;
    ans += B;
  }
  cout << ans << endl;
}