#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B, W;
  cin >> A >> B >> W;
  ll w = W * 1000;

  vector<ll> possibles;
  rep(i, 1, 1000001) {
    ll mi = A * i;
    ll ma = B * i;
    if (mi <= w && ma >= w) {
      possibles.push_back(i);
    }
  }
  if (possibles.size() == 0) {
    cout << "UNSATISFIABLE" << endl;
  } else {
    cout << possibles[0] << " " << possibles.back() << endl;
  }
}
