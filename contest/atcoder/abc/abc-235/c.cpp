#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  map<ll, vector<ll>> mp;
  rep(i, 0, N) { mp[A[i]].push_back(i + 1); }
  rep(i, 0, Q) {
    ll xi, ki;
    cin >> xi >> ki;
    if (mp.find(xi) == mp.end()) {
      cout << -1 << endl;
      continue;
    }
    if (mp[xi].size() <= ki - 1) {
      cout << -1 << endl;
      continue;
    }
    cout << mp[xi][ki - 1] << endl;
  }
}