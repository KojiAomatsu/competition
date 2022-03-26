#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N);
  vector<ll> Y(N);
  rep(i, 0, N) {
    cin >> X[i];
    cin >> Y[i];
  }
  string S;
  cin >> S;
  unordered_map<ll, map<ll, char>> mp;
  rep(i, 0, N) { mp[Y[i]][X[i]] = S[i]; }
  for (auto ele : mp) {
    auto np = ele.second;
    bool has_r = false;
    for (auto e : np) {
      if (e.second == 'L' && has_r) {
        cout << "Yes" << endl;
        return 0;
      }
      if (e.second == 'R') {
        has_r = true;
      }
    }
  }
  cout << "No" << endl;
}