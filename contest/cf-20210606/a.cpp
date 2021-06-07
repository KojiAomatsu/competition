#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll num, vector<ll> li) {
  ll completion = 0;

  while (completion < li.size()) {
    rep(i, completion, li.size()) {
      rep(j, 0, li.size()) {
        ll ab = abs(li[i] - li[j]);
        if (i == j) {
          continue;
        }
        if ((find(li.begin(), li.end(), ab)) == li.end()) {
          li.push_back(ab);
          if (li.size() > 300) {
            goto out_of_while; // break while loop
          }
        }
      }
      completion = i + 1;
    }
  }
out_of_while:
  if (li.size() > 300) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  cout << li.size() << endl;
  rep(i, 0, li.size() - 1) { cout << li[i] << " "; }
  cout << li[li.size() - 1] << endl;
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