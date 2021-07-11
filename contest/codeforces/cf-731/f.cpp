#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

ll gcd(vector<ll> &li) {
  ll n = li.size();
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return li[0];
  }
  ll a;
  a = gcd(li[0], li[1]);
  if (n == 2) {
    return a;
  }

  for (ll i = 2; i < n; i++) {
    a = gcd(a, li[i]);
  }
  return a;
}

void solve(ll num, vector<ll> li) {
  ll g = gcd(li);
  cout << g << endl;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<ll> li(le);
    rep(j, 0, le) { cin >> li[j]; }
    solve(le, li);
  }
}