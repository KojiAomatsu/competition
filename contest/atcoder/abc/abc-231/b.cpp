#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  map<string, ll> mp;
  rep(i, 0, N) {
    string si;
    cin >> si;
    mp[si]++;
  }
  ll mx = 0;
  string ans = "";
  for (auto m : mp) {
    if (m.second > mx) {
      ans = m.first;
      mx = m.second;
    }
  }
  cout << ans << endl;
}