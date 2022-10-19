#pragma once
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
/*    рекурсивное возведние:
      степень возможна только для квадратной матрицы,
      так что если она не квадратная, игнорирует действие
*/
    matrix overspeeddegree(int val){
        if(mtrx.size() != mtrx[0].size()){
            return mtrx;
        } else{
            if(val == 0){
                return matrix(mtrx.size(), mtrx[0].size(), 1);
            } else if(val == 1){
                return *this;
            } else if(val % 2 == 1){
                return overspeeddegree(val - 1) * mtrx;
            } else{
                return overspeeddegree(val / 2) * overspeeddegree(val / 2);
            }
        }
    }
};
matrix matrix::operator*(int val){
    for(int i = 0; i < mtrx.size(); ++i){
        for(int j = 0; j < mtrx[0].size(); ++j){
            mtrx[i][j] *= val;
        }
    } return *this;
}

matrix matrix::operator*(matrix a){
    // проверка на соответствие размеров, в случае несовпадения игнорирует действие
    matrix ans(mtrx.size(), a.mtrx[0].size());
    if(mtrx[0].size() != a.mtrx.size()){
        return *this;
    } else{
        for(int i = 0; i < mtrx.size(); ++i){
            for(int j = 0; j < a.mtrx[i].size(); ++j){
                int count = 0;
                for(int z = 0; z < mtrx[i].size(); ++z){
                    count += mtrx[i][z] * a.mtrx[z][j];
                }
                ans.mtrx[i][j] = count;
            }
        }
    }
    return ans;
}


matrix matrix::operator+(matrix a){
    vvi ans(a.mtrx.size());
    if(a.mtrx[0].size() != mtrx[0].size() || a.mtrx.size() != mtrx.size()){
        return mtrx;
    } else{
        for(int i = 0; i < mtrx.size(); ++i){
            for(int j = 0; j < mtrx[0].size(); ++j){
                ans[i].pb(a.mtrx[i][j] + mtrx[i][j]);
            }
        }
    }
    return ans;
}

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