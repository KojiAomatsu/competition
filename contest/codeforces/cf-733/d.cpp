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
    vector<ll> li(le + 1);
    set<ll> se;
    map<ll, ll> deci;
    map<ll, ll> to;
    rep(j, 1, le + 1) {
      cin >> li[j];
      if (se.count(li[j]) == 0) {
        deci[j] = li[j];
        to[li[j]] = j;
      }
      se.insert(li[j]);
    }
    cout << se.size() << endl;

    queue<ll> qu;
    rep(j, 1, le + 1) {
      if (se.count(j) == 0) {
        qu.push(j);
      }
    }
    vector<ll> ans;
    rep(j, 1, le + 1) {
      if (deci.count(j) != 0) {
        ans.push_back(deci[j]);
        continue;
      }
      ll nu;
      if (qu.size() == 0) {
        nu = 0;
      } else {
        nu = qu.front();
        qu.pop();
      }
      if (nu == j || nu == 0) {
        qu.push(nu);
        nu = qu.front();
        qu.pop();
        if (nu == j || nu == 0) {
          qu.push(nu);
          nu = qu.front();
          qu.pop();
        }
      }
      ans.push_back(nu);
    }
    rep(j, 0, le) {
      if (ans[j] == j + 1 || ans[j] == 0) {
        ans[j] = li[j + 1];
        ans[to[ans[j]] - 1] = j + 1;
      }
    }
    for (auto item : ans) {
      cout << item << " ";
    }
    cout << endl;
  }
}