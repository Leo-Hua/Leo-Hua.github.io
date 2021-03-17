/*
少加头文件，爆零两行泪
DP后效性，爆零两行泪
文件读入错，爆零两行泪
文件名写错，爆零两行泪
调完不编译，爆零两行泪
结论不证明，爆零两行泪
数组没开够，爆零两行泪
ll开 int，爆零两行泪
 dp 没初值，爆零两行泪
深搜没边界，爆零两行泪
广搜忘出队，爆零两行泪
模数没看清，爆零两行泪
越界不特判，爆零两行泪
多测不清空，爆零两行泪
空间胡乱开，爆零两行泪
无向变有向，爆零两行泪
调试忘删除，爆零两行泪
文件不保存，爆零两行泪
题目提交错，爆零两行泪
*/
#include<iostream>
#include<cstring>
using namespace std;
int lowbit(int a)
{
    return a&(-a);
}
int main()
{
    int n=2,m=1;
    int ans[m+1];
    int a[n+1],c[n+1],s[n+1];
    int o=0;
    memset(c,0,sizeof(c));
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        c[i]=s[i]-s[i-lowbit(i)];//树状数组创建前缀和优化
    }
    for(int i=1;i<=m;i++)
    {
        int q=2;
        //if(q==1)
        //{（没有更改操作）
        //    int x,y;
        //    cin>>x>>y;
        //    int j=x;
        //    while(j<=n)
        //    {
        //        c[j]+=y;
        //        j+=lowbit(j);
        //    }
        //}
        //else
        {
            int x=1,y=2;//求a[1]+a[2]的和
            int s1=0,s2=0,p=x-1;
            while(p>0)
            {
                s1+=c[p];
                p-=lowbit(p);//树状数组求和操作，用两个前缀和相减得到区间和
            }
            p=y;
            while(p>0)
            {
                s2+=c[p];
                p-=lowbit(p);
            }    
            o++;
            ans[o]=s2-s1;//存储答案
        }
    }
    for(int i=1;i<=o;i++)
        cout<<ans[i]<<endl;//输出
    return 0;
}

