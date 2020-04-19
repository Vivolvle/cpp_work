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

void DeleteRepeatElem(SqList &L){
    if (L.length==0)
        return;
    int k=1;
    ElemType temp=L.data[0];
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i]!=temp)
        {
            temp=L.data[i];
            L.data[k++]=L.data[i];
        }
    }
    L.length=k;
}

int main(){
    SqList list;
    vector<ElemType> vector = {1,2,2,3,3,4,5,5,6,7,7,8};
    InitList(list,vector);
    DeleteRepeatElem(list);
    ListPrint(list);
    return 0;
}