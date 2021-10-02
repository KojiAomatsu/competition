#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A;
  cin >> A;
  if (A < 40) {
    cout << 40 - A << endl;
  } else if (A < 70) {
    cout << 70 - A << endl;
  } else if (A < 90) {
    cout << 90 - A << endl;
  } else {
    cout << "expert" << endl;
  }
  return 0;
}