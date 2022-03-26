#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int rotate(int num) {
  int rem = num % 10;
  int div = num / 10;
  int digits = 1;
  while (true) {
    num /= 10;
    if (num == 0) break;
    digits *= 10;
  }
  return rem * digits + div;
}

int main() {
  ll a, N;
  cin >> a >> N;
  queue<pair<ll, ll>> q;
  q.push(make_pair(1, 0));
  vector<ll> vis(2220000, -1);
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    if (t.first >= 1E6) continue;
    if (vis[t.first] >= 0) continue;
    vis[t.first] = t.second;
    if (t.first == N) break;
    ll new_a = t.first * a;
    if (new_a < 1E6 && vis[new_a] < 0) {
      q.push(make_pair(new_a, t.second + 1));
    }
    if (t.first % 10 != 0) {
      ll rot = rotate(t.first);
      if (rot != t.first && rot < 1E6 && vis[rot] < 0) {
        q.push(make_pair(rot, t.second + 1));
      }
    }
  }
  if (vis[N] == -1) {
    cout << -1 << endl;
  } else {
    cout << vis[N] << endl;
  }
}