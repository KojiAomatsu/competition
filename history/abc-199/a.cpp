#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  cout << (A * A + B * B < C * C ? "Yes" : "No") << endl;
}