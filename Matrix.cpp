#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define pb push_back
#define int long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ld = long double;
using ll = long long;

class matrix{
    vvi mtrx;
public:
    matrix operator+(matrix);
    matrix operator*(int);
    matrix operator*(matrix);
    friend ostream& operator<<(ostream &fout, const matrix&);
    friend istream& operator>>(istream &in, matrix&);
    // проверка
};

void solve(){
    
}
signed main(){
    solve(); return 0;
}