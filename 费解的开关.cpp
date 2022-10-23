#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

const int N=6;

char g[N][N];

char backup[N][N];//备份数组

int dx[N]={1,0,-1,0,0};//向量表示法对该灯以及周围的四盏灯进行操作
int dy[N]={0,1,0,-1,0};

void turn(int x, int y)
{
    for(int i=0;i<5;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a<0||a>=5||b<0||b>=5)
        {
            continue;//如果越界则忽略
        }
        g[a][b]^=1;//^异或操作，不同数字的^的值为真
    }
}
int main()
{
    cin>>n;
    while(n--)
    {
        for(int i=0;i<5;i++) cin>>g[i];
        int res=10;//记录操作次
        for(int op=0;op<32;op++)
        {
            memcpy(backup,g,sizeof(g));
            int step=0;//同样记录步数
            for(int i=0;i<5;i++)
            {
                if(op>>i&1){
                    //只要这个数字的第I位是1的就进行一次开关操作
                    turn(0,i);
                    step++;
                }
            }
            
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(g[i][j]=='0')
                    {
                        turn(i+1,j);
                        step++;
                    }
                }
            }

            bool dark=false;//判断某个位置上的位置是否是暗的，不是暗的dark=false
            for(int i=0;i<5;i++)
            {
                if(g[4][i]=='0')
                {
                    dark=true;
                    break;//从左到右扫描只要遇到一个暗的就退出循环
                }
            }

            if(!dark)
            {
                res=min(res,step);
            }
             memcpy(g,backup,sizeof(backup));//不管有没有得到<6的最小步骤，都应该在一次测试之后还原到最初状态
        }
        if(res>6)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}