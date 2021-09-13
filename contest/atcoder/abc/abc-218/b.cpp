#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string ans = "";
  rep(i, 0, 26) {
    ll pi;
    cin >> pi;
    ans += 'a' + (pi - 1);
  }
  cout << ans << endl;
}
