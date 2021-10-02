#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll K;
  string A, B;
  cin >> K >> A >> B;
  ll a = 0;
  rep(i, 0, A.size()) {
    ll po = pow(K, i);
    ll nu = A[A.size() - i - 1] - '0';
    a += po * nu;
  }
  ll b = 0;
  rep(i, 0, B.size()) {
    ll po = pow(K, i);
    ll nu = B[B.size() - i - 1] - '0';
    b += po * nu;
  }
  cout << a * b << endl;
}