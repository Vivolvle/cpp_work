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
}
ElemType DeleteMin(SqList &L){
    assert(L.length>0);//判断顺序表是否为空，为空则报错
    ElemType result = L.data[0];
    int index=0;
    for(int i=0;i<L.length;i++){
        if(result>L.data[i]){
            result=L.data[i];
            index=i;
        }
    }
    if(index==L.length-1){//如果最小值在最后一位，则不需要进行元素位置替换
        L.length--;
    }
    else{
        L.data[index]=L.data[L.length-1];
        L.length--;
    }
    return result;
}
int main(){
    SqList list;
    vector<ElemType> vector = {8,9,3,4,5};
    InitList(list,vector);
    ElemType result = DeleteMin(list);
    cout<<"the min value is: "<<result<<endl;
    ListPrint(list);
    return 0;
}