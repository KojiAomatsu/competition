#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B;
  cin >> A >> B;
  double ans = (double)(A - B) / 3.0 + B;
  printf("%.11f", ans);
}