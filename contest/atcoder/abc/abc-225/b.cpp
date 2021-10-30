#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll a0, b0;
  cin >> a0 >> b0;
  ll a1, b1;
  cin >> a1 >> b1;
  ll ro;
  bool fl = true;
  if (a0 == a1 || a0 == b1) {
    ro = a0;
  } else if (b0 == a1 || b0 == b1) {
    ro = b0;
  } else {
    ro = a0;
    fl = false;
  }
  rep(i, 0, N - 3) {
    ll ai, bi;
    cin >> ai >> bi;
    if (ai == ro || bi == ro) {
      // ok
    } else {
      fl = false;
    }
  }
  cout << (fl ? "Yes" : "No") << endl;
}