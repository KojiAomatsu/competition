#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  string s;
  cin >> s;

  vector<deque<int>> des(26);
  for (int i = 0; i < N; i++) {
    int c_int = s[i] - 'a';
    des[c_int].push_back(i);
  }
  int head = 0;
  int tail = N - 1;
  while (head < tail) {
    int p = -1;
    for (int i = 0; i < s[head] - 'a'; i++) {
      if (!des[i].empty()) {
        p = des[i].back();
        break;
      }
    }
    if (p == -1) {
      des[s[head] - 'a'].pop_front();
      head++;
    } else {
      des[s[head] - 'a'].pop_front();
      for (int i = p; i <= tail; i++) {
        des[s[i] - 'a'].pop_back();
      }
      swap(s[head], s[p]);
      head++;
      tail = p - 1;
    }
  }
  cout << s << endl;
}