#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;

  ll ans = 0;
  if (N > 999) {
    ans += N - 999;
  }
  if (N > 999999) {
    ans += N - 999999;
  }
  if (N > 999999999) {
    ans += N - 999999999;
  }
  if (N > 999999999999) {
    ans += N - 999999999999;
  }
  if (N > 999999999999999) {
    ans += N - 999999999999999;
  }
  cout << ans << endl;
}
