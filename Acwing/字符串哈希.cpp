/*
把字符串看作p进制的数，然后计算hash值，假设人品足够好，遇不到冲突（经验值p的值取131或13331，取模的Q值常取2^64次方）
注意：
不可以把一个字母映射成0
公式：h^r-h^l*p^(r-l+1)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
const int N = 100010,P=131;
int n,m;
char str[N];
ULL h[N],p[N]; //h存放的是字符的hash值，p存放的是p的i次方的值
ULL get(int l, int r)  // 计算子串 str[l ~ r] 的哈希值
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    cin>>n>>m>>(str+1);
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*P;          //计算p的i次方
        h[i]=h[i-1]*P+str[i];   //计算hash值
    }
    while (m -- ){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1,r1)==get(l2,r2))puts("Yes");
        else puts("No");
    }
    
}