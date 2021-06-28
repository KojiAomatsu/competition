#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  set<ll> se;
  rep(i, 0, N) {
    ll num;
    cin >> num;
    if (num < 1 || num > N + 1) {
      cout << "No" << endl;
      return 0;
    }
    se.insert(num);
  }
  auto flag = se.size() == N;
  cout << (flag ? "Yes" : "No") << endl;
}
