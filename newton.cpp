#include <iostream>
using namespace std;

double newton(double x[], double y[], int n, double xx)
{
    double mt[n][n];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if(j==0)
                mt[i][j] = y[i];
            else mt[i][j] = 0.0;
        }
    }

    for (int j = 1; j<n;j++)
    {
        for (int i = j; i<n; i++)
        {
            mt[i][j] = (mt[i][j-1]-mt[i-1][j-1])/(x[i] - x[i-j]); 
        }
    }

    cout<<"\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout<<mt[i][j]<<'\t';
        }
        cout<<"\n";
    }

    double result = mt[0][0];
    double term = 1.0;

    for (int i = 1; i<n ;i++) 
    {
        term = 1.0;
        for (int j = 0; j< i; j++)
        {
            term *= (xx - x[j]);
        }
        result += mt[i][i] * term;
    }

    return result;

}
int main()
{
    int n;
    cout<<"So luong moc suy: ";
    cin>>n;

    double x[n], y[n];
    cout<<"Nhap cac moc x\n";
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    cout<<"Nhap cac moc y\n";
    for (int i = 0; i < n; i++)
    {
        cin>>y[i];
    }

    double xx;
    cout<<"Tinh gia tri tai x = ";
    cin>>xx;

    cout<<"\n ==> "<<newton(x, y, n, xx);
    return 0;
}