#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll N;
vector<priority_queue<ll, vector<ll>, greater<ll>>> edges(220000);
vector<bool> vis(220000);

void dfs(ll num) {
  vis[num] = true;
  cout << num << " ";

  ll cnt = 0;
  ll mx = edges[num].size();
  while (!edges[num].empty()) {
    ll top = edges[num].top();
    edges[num].pop();

    if (vis[top]) {
      cnt++;
      continue;
    } else {
      dfs(top);
      cout << num << " ";
    }
  }
  return;
}

int main() {
  cin >> N;
  rep(i, 0, N - 1) {
    ll ai, bi;
    cin >> ai >> bi;
    edges[ai].push(bi);
    edges[bi].push(ai);
  }

  dfs(1);
  cout << endl;
}