/**
 * 二分查找，折半查找
 **/
#include<iostream>
using namespace std;
//用ElemType代替int，和书本上保持一致
typedef int ElemType;
//返回的结果是数组的下标，low和high对应的也是数组的下标
int BinarySearch(ElemType A[],ElemType &x,int low,int high){
    int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (A[mid]==x)
            break;
        else if (A[mid]<x)
        {
            low=mid+1;
        }else
        {
            high=mid-1;
        }
    }
    if (A[mid]==x)
    {
        return mid;
    }else{
        return -1;
    }
}

int main(){
    ElemType A[8]={1,2,3,4,5,6,7,8};
    ElemType x = 4;
    int index = BinarySearch(A,x,0,7);
    if (index==-1)
    {
        cout<<"not found";
    }else
    {
        cout<<"the index is: "<<index+1;
    }
    
    
}