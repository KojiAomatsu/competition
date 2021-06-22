#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll V, T, S, D;
  cin >> V >> T >> S >> D;
  cout << ((V * T <= D && V * S >= D) ? "No" : "Yes") << endl;
}
