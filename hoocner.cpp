#include <iostream>
#include <iomanip>
using namespace std;

void nhap(int &n, double fx[], int &c)
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
    cout<<"Tinh f(x) tai x = ";
    cin>>c;
}
void xuatpt(int n, double fx[])
{
    for (int i = 0; i<n-1; i++)
    {
        cout<<fx[i]<<"x^"<<n-i<<" + ";
    }
    cout<<fx[n-1]<<"x + "<<fx[n]<<" = 0";
}
void hoocner(int n, double fx[], int c)
{
    int a[n+1], b[n+1];
    b[0] = fx[0];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i-1]*c;
        b[i] = fx[i]+a[i];
    }
    cout<<"\nHoocner:"<<'\n';
    for(int i = 0; i<=n; i++)
    {
        cout<<setw(4)<<fx[i];
    }
    cout<<'\n';
    for(int i = 1; i<=n; i++)
    {
        if (i == 1) 
            cout<<setw(8)<<a[1];
        else cout<<setw(4)<<a[i];
    }
    cout<<'\n';
    for(int i = 0; i<=n*4+5; i++)
    {
        cout<<'-';
    }
    cout<<'\n';
    for(int i = 0; i<=n; i++)
    {
        cout<<setw(4)<<b[i];
    }
    cout<<'\n';
    cout<<"=> f("<<c<<") = "<<b[n];
}
int main()
{
    int n, c;
    double fx[100];
    nhap(n, fx, c);
    xuatpt(n, fx);
    hoocner(n, fx, c);
    return 0;
}
