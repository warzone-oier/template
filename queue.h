#pragma once
#include"template.h"
template<typename type,word size_>
struct queue{
	type list[size_];
	word head,tail;
	inline queue(){head=tail=0;}
	inline void push(const type& in){
		list[tail]=in;
		if(++tail==size_) tail=0;
	}
	inline void pop(){
		if(++head==size_) head=0;}
	inline word top(){return list[head];}
	inline bool empty(){return head==tail;}
};