#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll memo[200200];
int main() {
  ll N, W;
  cin >> N >> W;
  vector<ll> A(N);
  rep(i, 0, N) {
    ll s, t, p;
    cin >> s >> t >> p;
    memo[s] += p;
    memo[t] -= p;
  }

  rep(i, 0, 200100) {
    memo[i + 1] += memo[i];
    if (memo[i] > W) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
