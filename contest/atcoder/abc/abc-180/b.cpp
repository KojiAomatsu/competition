#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  ll ma = 0;
  ll yus = 0;
  ll mx = 0;
  rep(i, 0, N) {
    ma += abs(A[i]);
    yus += A[i] * A[i];
    mx = max(mx, abs(A[i]));
  }
  cout << ma << endl;
  printf("%.12f\n", sqrt(yus));
  cout << mx << endl;
}