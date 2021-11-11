#ifndef FFT_H
#ifndef NTT_H
#define NTT_H
#include"fftdef.h"
namespace FFT{
	word root[1<<mx],inv[1<<mx],eax[1<<mx],ebx[1<<mx];
	struct NTTINIT{
		inline NTTINIT(){
			const ull num1=pow_(3,(mod-1)>>mx);
			const ull num2=pow_(num1,mod-2);
			root[1<<mx_]=inv[1<<mx_]=1;
			for(word i=(1<<mx_)+1;i<(1<<mx);++i){
				root[i]=num1*root[i-1]%mod;
				inv[i]=num2*inv[i-1]%mod;
			}
			for(word i=(1u<<mx_)-1;i;--i)
				root[i]=root[i<<1],inv[i]=inv[i<<1];
		}
	}nttinit;
	#define ntt(num,root) [&](){							\
		word num1=num[head|i],num2=num[head|i|floor];		\
    	num1+=(num2=1ull*num2*root[i|floor]%mod);   		\
		num[head|i]=num1>=mod? num1-mod:num1;	    		\
		num1-=num2,num1+=mod-num2;                  		\
		num[head|i|floor]=num1>=mod? num1-mod:num1;}()
	struct fftreg{
		word ecx[1<<mx];
		inline void operator()(const word size,const word *const f){
			FOR(size>>1){
				ecx[id(size,i)]=f[i];
				ecx[id(size,size>>1|i)]=0;
			}
			fftfor(size) ntt(ecx,root);
		}
	};
	inline void conv(const word size,const fftreg &f,
		const fftreg &g,word *const f_times_g){
		FOR(size) eax[id(size,i)]=1ull*f.ecx[i]*g.ecx[i]%mod;
		fftfor(size) ntt(eax,inv);
		const word num1=pow_(size,mod-2);
		FOR(size) f_times_g[i]=1ull*num1*eax[i]%mod;
	}
}
using FFT::fftreg;
using FFT::conv;
#endif
#endif
