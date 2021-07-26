#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll le;
vector<ll> li(20);
bool en = false;

void dfs(vector<ll> curs) {
  if (en == true) return;
  int cnt = curs.size() - 1;
  if (cnt == le) {
    return;
  }
  ll base = curs.back();
  ll next = li[cnt];
  ll pos = base + next;
  ll neg = base - next;
  rep(i, 0, le) {
    if (pos == li[i] || pos == 0) {
      cout << "YES" << endl;
      en = true;
      return;
    }
    if (neg == li[i] || neg == 0) {
      cout << "YES" << endl;
      en = true;
      return;
    }
  }
  auto cp = curs;
  curs.push_back(pos);
  cp.push_back(neg);
  dfs(curs);
  dfs(cp);
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    cin >> le;
    rep(j, 0, le) { cin >> li[j]; }
    en = false;
    dfs({0});
    if (en == false) {
      cout << "NO" << endl;
    }
  }
}