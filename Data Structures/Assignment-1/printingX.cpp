#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    bool crossed = false;
    if(N>20 || N<1 || N%2==0)
    {
        return 0;
    }
    int middleSpace=N-2;
    int leftSpace=0;
    for(int i=0; i<N; i++)
    {
       // cout<<middleSpace<<" "<<leftSpace<<endl;
       if(middleSpace>=0 )
       {
         for(int j=0;j<leftSpace;j++)
        {
            cout<<" ";
        }
        
        crossed? cout<<"/":cout<<"\\";
        
        for(int k=0;k<middleSpace;k++)
        {
            cout<<" ";
        }
        crossed? cout<<"\\":cout<<"/";
        cout<<endl;
       }
       else
       {
        for(int j=0;j<leftSpace;j++)
        {
            cout<<" ";
        }
        cout<<"X"<<endl;;
       }
       if(middleSpace<=0)
       {
        crossed=true;
       }
       if(crossed==true)
       {
        middleSpace+=2;
        leftSpace--;
       }
       else
       {
        leftSpace++;
        middleSpace-=2;
       }
       
    }
    
}