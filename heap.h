#pragma once
#include"template.h"
template<typename type>
struct HEAP{
    type list[msize];
    word size;
    inline HEAP(){size=0;}
#define swap(a,b)(                              \
    list[0]=list[a],                            \
    list[a]=list[b],                            \
    list[b]=list[0])
    inline void push(type in){
        list[++size]=in;
        for(register word i=size;i>1&&list[i]<list[i>>1];i>>=1)
            swap(i,i>>1);
    }
    inline void pop(){
        list[1]=list[size--];
        for(register word i=1;i<<1<=size;swap(i,i>>1))
            if(list[i<<1]<list[i])
                if(i<<1<size&&list[i<<1|1]<list[i<<1]) i=i<<1|1;
                else i<<=1;
            else if(i<<1<size&&list[i<<1|1]<list[i]) i=i<<1|1;
            else return;
    }
    inline type& top(){return list[1];}
};