#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll n, ll m) { cout << 1 << " " << 1 << " " << n << " " << m << endl; }

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    solve(n, m);
  }
}
