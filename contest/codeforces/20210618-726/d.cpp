#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll num) {
  if (num % 2 == 1) {
    cout << "Bob" << endl;
  } else if ((num & (num - 1)) == 0) {
    ll i = 0;
    while (true) {
      if (num & 1 << i) {
        break;
      }
      i++;
    }
    if (i % 2 == 1) {
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
    }
  } else {
    cout << "Alice" << endl;
  }
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    solve(le);
  }
}
