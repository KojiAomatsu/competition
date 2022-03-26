#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B, C, X;
  cin >> A >> B >> C >> X;
  double ans = 1.0;
  if (X <= A) {
    // そのまま
  } else if (X > B) {
    ans = 0.0;
  } else {
    ans = (double)C / (B - A);
  }
  printf("%.11f", ans);
}