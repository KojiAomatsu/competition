#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  deque<int> dq;
  dq.push_back(N);
  for (int i = S.size() - 1; i >= 0; i--) {
    if (S[i] == 'R')
      dq.push_front(i);
    else
      dq.push_back(i);
  }
  N++;
  while (N--) {
    int d = dq.front();
    dq.pop_front();
    cout << d << ' ';
  }
  cout << endl;
}