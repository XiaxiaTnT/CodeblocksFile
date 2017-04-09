#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
map<string,string> mp;
string s[10]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001"};
string t[10];
int main()
{
    for(int i=0;i<10;i++){
        t[i]=s[9-i];
    }
    for(int i=0;i<10;i++){
        mp[s[i]]=t[i];
    }
    for(int i=0;i<10;i++){
        cout<<mp[s[i]]<<endl;
    }
    return 0;
}
