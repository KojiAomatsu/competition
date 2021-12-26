#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll D;
  cin >> D;
  double ans = (double)D / 100.0;
  printf("%.11f", ans);
}