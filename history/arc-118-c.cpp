#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  set<ll> A;

  rep(i, 2, 1666) { A.insert(i * 6); }
  rep(i, 2, 1000) { A.insert(i * 10); }
  rep(i, 2, 666) { A.insert(i * 15); }

  cout << "6 10 15 ";
  // N-3 times
  ll count = 3;
  for (auto it = A.begin(); it != A.end(); it++) {
    if (count == N) {
      break;
    }
    cout << *it << " ";
    count++;
  }
}