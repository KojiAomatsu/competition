#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N);
  vector<ll> Y(N);
  rep(i, 0, N) { cin >> X[i] >> Y[i]; }
  ll M;
  cin >> M;
  vector<P> Op(M);
  rep(i, 0, M) {
    ll type;
    cin >> type;
    switch (type) {
    case 1:
      Op[i] = {1, 0};
      break;
    case 2:
      Op[i] = {2, 0};
      break;
    case 3:
      ll p3;
      cin >> p3;
      Op[i] = {3, p3};
      break;
    case 4:
      ll p4;
      cin >> p4;
      Op[i] = {4, p4};
      break;
    }
  }
  ll Q;
  cin >> Q;
  vector<ll> A(Q);
  vector<ll> B(Q);
  rep(i, 0, Q) { cin >> A[i] >> B[i]; }

  vector<P> origins(M + 1);
  vector<P> x_dir(M + 1);
  vector<P> y_dir(M + 1);

  origins[0] = {0, 0};
  x_dir[0] = {1, 0};
  y_dir[0] = {0, 1};

  rep(i, 0, M) {
    auto op = Op[i];
    switch (op.first) {
    case 1:
      origins[i + 1] = {origins[i].second, -1 * origins[i].first};
      x_dir[i + 1] = {x_dir[i].second, -1 * x_dir[i].first};
      y_dir[i + 1] = {y_dir[i].second, -1 * y_dir[i].first};
      break;
    case 2:
      origins[i + 1] = {-1 * origins[i].second, origins[i].first};
      x_dir[i + 1] = {-1 * x_dir[i].second, x_dir[i].first};
      y_dir[i + 1] = {-1 * y_dir[i].second, y_dir[i].first};
      break;
    case 3:
      origins[i + 1] = {2 * op.second - origins[i].first, origins[i].second};
      x_dir[i + 1] = {-1 * x_dir[i].first, x_dir[i].second};
      y_dir[i + 1] = {-1 * y_dir[i].first, y_dir[i].second};
      break;
    case 4:
      origins[i + 1] = {origins[i].first, 2 * op.second - origins[i].second};
      x_dir[i + 1] = {x_dir[i].first, -1 * x_dir[i].second};
      y_dir[i + 1] = {y_dir[i].first, -1 * y_dir[i].second};
      break;
    }
  }

  rep(i, 0, Q) {
    ll xq = X[B[i] - 1];
    ll yq = Y[B[i] - 1];
    ll ansx = xq * x_dir[A[i]].first + yq * y_dir[A[i]].first + origins[A[i]].first;
    ll ansy = xq * x_dir[A[i]].second + yq * y_dir[A[i]].second + origins[A[i]].second;
    cout << ansx << " " << ansy << endl;
  }
}
