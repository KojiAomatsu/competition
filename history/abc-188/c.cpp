#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll mx1 = 0;
  ll i1 = 0;
  rep(i, 0, 1 << (N - 1)) {
    ll num;
    cin >> num;
    if (mx1 < num) i1 = i;
    mx1 = max(mx1, num);
  }
  ll mx2 = 0;
  ll i2 = 0;
  rep(i, 0, 1 << (N - 1)) {
    ll num;
    cin >> num;
    if (mx2 < num) i2 = i + (1 << (N - 1));
    mx2 = max(mx2, num);
  }
  if (mx1 > mx2) {
    cout << (i2 + 1) << endl;
  } else {
    cout << (i1 + 1) << endl;
  }
}
