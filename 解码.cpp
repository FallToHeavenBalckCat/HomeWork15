#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=110;
string str;
int main(){
    cin>>str;
    string res;
    int n=str.size();
    int k=0;
    for(int i=0;i<n;i++){
        char ch=str[i];
        if(ch>='0'&&ch<='9'){
            char front=str[i-1];
            int m=ch-'0'-1;
            while(m--){
               res+=front; 
            }
        }
        else{
            res+=ch;
        }
    }
    for(auto x:res) cout<<x;
    cout<<endl;
    return 0;
}