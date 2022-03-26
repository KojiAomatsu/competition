#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, Q;
  cin >> N >> Q;
  map<ll, vector<ll>> mp;
  rep(i, 0, Q) {
    ll li, ri;
    cin >> li >> ri;
    li--;
    mp[ri].push_back(li);
    mp[li].push_back(ri);
  }

  vector<bool> ables(N + 1);
  vector<bool> vis(N + 1);
  queue<ll> q;
  q.push(0);
  while (!q.empty()) {
    ll top = q.front();
    q.pop();
    vis[top] = true;
    ables[top] = true;
    for (auto m : mp[top]) {
      if (vis[m]) continue;
      q.push(m);
    }
  }

  cout << (ables[N] ? "Yes" : "No") << endl;
}