#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll n;
    cin >> n;
    if (n % 4 == 0) {
      cout << "Even" << endl;
    } else if (n % 2 == 0) {
      cout << "Same" << endl;
    } else {
      cout << "Odd" << endl;
    }
  }
  return 0;
}