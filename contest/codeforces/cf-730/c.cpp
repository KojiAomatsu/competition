#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

double ips = 0.000001;

double solve(double c, double m, double p, double v) {
  double ans = 0;
  ans += p * 1;
  if (c != 0) {
    if (c - v >= ips) {
      if (m > ips) {
        double ne = solve(c - v, m + v / 2.0f, p + v / 2.0f, v) + 1.0f;
        ans += c * ne;
      } else {
        double ne = solve(c - v, 0.0f, p + v, v) + 1.0f;
        ans += c * ne;
      }
    } else {
      if (m > ips) {
        double ne = solve(0, m + c / 2.0f, p + c / 2.0f, v) + 1.0f;
        ans += c * ne;
      } else {
        double ne = 1 + 1;
        ans += c * ne;
      }
    }
  }
  swap(c, m);
  if (c != 0) {
    if (c - v >= ips) {
      if (m > ips) {
        double ne = solve(c - v, m + v / 2.0f, p + v / 2.0f, v) + 1.0f;
        ans += c * ne;
      } else {
        double ne = solve(c - v, 0.0f, p + v, v) + 1.0f;
        ans += c * ne;
      }
    } else {
      if (m > ips) {
        double ne = solve(0, m + c / 2.0f, p + c / 2.0f, v) + 1.0f;
        ans += c * ne;
      } else {
        double ne = 1 + 1;
        ans += c * ne;
      }
    }
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    double c, m, p, v;
    cin >> c >> m >> p >> v;
    printf("%.14lf\n", solve(c, m, p, v));
  }
}