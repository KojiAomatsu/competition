#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<ll> a(le);
    vector<ll> b(le);
    rep(j, 0, le) { cin >> a[j]; }
    rep(j, 0, le) { cin >> b[j]; }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> asum(le + 1);
    vector<ll> bsum(le + 1);
    rep(j, 0, le) { asum[j + 1] = asum[j] + a[j]; }
    rep(j, 0, le) { bsum[j + 1] = bsum[j] + b[j]; }

    ll cnt = 0;
    ll scorea = asum[le] - asum[le / 4];
    ll scoreb = bsum[le] - bsum[le / 4];
    ll cur = le;
    while (scorea < scoreb) {
      cnt++;
      cur += 1;
      scorea = asum[le] + 100 * (cur - le) - asum[cur / 4];
      scoreb = bsum[le] - bsum[max((cur / 4) - (cur - le), 0ll)];
    }
    cout << cnt << endl;
  }
}