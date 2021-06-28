#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

double dis(P a, P b) {
  return sqrt((double)((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)));
}

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  vector<ll> D(N);
  rep(i, 0, N) { cin >> A[i] >> B[i]; }
  rep(i, 0, N) { cin >> C[i] >> D[i]; }
  if (N == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  double accep = 0.00001;
  P oi = {A[0], B[0]};
  P one = {A[1], B[1]};
  P a = {one.first - oi.first, one.second - oi.second};
  double ra = -1 * atan2(a.second, a.first);
  vector<pair<double, double>> cnd; // dis, radi
  cnd.push_back({dis(one, oi), 0});
  rep(i, 2, N) {
    P b = {A[i] - oi.first, B[i] - oi.second};
    pair<double, double> dot = {b.first * cos(ra) - b.second * sin(ra), b.first * sin(ra) + b.second * cos(ra)};
    double thet = atan2(dot.second, dot.first);
    if (thet <= -3.1415) {
      thet = 3.14159265;
    }
    double d = dis(b, {0, 0});
    cnd.push_back({d, thet});
  }
  sort(cnd.begin(), cnd.end());

  rep(i, 0, N) {
    P ori = {C[i], D[i]};
    double rad;
    rep(j, 0, N) {
      vector<pair<double, double>> cand; // dis, radi
      if (i == j) {
        continue;
      }
      P b = {C[j] - ori.first, D[j] - ori.second};
      rad = -1 * atan2(b.second, b.first);
      cand.push_back({dis(b, {0, 0}), 0});
      rep(k, 0, N) {
        if (i == k || j == k) {
          continue;
        }
        P b = {C[k] - ori.first, D[k] - ori.second};
        pair<double, double> dot = {b.first * cos(rad) - b.second * sin(rad), b.first * sin(rad) + b.second * cos(rad)};
        double thet = atan2(dot.second, dot.first);
        if (thet <= -3.1415) {
          thet = 3.14159265;
        }
        cand.push_back({dis(b, {0, 0}), thet});
      }
      sort(cand.begin(), cand.end());
      bool fl = true;
      rep(j, 0, N - 1) {
        if (!(abs((cnd[j].first - cand[j].first)) <= accep && abs((cnd[j].second - cand[j].second)) <= accep)) {
          fl = false;
          break;
        }
      }
      if (fl) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}