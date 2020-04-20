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

void ListRevert(SqList &L){
    if(L.length==0)
        return;
    ElemType temp;
    for(int i=0;i<L.length/2;i++){
        temp=L.data[i];
        L.data[i]=L.data[L.length-1-i];
        L.data[L.length-1-i]=temp;
    }
}

int main(){
    SqList list;
    vector<ElemType> vector = {8,9,3,4,5};
    InitList(list,vector);
    ListRevert(list);
    ListPrint(list);
    return 0;
}