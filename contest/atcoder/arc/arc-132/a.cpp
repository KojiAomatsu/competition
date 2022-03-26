#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector<ll> R(n);
  vector<ll> C(n);
  rep(i, 0, n) { cin >> R[i]; }
  rep(i, 0, n) { cin >> C[i]; }
  ll q;
  cin >> q;
  rep(i, 0, q) {
    ll ri, ci;
    cin >> ri >> ci;
    cout << (n - R[ri - 1] < C[ci - 1] ? "#" : ".");
  }
  cout << endl;
}