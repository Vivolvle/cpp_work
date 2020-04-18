/**
 * 线性表的顺序存储
 */
#include<iostream>
#include<vector>
#define MaxSize 50 //定义线性表的最大程度
using namespace std;
//为了和教材一致，我们选择了将int用ElemType代替
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize]; //顺序表的元素
    int length = 0; //顺序表的当前长度,初始化长度为0
}SqList;

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
}

bool ListDelete(SqList &L,int i,ElemType &e){
    if(i<1||i>L.length)//越界判断
        return false;
    e=L.data[i-1];//被删除元素赋值给e
    for(int j=i;j<L.length;j++)//将第i个位置开始的元素前移
        L.data[j-1]=L.data[j];
    L.length--; //线性表长度减1
    return true;
}

int LocateElem(SqList &L,ElemType e){
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i++;
    return 0;
}

int main(){
    SqList list;
    ListInsert(list,1,3);
    ListInsert(list,2,4);
    int locate = LocateElem(list,3);
    cout<<locate<<endl;
    cout<<list.length<<endl;
    ElemType e;
    ListDelete(list,1,e);
    cout<<e<<list.length;
    return 0;
}