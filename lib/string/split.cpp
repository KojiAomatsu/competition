#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string tmp;
  cin >> tmp;
  char tab2[tmp.size()];
  cout << tmp.size() << endl;
  strcpy(tab2, tmp.c_str());
  cout << tab2[tmp.size() - 1] << endl;
  for (auto item : tab2) {
    cout << item << ", ";
  }
  cout << endl;
}