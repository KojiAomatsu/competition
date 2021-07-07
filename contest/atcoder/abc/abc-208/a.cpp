#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B, C;
  cin >> A >> B;
  bool ans = A <= B && A * 6 >= B;
  cout << (ans ? "Yes" : "No") << endl;
}