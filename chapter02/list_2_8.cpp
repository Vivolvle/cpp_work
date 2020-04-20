#include<iostream>
//断言
#include<cassert>
using namespace std;
//为了和教材一致，我们选择了将int用ElemType代替
typedef int ElemType;
//left和right表示数组下标
void Revert(ElemType A[],int left,int right,int ArraySize){
    for (int i = left; i < left+ArraySize/2; i++)
    {
        ElemType temp=A[i];
        A[i]=A[right-i+left];//交换的元素的两个位置，需要注意right-i+left，不可以写成right-i,因为要考虑left不为0的情况
        A[right-i+left]=temp;
    }
}

void Exchange(ElemType A[],int m,int n,int ArraySize){
    assert(m+n==ArraySize);
    //先变成 8,7,6,5,4,3,2,1
    Revert(A,0,ArraySize-1,ArraySize);
    //对前五个进行转置 4,5,6,7,8
    Revert(A,0,n-1,n);
    //对后三个进行转置 1,2,3
    Revert(A,n,ArraySize-1,m);
}


int main(){
    //定义一个int数组
    ElemType A[8]={1,2,3,4,5,6,7,8};
    Exchange(A,3,5,8);
    for (int i = 0; i < 8; i++)
    {
        cout<<A[i]<<"\t";
    }
    
    return 0;
}