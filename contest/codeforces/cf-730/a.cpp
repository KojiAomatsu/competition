#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll a, ll b) {
  if (a == b) {
    cout << "0 0" << endl;
    return;
  }
  if (a > b) {
    swap(a, b); // a <= b always
  }
  ll mx = b - a; // >= 1
  ll rem = a % mx;
  ll mn = min(mx - rem, rem);
  cout << mx << " " << mn << endl;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll a, b;
    cin >> a >> b;
    solve(a, b);
  }
}