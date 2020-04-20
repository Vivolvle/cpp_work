#include<iostream>
#include<vector>
//断言
#include<cassert>
#define MaxSize 50 //定义线性表的最大程度
using namespace std;
//为了和教材一致，我们选择了将int用ElemType代替
typedef int ElemType;

//合并两个有序链表
ElemType M_Search(ElemType A[],ElemType B[],int n,ElemType C[]){
    int i=0,j=0,k=0;//分别是A,B,C的元素下标
    while (i <n&&j<n)
    {
        if (A[i]<=B[j])
        {
            C[k++]=A[i++];
        }
        if (A[i]>=B[j])
        {
            C[k++]=B[j++];
        }
    }
    //下面的两个循环，其实只有一个会被执行
    while (i <n)
    {
        C[k++]=A[i++];
    }
    while (j <n)
    {
        C[k++]=B[j++];
    }
    return C[n-1];
}

int main(){
    ElemType A[]={11,13,15,17,19};
    ElemType B[]={2,4,6,7,20};
    ElemType C[10];
    ElemType result = M_Search(A,B,5,C);
    cout<<"the mid number is: "<<result;
    return 0;
}