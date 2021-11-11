#pragma once
#include"../../template.h"
#define mx 20
#define mx_ 19
#define fftfor(size)								\
	for(word floor=1;floor<(size);floor<<=1)		\
		for(word head=0;head<(size);head+=floor<<1)	\
			for(word i=0;i<floor;++i)
const word mod=992844353,nimod=29;
constexpr ull pow_(word a,word b,const word md=mod){
	word ans=1;
	for(;b;b>>=1){
		if(b&1) ans=1ull*ans*a%md;
		a=1ull*a*a%md;
	}
	return ans;
}
word realid[1<<mx],ni[nimod];
namespace FFT{
	struct FFTDEF{
		inline FFTDEF(){
			ni[2]=pow_(2,mod-2),realid[1]=0;
			for(word floor=1,i=2;floor<=mx;++floor){
				ni[(1u<<floor)%nimod]=ni[(1u<<(floor-1))%nimod]*ni[2]%mod;
				for(;i<1u<<(floor+1);++i)
					realid[i]=(i&1)<<(floor-1)|realid[i>>1];
			}
		}
	}fftdef;
}
#define id(size,i) (realid[(i)|(size)])
#define FOR(size) for(word i=0;i<size;++i)
