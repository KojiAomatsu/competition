#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  vector<ll> B(M);
  rep(i, 0, M) { cin >> B[i]; }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  ll curm = abs(A[0] - B[0]);
  bool is_a_smaller = A[0] < B[0];
  ll curi = is_a_smaller ? 1 : 0;
  ll curj = is_a_smaller ? 0 : 1;
  if (curm == 0) {
    cout << 0 << endl;
    return 0;
  }
  while (curi < N && curj < M) {
    curm = min(curm, abs(A[curi] - B[curj]));
    is_a_smaller = A[curi] < B[curj];
    if (is_a_smaller) {
      curi++;
    } else {
      curj++;
    }
  }
  cout << curm << endl;
  return 0;
}