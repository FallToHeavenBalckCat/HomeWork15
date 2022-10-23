#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

const int N=20;

int num[N];//储存9个数字的全排列

bool st[N];//判断第I位置是否用过

int n=0;

int ans;

//求分段的数字
int cal(int l,int r)
{
    int cnt=0;
    for(int i=l;i<=r;i++)
    {   
        cnt=cnt*10+num[i];//不断的L向左移动，并且右边加入新的数字
    }
    return cnt;
}
void dfs(int u)//u表示枚举到第几位
{
    if(u==9)//如果枚举到了第九位，那么进行分段处理
    {
        int a,b,c;
        for(int i=0;i<7;i++)
        {
            for(int j=i+1;j<8;j++)
            {
                a=cal(0,i);
                b=cal(i+1,j);
                c=cal(j+1,8);
                if(a*c+b==n*c)
                    ans++;
            }
        }
        return ;
    }

    //递归求全排列
    for(int i=1;i<=9;i++)
    {
        if(!st[i])//如果这个数字没别用过
        {
            st[i]=true;
            num[u]=i;
            dfs(u+1);
            st[i]=false;//恢复现场
            //num[u]=0;不写不会影响，因为会被覆盖掉
        }
    }   
}
int main()
{
    cin>>n;
    dfs(0);
    cout<<ans<<endl;
    return 0;
}