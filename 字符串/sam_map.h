#ifndef SAM_H
#define SAM_H
#include<map>
#include"../template.h"
template<word size_,typename type>
struct SAM{
	std::map<type,word> next[size_];
	word fa[size_],floor[size_];
	word last,size;
	inline SAM(){
		size=last=0;
		fa[0]=0xffffffff;
	}
	inline void operator >>(byte c){
		last=next[last][c];}
	#define copy()	\
		floor[++size]=floor[last]+1;					\
		next[size]=next[*num];							\
		fa[size]=fa[*num],fa[*num]=size;				\
		register word old=*num;							\
		*num=size,last=fa[last];						\
		for(;last!=0xffffffff;last=fa[last])			\
			if(*(num=&(next[last][c]))==old) *num=size;	\
			else break;
	inline void operator +=(const type& c){
		register word *num;
		if(*(num=&(next[last][c]))){
			if(floor[*num]==floor[last]+1)
				return void(last=*num);
			copy();
			return void(last=size);
		}
		floor[++size]=floor[last]+1;
		for(;last!=0xffffffff;last=fa[last])
			if(*(num=&(next[last][c]))==0) *num=size;
			else if(floor[*num]==floor[last]+1)
				return fa[size]=*num,void(last=size);
			else{
				copy();
				return void(fa[last=size-1]=size);
			}
		return fa[size]=0,void(last=size);
	}
	#undef copy
};
#endif