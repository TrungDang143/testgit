#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void nhap(int &n, double fx[], double &a, double &b, double &ss)
{
    cout<<"Phuong trinh bac: ";
    cin>>n;
    for (int i = 0; i < n - 1; i++)
    {
        cout<<"He so x^"<<n-i<<": ";
        cin>>fx[i];
    }
    cout<<"He so x"<<": ";
    cin>>fx[n-1];
    cout<<"He so tu do"<<": ";
    cin>>fx[n];

    cout<<"Khoang cach li nghiem (a, b)\na = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;

    cout<<"Sai so = ";
    cin>>ss;

}
void xuatpt(int n, double fx[])
{
    for (int i = 0; i<n-1; i++)
    {
        cout<<fx[i]<<"x^"<<n-i<<" + ";
    }
    cout<<fx[n-1]<<"x + "<<fx[n]<<" = 0";
}

void show(int n, double ss)
{
    cout<<'\n'<<setw(3)<<roundf(n * 10000)/10000<<setw(10)<<setw(10)<<roundf(ss * 10000)/10000<<setw(5)<<"truefalse";
}

void dh(int n, double fx[], double dhfx[])
{
    for (int i = 0; i <n; i++)
    {
        dhfx[i] = fx[i]*(n-i);
    }
}

double f_x(int n, double fx[], double m)
{
    double kq = 0;
    for (int i = 0; i<=n; i++)
    {
        kq += fx[i]*pow(m, n-i);
    }
    return kq;
}
void chiadoi(int n, double fx[], double a, double b, double ss)
{
    cout<<'\n'<<setw(3)<<"x"<<setw(10)<<"|a-b|/2"<<setw(5)<<"Tm";
    
    int i = 0;
    double saiso = fabs(a - b)/2.0;
    double fa = f_x(n, fx, a);
    double fb = f_x(n, fx, b);
    double m = (a + b)/2.0;
    double fm = f_x(n, fx, m);
    while (saiso > ss)
    {
        show(i, a, b, m, fm, saiso);

        if (fm*fa < 0)
            b = m;
        else a = m;
        m = (a + b)/2.0;
        fm = f_x(n, fx, m);
        saiso = fabs(a - b)/2;
        i+=1;
    }
    show(i, a, b, m, fm, saiso);
    cout<<"\n=> Nghiem gan dung = "<<roundf(m * 10000)/10000<<"\nVoi sai so = "<<roundf(saiso * 10000)/10000;
}
int main()
{
    int n;
    double a, b, ss, fx[100];
    nhap(n, fx, a, b, ss);
    xuatpt(n, fx);
    chiadoi(n, fx, a, b, ss);
    return 0;
}