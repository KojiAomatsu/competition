#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  ll ans = 0;
  ll max_g = 0;
  rep(i, 2, 1001) {
    ll g = 0;
    for (auto a : A) {
      if (a % i == 0) g++;
    }
    if (g > max_g) {
      ans = i;
      max_g = g;
    }
  }
  cout << ans << endl;
}
