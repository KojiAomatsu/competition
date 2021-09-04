#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string A, B;
  cin >> A >> B;
  bool smaller = A < B;
  cout << (smaller ? "Yes" : "No") << endl;
}