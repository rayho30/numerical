#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int mn;
    for(int i=0;i<n-1;i++){
        mn=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[mn]){
                mn=j;
            }

        }
        swap(v[i],v[mn]);
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<"   ";
    }
    return 0;
}

