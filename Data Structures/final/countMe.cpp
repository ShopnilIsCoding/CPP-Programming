#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    while(n--)
        {
        string sen;
        getline(cin,sen);
        map<string,int>wMap;
        stringstream ss(sen);
        string word;
        int pos=0;
        int maxCount=0;
        string mostFrequentWord;

        while(ss>>word)
            {
            pos++;
            wMap[word]++;
            if(wMap[word]>maxCount || (wMap[word]==maxCount && wMap[word]<wMap[mostFrequentWord]))
            {
                maxCount=wMap[word];
                mostFrequentWord=word;
            }
        }
        cout<<mostFrequentWord<<" "<<maxCount<<endl;
    }
    return 0;
}