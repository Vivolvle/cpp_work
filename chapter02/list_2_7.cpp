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

//插入操作 i是绝对位置，比如i为1，对应链表的位置时data[0]
bool ListInsert(SqList &L,int i,ElemType e){
    if(i<1||i>L.length+1) //越界判断
        return false;
    if(L.length>=MaxSize)   //判断顺序表是否已满
        return false;
    for(int j=L.length;j>=i;j--)
        L.data[j] = L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}

//顺序插入元素至列表
bool ListInsertByLast(SqList &L,ElemType e){
    return ListInsert(L,L.length+1,e);
}

//合并两个有序链表
SqList MergeList(SqList &L,SqList &S){

    SqList list;
    assert(L.length+S.length<=MaxSize);
    //两个顺序表都不为空，合并操作，也就是归并排序的下一步
    int i=0,j=0;
    while (i <L.length&&j<S.length)
    {
        if (L.data[i]<=S.data[j])
        {
            ListInsertByLast(list,L.data[i++]);
        }
        if (L.data[i]>=S.data[j])
        {
            ListInsertByLast(list,S.data[j++]);
        }
    }
    //下面的两个循环，其实只有一个会被执行
    while (i <L.length)
    {
        ListInsertByLast(list,L.data[i++]);
    }
    while (j <S.length)
    {
        ListInsertByLast(list,S.data[j++]);
    }
    return list;
}

int main(){
    SqList L;
    vector<ElemType> vector1 = {1,2,3,4,5,6,7,8};
    InitList(L,vector1);
    SqList S;
    vector<ElemType> vector2 = {3,6,7,8,9,12};
    InitList(S,vector2);
    SqList result = MergeList(L,S);
    ListPrint(result);
    return 0;
}