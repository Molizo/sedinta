#include <iostream>
#include <fstream>

using namespace std;
ifstream in("sedinta.in");
ofstream out("sedinta.out");

///Cea mai lunga sedinta si max nr de sedinte simultane

int v[1440];

int main()
{int n,maxn=0,cnt=0,x=0,cx,max2=0;char ch;
    in>>n;
    for(int i=0;i<n;i++)
    {
        int sh=0,sm=0,fh=0,fm=0;
        in>>ch;
        sh=ch-'0';
        in>>ch;
        sh=sh*10+ch-'0';
        in>>ch; /// for :

        in>>ch;
        sm=ch-'0';
        in>>ch;
        sm=sm*10+ch-'0';

        in>>ch;
        fh=ch-'0';
        in>>ch;
        fh=fh*10+ch-'0';
        in>>ch; /// for :

        in>>ch;
        fm=ch-'0';
        in>>ch;
        fm=fm*10+ch-'0';

        sm=sm+sh*60;
        fm=fm+fh*60;

        if(max2<fm-sm)
            max2=fm-sm;

        for(int j=sm;j<fm;j++)
            v[j]++;
    }
    x=v[0];
    for(int i=0;i<1440;i++)
    {
        if(x<v[i])
        {
            x=v[i];
            if(maxn<cnt)
            {
                maxn=cnt;
                cx=x;
            }
            continue;
        }
        if(x==v[i])
            cnt++;
    }
    cout<<max2<<" "<<cx;
    return 0;
}
