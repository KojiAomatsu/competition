#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  double A;
  cin >> A;
  double diff = A - int(A);
  int ans = 0;
  if (diff >= 0.500) {
    ans = int(A) + 1;
  } else {
    ans = int(A);
  }
  cout << ans << endl;
  return 0;
}