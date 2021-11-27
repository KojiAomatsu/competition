#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  set<vector<ll>> s;
  rep(i, 0, N) {
    ll Li;
    cin >> Li;
    vector<ll> as(Li);
    rep(j, 0, Li) { cin >> as[j]; }
    s.insert(as);
  }
  cout << s.size() << endl;
}