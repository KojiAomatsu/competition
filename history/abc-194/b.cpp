#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, 0, N) { cin >> A[i] >> B[i]; }

  ll mi = 10000000;
  rep(i, 0, N) { mi = min(mi, A[i] + B[i]); }

  ll idxa = 0;
  ll mia1 = A[0];
  ll mia2 = 1000000;
  ll idxb = 0;
  ll mib1 = B[0];
  ll mib2 = 1000000;
  rep(i, 1, N) {
    if (A[i] <= mia1) {
      idxa = i;
      mia2 = mia1;
      mia1 = A[i];
    }
    if (B[i] <= mib1) {
      idxb = i;
      mib2 = mib1;
      mib1 = B[i];
    }
  }
  if (idxa != idxb) {
    mi = min(mi, max(mia1, mib1));
  } else {
    mi = min(mi, min(max(mia1, mib2), max(mia2, mib1)));
  }

  cout << mi << endl;
}
