#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  bool ans = false;
  if (N >= INT_MIN && N <= INT_MAX) ans = true;
  cout << (ans ? "Yes" : "No") << endl;
}