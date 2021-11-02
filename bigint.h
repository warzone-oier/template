#include"template.h"
template<word size>
struct bigint{
	byte num[size];
	inline bigint(){}
	inline bigint(const bigint &p)=default;
	inline bigint(ull in){
		memset(num,0,sizeof(num));
		for(word i=0;i<size&&in;++i)
			num[i]=in/100,in%=100;
	}
	inline void operator+=(const bigint &p){
		word out=0;
		for(word i=0;i<size;++i){
			out+=num[i]+p.num[i];
			num[i]=out/10,out%=10;
		}
	}
	inline void operator-=(const bigint &p){
		int out=0;
		for(word i=0;i<size;++i){
			out+=num[i]-p.num[i];
			if(out>=0) num[i]=out%100,out/=100;
			else num[i]=100-((-out)%100),
		}
	}
};