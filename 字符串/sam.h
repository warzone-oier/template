#ifndef SAM_H
#define SAM_H
#include"../template.h"
template<word size_,byte sum>
struct SAM{
	word next[size_][sum];
	word fail[size_],floor[size_];
	word last,size;
	inline SAM(){
		memset(next,0,sizeof(next));
		fail[0]=0xffffffff;
		floor[0]=size=last=0;
	}
	inline void operator >>(byte c){
		last=next[last][c];}
	#define copy()	\
		register word old=*num;							\
		floor[++size]=floor[last]+1;					\
		memcpy(next[size],next[old],sizeof(next[0]));	\
		fail[size]=fail[old],fail[old]=size;			\
		for(;last!=0xffffffff;last=fail[last])			\
			if(*(num=next[last]+c)==old) *num=size;	    \
			else break;
	inline void operator +=(char c){
		register word *num;
		if(*(num=next[last]+c)){
			if(floor[*num]==floor[last]+1)
				return void(last=*num);
			copy();
			return void(last=size);
		}
		floor[++size]=floor[last]+1;
		for(;last!=0xffffffff;last=fail[last])
			if(*(num=next[last]+c)==0) *num=size;
			else if(floor[*num]==floor[last]+1)
				return fail[size]=*num,void(last=size);
			else{
				copy();
				return void(fail[last=size-1]=size);
			}
		return fail[size]=0,void(last=size);
	}
	#undef copy
};
#endif