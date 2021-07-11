#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll ai, aj, bi, bj, fi, fj;
    cin >> ai >> aj >> bi >> bj >> fi >> fj;
    ll ans;
    if (ai == bi && aj == bj) {
      cout << 0 << endl;
      continue;
    } else if (ai == bi) {
      ans = abs(aj - bj);
      if (ai == fi && abs(aj - fj) + abs(fj - bj) == ans) {
        ans += 2;
      }
      cout << ans << endl;
      continue;
    } else if (aj == bj) {
      ans = abs(ai - bi);
      if (aj == fj && abs(ai - fi) + abs(fi - bi) == ans) {
        ans += 2;
      }
      cout << ans << endl;
      continue;
    } else {
      ans = abs(ai - bi) + abs(aj - bj);
      cout << ans << endl;
      continue;
    }
  }
}