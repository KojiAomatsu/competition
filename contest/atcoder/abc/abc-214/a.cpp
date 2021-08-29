#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A;
  cin >> A;

  ll ans = 0;
  if (A <= 125) {
    ans = 4;
  } else if (A <= 211) {
    ans = 6;
  } else {
    ans = 8;
  }
  cout << ans << endl;
}