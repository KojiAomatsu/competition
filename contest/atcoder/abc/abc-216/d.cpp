#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll N, M;
vector<queue<ll>> ks(220000);
map<ll, ll> memo;
vector<ll> vis(220000, false);

void calc(ll nu, ll co) {
  if (vis[co]) {
    ll memocol, nucol;
    bool memofl = false;
    bool nufl = false;
    ll memod = memo[co];
    ks[memod].pop();
    ks[nu].pop();

    if (!ks[memod].empty()) {
      memocol = ks[memod].front();
      memofl = true;
    }

    if (!ks[nu].empty()) {
      nucol = ks[nu].front();
      nufl = true;
    }
    if (memofl) {
      calc(memod, memocol);
    }
    if (nufl) {
      calc(nu, nucol);
    }
  } else {
    memo[co] = nu;
    vis[co] = true;
  }
  return;
}

int main() {
  cin >> N >> M;
  rep(i, 0, M) {
    ll depth;
    cin >> depth;
    rep(j, 0, depth) {
      ll item;
      cin >> item;
      item--;
      ks[i].push(item);
    }
  }

  ll col = ks[0].front();
  memo[col] = 0;
  vis[col] = true;

  rep(i, 1, M) {
    ll newcol = ks[i].front();
    calc(i, newcol);
  }

  ll emp = true;
  rep(i, 0, M) {
    if (!ks[i].empty()) {
      emp = false;
      break;
    }
  }
  cout << (emp ? "Yes" : "No") << endl;
}