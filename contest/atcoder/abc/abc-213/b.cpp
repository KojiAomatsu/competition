#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<P> A(N);
  rep(i, 0, N) {
    ll num;
    cin >> num;
    A[i] = {num, i + 1};
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  cout << A[1].second << endl;
}