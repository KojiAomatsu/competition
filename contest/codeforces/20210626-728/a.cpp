#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll num) {
  if (num % 2 == 0) {
    rep(i, 0, num / 2) { cout << (i + 1) * 2 << " " << (i + 1) * 2 - 1 << " "; }
    cout << endl;
  } else {
    cout << "3 1 2 ";
    rep(i, 0, (num - 3) / 2) { cout << (i + 2) * 2 + 1 << " " << (i + 2) * 2 << " "; }
    cout << endl;
  }
  return;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll n;
    cin >> n;
    solve(n);
  }
}