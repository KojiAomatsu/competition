#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll M, H;
  cin >> M >> H;
  cout << (H % M == 0 ? "Yes" : "No") << endl;
}
