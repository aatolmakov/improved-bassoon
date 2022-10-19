#include <iostream>
#include <Windows.h>
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

    cout << "Введите множитель k (на него умножится первая матрица): " << endl;
    int k;
    cin >> k;
    cout << "Введите степень n (в неё возведётся первая матрица): " << endl;
    int n;
    cin >> n;

    cout << "Cумма матриц (если верные условия выведет сумму, в противном случае выведет первую матрицу): " << endl;
    cout << a + b << endl;

    cout << "Произведение матриц (если верные условия выведет произведение, в противном случае выведет первую матрицу): " << endl;
    cout << a * b << endl;

    cout << "Произведение первой матрицы на k: " << endl;
    cout << a * k << endl;

    cout << "Первая матрица в степени n (если верные условия выведет первую матрицу в степени n, в противном случае выведет исходную матрицу): " << endl;
    cout << a + b;

    cout << "Транспонирование первой матрицы: " << endl;
    a.transpon();
    cout << a;

}
signed main(){
    SetConsoleOutputCP(CP_UTF8);
    solve(); return 0;
}