//问题：为什么输出从0开始，但输入是从1开始
//回答：输入时i是要放的数字，u才是层数，而输出的i是层数，所以才从0开始
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10;
int n;
int path[N];
int st[N];

void dfs(int u){
    if(u==n){                   //如果u(层数)等于n(数字个数)，全部输出
        for(int i=0;i<n;i++)   cout<<path[i]<<" ";
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {      //如果不等于，往下一层推进
        if(!st[i])
        {             //如果该数字还没有被用过，放入
            path[u]=i;          //在这一层放入数字
            st[i]=true;         
            dfs(u+1);           
            st[i]=false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
}
