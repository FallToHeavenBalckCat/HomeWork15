#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>

#define m first;
#define n second;

using namespace std;


typedef pair<int,int> PII;//typedef的作用是给数据类型起一个别名，方便编码

const int N=5;

char g[N][N],backup[N][N];

int get(int x,int y)
{
    return x*4+y;//返回对应位置的十进制数
}
void turn(int x,int y)
{
    if(g[x][y]=='+') g[x][y]='-';
    else 
        g[x][y]='+';
}   
void turn_all(int a,int b)
{
    for(int i=0;i<4;i++)
    {
        turn(a,i);
        turn(i,b);
    }
    turn(a,b);
}
int main()
{
    
    for(int i=0;i<4;i++)
    {
        cin>>g[i];
    }
    vector<PII> res;
    //遍历所有操作，共有65536种操作
    for(int op=0;op<1<<16;op++)
    {
        vector<PII> temp;//temp是储存没一种方案的操作记录，res则是不断更新力求找到最短的解决方案
        memcpy(backup,g,sizeof g);
        
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(op>>get(i,j)&1)
                {
                    turn_all(i,j);
                    temp.push_back({i,j});
                }
            }
        }
        //判断这种操作是否成立，如果成立计算步数和输出步骤
        
        bool open_s=false;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(g[i][j]=='+')//只要遇到一个闭合的，就将open_s标记置为false
                {
                    open_s=true;
                }
            }
        }
        if(open_s==false)
        {
            if(res.empty()||res.size()>temp.size()) res=temp;
        }
        memcpy(g,backup,sizeof(backup));
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
    }
    return 0;
}