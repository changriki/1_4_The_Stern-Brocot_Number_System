#include <iostream>
#include <cstdio>
using namespace std;

class Fraction {
public:
  int m;
  int n;
};

bool slt(Fraction a, Fraction b) {
  return (a.m * b.n) < (b.m * a.n);
}

bool sne(Fraction a, Fraction b) {
  return (a.m != b.m) || (a.n != b.n);
}

int main() {
  Fraction left, right;
  Fraction destination, trace; // F = destination, M = trace
  string path;

  while(cin >> destination.m >> destination.n){
    if(cin.eof() || (destination.m == 1 && destination.n == 1)) break;
    path = "";
    trace.m = 1;
    trace.n = 1;

    left.m = 0;
    left.n = 1;
    right.m = 1;
    right.n = 0;

    while(sne(destination, trace)) {
      if( slt(destination, trace)) {
        path += "L";
        right = trace;
        trace.m += left.m;
        trace.n += left.n;
      }
      else {
        path += "R";
        left = trace;
        trace.m += right.m;
        trace.n += right.n;
      }
    }
    cout << path.c_str() << endl;
  }

  return 0;
}