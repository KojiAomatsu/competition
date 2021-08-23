#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

bool isPrime[101000];
bool isOK[101000];
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  vector<ll> B;
  rep(i, 0, N) {
    if (A[i] != 1) B.push_back(A[i]);
  }
  N = B.size();

  rep(i, 2, M + 1) { isPrime[i] = true; }
  rep(i, 2, M / 2 + 1) {
    if (!isPrime[i]) {
      continue;
    }
    for (ll j = i * 2; j <= M; j += i) {
      isPrime[j] = false;
    }
  }
  set<ll> ps;
  rep(i, 2, M + 1) {
    if (isPrime[i]) {
      ps.insert(i);
    }
  }

  rep(i, 0, N) {
    for (auto p : ps) {
      if (gcd(B[i], p) != 1) {
        ps.erase(p);
      }
    }
  }

  rep(i, 1, M + 1) { isOK[i] = false; }
  isOK[1] = true;
  rep(i, 1, M + 1) {
    if (!isOK[i]) {
      continue;
    }
    for (auto p : ps) {
      ll j = i * p;
      if (j > M) break;
      isOK[j] = true;
    }
  }
  ll cnt = 0;
  rep(i, 1, M + 1) {
    if (isOK[i]) cnt++;
  }
  cout << cnt << endl;
  rep(i, 1, M + 1) {
    if (isOK[i]) {
      cout << i << endl;
    }
  }
}
