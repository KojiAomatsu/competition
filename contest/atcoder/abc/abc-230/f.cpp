#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)
ll mod = 998244353;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) {
    cin >> A[i];
  }
  
  vector<ll> twos;
  twos[0] = 1;
  rep(i, 0, N) {
    twos[i + 1] = twos[i] * 2 % mod;
  }

  
}