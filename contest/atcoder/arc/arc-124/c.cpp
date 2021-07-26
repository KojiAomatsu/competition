#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<vector<ll>> ans(100);

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  vector<ll> b(N);
  rep(i, 0, N) { cin >> a[i] >> b[i]; }

  queue<tuple<int, int, ll, ll>> q; // i番目Red j に選ぶもの, GCD, GCD
  q.push({0, 0, 1, 1});
  q.push({0, 1, 1, 1});
  while (!q.empty()) {
    auto nod = q.front();
    q.pop();
    ll idx = get<0>(nod);
    bool chosea = get<1>(nod) == 0;
    ll newa = gcd(get<2>(nod), chosea ? a[idx] : b[idx]);
    ll newb = gcd(get<3>(nod), chosea ? b[idx] : a[idx]);

    bool flaga = true;
    bool flagb = true;
    for (auto an : ans[idx]) {
      if (an % newa == 0) {
        flaga = false;
      }
      if (an % newb == 0) {
        flagb = false;
      }
    }
  }
}