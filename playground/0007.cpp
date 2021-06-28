#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> A(N), B(N);
  for (auto &[x, y] : A)
    cin >> x >> y;
  for (auto &[x, y] : B)
    cin >> x >> y;
  unordered_map<int, int> s, t;
  auto add = [](auto &s, auto a1, auto a2, auto a3) {
    const int x1 = a2.first - a1.first, y1 = a2.second - a1.second;
    const int x2 = a3.first - a1.first, y2 = a3.second - a1.second;
    const int cross = x1 * y2 - y1 * x2;
    const int r1 = x1 * x1 + y1 * y1, r2 = x2 * x2 + y2 * y2;
    s[cross << 20 ^ r1 << 10 ^ r2]++;
  };
  for (auto a : A)
    for (auto b : A)
      for (auto c : A)
        add(s, a, b, c);
  for (auto a : B)
    for (auto b : B)
      for (auto c : B)
        add(t, a, b, c);
  for (auto item : s) {
    cout << item.first << " " << item.second << endl;
  }
  puts(s == t ? "Yes" : "No");
}