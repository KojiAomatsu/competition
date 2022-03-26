#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  rep(i, 0, n) { cin >> p[i]; }
  if (n == 2) {
    if (p[0] == 1) {
      cout << 0;
    } else {
      cout << 1;
    }
    return 0;
  }

  ll ans1 = 1E5;
  vector<ll> pp = p;
  pp.insert(pp.end(), p.begin(), p.end());
  pp.insert(pp.end(), p.begin(), p.end());
  ll idx1 = 0;
  while (pp[idx1] != 1) {
    idx1++;
  }
  if (pp[idx1 + 1] == 2) {
    ans1 = idx1;
  }

  ll ans2 = 1E5;
  ll idx2 = 0;
  while (pp[idx2] != n) {
    idx2++;
  }
  if (pp[idx2 + 1] == n - 1) {
    ans2 = idx2 + 1;
  }

  ll ans3 = 1E5;
  vector<ll> rpp = pp;
  reverse(rpp.begin(), rpp.end());
  ll ix1 = 0;
  while (rpp[ix1] != 1) {
    ix1++;
  }
  if (rpp[ix1 + 1] == 2) {
    ans3 = ix1 + 1;
  }

  ll ans4 = 1E5;
  ll ix2 = 0;
  while (rpp[ix2] != n) {
    ix2++;
  }
  if (rpp[ix2 + 1] == n - 1) {
    ans4 = ix2 + 2;
  }

  cout << min({ans1, ans2, ans3, ans4}) << endl;
}