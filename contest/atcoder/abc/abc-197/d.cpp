#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll x0, y0;
  ll xN2, yN2;
  cin >> x0 >> y0 >> xN2 >> yN2;

  double centerX = (double)(x0 + xN2) / 2;
  double centerY = (double)(y0 + yN2) / 2;

  double xp = x0 - centerX;
  double yp = y0 - centerY;

  double theta = 2 * M_PI / N;
  double xp1 = cos(theta) * xp - sin(theta) * yp;
  double yp1 = sin(theta) * xp + cos(theta) * yp;

  printf("%.10f %.10f\n", xp1 + centerX, yp1 + centerY);
}
