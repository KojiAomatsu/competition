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
  unordered_map<ll, ll> bpos;
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) {
    cin >> B[i];
    bpos[B[i]] = i;
  }

  ll hit = 0;
  ll blow = 0;

  rep(i, 0, N) {
    if (bpos.find(A[i]) == bpos.end()) {
      continue;
    }
    if (bpos[A[i]] == i) {
      hit++;
    } else {
      blow++;
    }
  }
  cout << hit << endl;
  cout << blow << endl;
}