#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  double H;
  cin >> H;
  double ans = sqrt(H * (12800000.0 + H));
  printf("%.11f", ans);
}