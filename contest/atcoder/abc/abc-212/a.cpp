#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B;
  cin >> A >> B;
  if (A == 0) {
    cout << "Silver" << endl;
  } else if (B == 0) {
    cout << "Gold" << endl;
  } else {
    cout << "Alloy" << endl;
  }
}