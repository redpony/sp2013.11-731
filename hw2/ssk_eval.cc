#include "kernel_string_subseq.h"

#include <vector>
#include <iostream>
#include "tdict.h"

using namespace std;

int main() {
  string in;
  const int kDIV = TD::Convert("|||");
  vector<int> x;
  while(getline(cin, in)) {
    x.clear();
    TD::ConvertSentence(in, &x);
    vector<int> h1,h2,ref;
    unsigned i = 0;
    while(x[i] != kDIV) { h1.push_back(x[i]); ++i; }
    ++i;
    while(x[i] != kDIV) { h2.push_back(x[i]); ++i; }
    ++i;
    while(i < x.size()) { ref.push_back(x[i]); ++i; }
    //cerr << TD::GetString(ref) << endl;
    float s1 = ssk<4>(h1, ref, 0.91);
    float s2 = ssk<4>(h2, ref, 0.91);
    if (fabs(s1 - s2) < 0.000001) cout << "0\n"; else {
      if (s1 > s2) { cout << -1 << endl; } else { cout << 1 << endl; }
    }
  }
}


