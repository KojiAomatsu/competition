#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> dif(N);
  rep(i, 0, N) {
    cin >> A[i] >> B[i];
    dif[i] = A[i] * 2 + B[i];
  }
  ll sum = accumulate(A.begin(), A.end(), 0ll);
  sort(dif.begin(), dif.end(), greater());
  ll cnt = 0;
  while (sum >= 0) {
    sum -= dif[cnt];
    cnt++;
  }
  cout << cnt << endl;
}
