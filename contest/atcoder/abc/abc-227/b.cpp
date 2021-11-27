#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> S(N);
  rep(i, 0, N) { cin >> S[i]; }
  map<ll, bool> canbe;
  rep(a, 1, 1000) {
    rep(b, 1, 1000) { canbe[4 * a * b + 3 * a + 3 * b] = true; }
  }
  ll cnt = 0;
  rep(i, 0, N) {
    if (!canbe[S[i]]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}