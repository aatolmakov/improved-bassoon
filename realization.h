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
    matrix overspeeddegree(int val) {
        if (mtrx.size() != mtrx[0].size()) {
            throw string("Невозможно возведение в степень: матрица не квадратная");
        } else {
            matrix ans = *this;
            matrix value = *this;
            while (val > 0) {
                if (val % 2) {
                    ans = ans * value;
                    val -= 1;
                } else {
                    value = value * value;
                    val /= 2;
                }
            }
            return ans;
        }
    }
};
matrix matrix::operator*(int val){
    matrix d = *this;
    for(int i = 0; i < mtrx.size(); ++i){
        for(int j = 0; j < mtrx[0].size(); ++j){
            d.mtrx[i][j] *= val;
        }
    } return d;
}

matrix matrix::operator*(matrix a){
    matrix ans(mtrx.size(), a.mtrx[0].size());
    if(mtrx[0].size() != a.mtrx.size()){
        throw string("Ошибка умножения: длина строк первой матрицы несовпадает с длиной столбцов второй матрицы");
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
        throw string("Ошибка сложения: размеры матриц не совпадают!");
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
