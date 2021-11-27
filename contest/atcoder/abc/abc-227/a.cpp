#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K, A;
  cin >> N >> K >> A;
  ll ans = ((A - 1 + K - 1) % N) + 1;
  cout << ans << endl;
  return 0;
}