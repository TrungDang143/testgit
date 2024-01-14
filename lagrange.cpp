#include <iostream>

using namespace std;

double lagrange(double listX[], double listY[], int n, double x) 
{
    double kq = 0.0;
    for (int i = 0; i< n;i++)
    {
        double pi = listY[i];
        for(int j = 0; j<n;j++)
        {
            if(j != i)
            {
                pi *= (x-listX[j])/(listX[i] - listX[j]);
            }
        }
        kq += pi;
    }
    return kq;
}

int main() 
{
    cout<<"Nhap so moc: ";
    int n;
    cin>>n;

    double listX[n], listY[n];

    for(int i= 0; i<n;i++)
    {
        cout<<"\n Nhap x = ";
        cin>>listX[i];
        cout<<"=> f[" << listX[i] << "] = ";
        cin>>listY[i];
    }

    cout<<"\n Tinh gia tri noi suy tai x = ";
    double x;
    cin>>x;
    cout<<"=> Gia tri noi suy tai "<<x<<" = "<<lagrange(listX, listY, n, x);
    return 0;
}
