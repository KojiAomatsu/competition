#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num, vector<ll> &li, vector<ll> &lu) {
  ll ans = 1E12;
  reverse(li.begin(), li.end());
  vector<ll> lis(num + 1);
  rep(i, 0, num) { lis[i + 1] = li[i] + lis[i]; }
  vector<ll> lus(num + 1);
  rep(i, 0, num) { lus[i + 1] = lu[i] + lus[i]; }
  rep(i, 0, num) {
    ll an = max(lis[num - 1 - i], lus[i]);
    ans = min(ans, an);
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<ll> li(le);
    vector<ll> lu(le);
    rep(j, 0, le) { cin >> li[j]; }
    rep(j, 0, le) { cin >> lu[j]; }
    cout << solve(le, li, lu) << endl;
  }
}