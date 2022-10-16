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
    friend ostream& operator<<(ostream &mout, const matrix&);
    friend istream& operator>>(istream &min, matrix&);
    matrix(int n = 0, int m = 0, int v = 0){
        mtrx.assign(n, vi(m, v));
    }
    matrix(vvi& v, int val = 1){
        mtrx.resize(v.size());
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                mtrx[i].pb(v[i][j] * val);
            }
        }
    }
    void transpon(){
        vvi v(mtrx[0].size());
        for(int i = 0; i < mtrx[0].size(); ++i){
            for(int j = 0; j < mtrx.size(); ++j){
                v[i].pb(mtrx[j][i]);
            }
        }
        *this = matrix(v);
    }
};
ostream& operator<<(ostream &mout, const matrix &v){
    for(int i = 0; i < v.mtrx.size(); ++i){
        for(int j = 0; j < v.mtrx[i].size(); ++j){
            mout << v.mtrx[i][j] << ' ';
        } mout << endl;
    }
    return mout;
}
istream& operator>>(istream &min, matrix &v){
    for(int i = 0; i < v.mtrx.size(); ++i){
        for(int j = 0; j < v.mtrx[i].size(); ++j){
            min >> v.mtrx[i][j];
        }
    }
    return min;
}
void solve(){
    int n, m; cin >> n >> m;
    matrix a(n, m);
    cin >> a;
    a.transpon();
    cout << a;
}
signed main(){
    solve(); return 0;
}