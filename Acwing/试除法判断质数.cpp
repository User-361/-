#include<iostream>
using namespace std;
bool prime(int x){  //判断x是不是质数
    if(x<2)return false;
    for(int i=2;i<=x/i;i++){    //只枚举0-sqrt(n)的数就可以判断
        if(x%i==0)return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(prime(x))puts("Yes");
        else puts("No");
    }
    return 0;
}