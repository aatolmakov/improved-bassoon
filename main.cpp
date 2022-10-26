#include <iostream>
#include <vector>
#include "realization.h"
#define pb push_back
#define int long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

void solve(){
    cout << "Введите размер первой матрицы: " << endl;
    int n1, m1;
    cin >> n1 >> m1;
    matrix a(n1, m1);
    cout << "Введите первую матрицу: " << endl;
    cin >> a;

    cout << "Введите размер второй матрицы: " << endl;
    int n2, m2;
    cin >> n2 >> m2;
    matrix b(n2, m2);
    cout << "Введите вторую матрицу: " << endl;
    cin >> b;

    cout << endl;
    try{
        matrix c = a + b;
        cout << "Cумма матриц: " << endl;
        cout << c << endl;
    } catch(string msg){
        cout <<msg << endl;
    }
    try{
        matrix c = a * b;
        cout << "Произведение матриц: " << endl;
        cout << c << endl;
    } catch(string msg){
        cout << msg << endl;
    }
    cout << "Введите степень для первой матрицы:" << endl;
    int n; cin >> n;
    try {
        matrix x = a.overspeeddegree(n);
        cout << "Результат возведения: " << endl;
        cout << x << endl;
    } catch (string msg){
        cout << msg << endl;
    }
    cout << "Введите множитель для первой матрицы: " << endl;
    int k; cin >> k;
    cout << endl;
    cout << a * k;

}
signed main(){
    solve(); return 0;
}

