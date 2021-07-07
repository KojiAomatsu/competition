#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

bool solve(ll n, ll a, ll b) {
  if (a == 1) {
    return (n - 1) % b == 0;
  }

  bool ans = false;
  ll ak = 1;
  while (ak <= n) {
    if ((n - ak) % b == 0) {
      ans = true;
      break;
    }
    ak *= a;
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll n, a, b;
    cin >> n >> a >> b;
    cout << (solve(n, a, b) ? "Yes" : "No") << endl;
  }
}