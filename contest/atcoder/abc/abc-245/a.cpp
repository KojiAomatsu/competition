#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  ll fl = false;
  if (A != C) {
    fl = A < C;
  } else {
    fl = B <= D;
  }
  cout << (fl ? "Takahashi" : "Aoki") << endl;
}