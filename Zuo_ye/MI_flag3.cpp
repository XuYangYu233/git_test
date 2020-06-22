#include <iostream>
using namespace std;
int main()
{
    for (int i=1;i<=11;i++)
    {
        if (i == 6 )
        {
            for (int j=1;j<=11;j++)
                cout << '*' << ' ';
            cout << endl;
        }           
        else
        {
            if (i>6) i--;
            for (int j=1;j<=21;j++)
            {
                if (j==2*i-1 || j==10 || j==22-i*2-1)
                    cout << "*";
                cout << ' ';
            }
            cout<<endl;
            if (i>5) i++;
        }
    }
    system("PAUSE");
}
