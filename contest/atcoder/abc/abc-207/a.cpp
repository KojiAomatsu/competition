#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  vector<ll> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(), A.end());
  cout << (A[2] + A[1]) << endl;
}