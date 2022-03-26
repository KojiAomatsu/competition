struct fraction {
  ll p, q;
  fraction(ll pi, ll qi) : p(pi), q(qi) {}
  bool operator<(const fraction &other) const { return p * other.q < other.p * q; }
  bool operator<=(const fraction &other) const { return p * other.q <= other.p * q; }
};