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
  map<ll, bool> mp;
  rep(i, 0, 2002) { mp[i] = false; }
  for (auto ai : A) {
    mp[ai] = true;
  }
  for (auto m : mp) {
    if (!m.second) {
      cout << m.first << endl;
      return 0;
    }
  }
}