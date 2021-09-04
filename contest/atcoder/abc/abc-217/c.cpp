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
  vector<ll> B(N);
  rep(i, 0, N) { B[A[i] - 1] = i + 1; }
  for (auto item : B) {
    cout << item << " ";
  }
  cout << endl;
}