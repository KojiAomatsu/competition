#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, X;
  cin >> N >> X;
  set<int> se;
  se.insert(0);
  rep(i, 0, N) {
    ll ai, bi;
    cin >> ai >> bi;
    set<int> ns;
    for (auto s : se) {
      if (s + ai <= X) ns.insert(s + ai);
      if (s + bi <= X) ns.insert(s + bi);
    }
    se = ns;
  }
  cout << (se.find(X) != se.end() ? "Yes" : "No") << endl;
}