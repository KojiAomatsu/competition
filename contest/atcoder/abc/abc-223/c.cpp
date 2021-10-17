#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);

  rep(i, 0, N) { cin >> A[i] >> B[i]; }

  vector<double> norms;
  rep(i, 0, N) { norms.push_back((double)A[i] / B[i]); }
  double su = accumulate(norms.begin(), norms.end(), 0.0);
  double mid = su / 2;
  auto it = lower_bound(norms.begin(), norms.end(), mid);
  ll idx = it - norms.begin();
  cout << idx << endl;
  double sum = accumulate(A.begin(), A.begin() + idx, 0.0);

  printf("%.11f", sum);
}