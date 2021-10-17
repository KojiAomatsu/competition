#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A;
  cin >> A;
  cout << (A % 100 == 0 && A != 0 ? "Yes" : "No") << endl;
}