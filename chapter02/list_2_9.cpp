#include<iostream>
#include<vector>
//断言
#include<cassert>
#define MaxSize 50 //定义线性表的最大程度
using namespace std;
//为了和教材一致，我们选择了将int用ElemType代替
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; //顺序表的元素
    int length = 0; //顺序表的当前长度,初始化长度为0
}SqList;

//批量插入至list
void InitList(SqList &L,vector<ElemType> &v){
    for(int i=0;i<v.size();i++){
        L.data[L.length++]=v[i];
    }
}
//打印出list全部内容
void ListPrint(SqList &L){
    for(int i=0;i<L.length;i++){
        cout<<L.data[i]<<"\t";
    }
    cout<<"\nthe length of the list is: "<<L.length;
}

//二分查找
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


void SearchExchangeOrInsert(SqList &L,ElemType x){
    //首先找一下x在顺序表中是否存在 在顺序表寻找一个元素的位置，我们使用二分查找，时间复杂度更低
    //因为不仅仅需要用到mid的值，还会用到high，所以不使用二分查找的方法，而是写在本方法内，以便于使用high
    int mid,low=0,high=L.length-1,index;//index为元素的所在位置，mid，low，high为二分查找的三个变量
    while (low<=high)
    {
        mid=(low+high)/2;
        if (L.data[mid]==x)
            break;
        else if (L.data[mid]<x)
        {
            low=mid+1;
        }else
        {
            high=mid-1;
        }
    }
    if (L.data[mid]==x)
    {
        index= mid;
    }else{
        index= -1;
    }

    if (index!=-1&&index!=L.length-1)
    {
        //找到了该元素，并且该元素位置不在最后一个，则对其与其后一个元素做一个位置调换
        ElemType temp = L.data[index];
        L.data[index]=L.data[index+1];
        L.data[index+1]=temp;
    }else if (high!=L.length-1&&index==-1)
    {
        //这种情况意味着，x未在顺序表中找到，并且x在顺序表中间
        //low=high+1,且high对应的元素小于x,而low对应位置的元素大于x
        for (int i = L.length-1; i > high; i--)
        {
            L.data[i+1]=L.data[i];
        }
        L.data[high+1]=x;
        L.length++;
    }else
    {
        L.data[high+1]=x;
        L.length++;
    }
    
}

int main(){
    SqList list;
    vector<ElemType> vector = {1,2,3,4,6,7,8};
    InitList(list,vector);
    SearchExchangeOrInsert(list,4);
    ListPrint(list);
    return 0;
}