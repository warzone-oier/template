#include"template.h"
#pragma once
struct READ{
	char c,w;
	inline READ(){c=getchar();}
	template<typename type>
	inline READ& operator >>(register type& num){
		for(w=1;'0'>c||c>'9';c=getchar())
			w=c=='-'? -1:1;
		for(num=0;'0'<=c&&c<='9';c=getchar())
			num=num*10+(c-'0');
		if(c=='.'){
			c=getchar();
			for(register ld i=0.1;'0'<=c&&c<='9';)
				num+=i*(c-'0'),c=getchar(),i*=0.1;
		}
		return num*=w,*this;
	}
};