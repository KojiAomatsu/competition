#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  vector<ll> A(4);
  ll mi = 111111;
  rep(i, 0, 4) {
    cin >> A[i];
    mi = min(mi, A[i]);
  }
  cout << mi << endl;
}