#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B;
  cin >> A >> B;
  if (A > B) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = (B - A) / 10;
  ll rem = (B - A) % 10;
  if (rem != 0) {
    ans++;
  }

  cout << ans << endl;
}
