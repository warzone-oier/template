#pragma once
#include<cmath>
#include"complex.h"
#define mx 20
#define mx_ 19
struct FFT{
	complex root[1<<mx],inv[1<<mx],eax[1<<mx],ebx[1<<mx];
	word realid[1<<(mx+1)];
	inline FFT(){
		for(register word floor=1,i=2;floor<=mx;++floor)
			for(;i<(1u<<(floor+1));++i)
				realid[i]=(i&1)<<(floor-1)|realid[i>>1];
		root[1<<mx_]=inv[1<<mx_]=1;
		const db PI=std::acos(-1.0)/(1<<mx_);
		for(register word i=1;i<1<<mx_;++i){
			root[1<<mx_|i]=complex(std::cos(PI*i),std::sin(PI*i));
			inv[1<<mx_|i]=~root[1<<mx_|i];
		}
		for(register word i=(1<<mx_)-1;i;--i)
			root[i]=root[i<<1],inv[i]=inv[i<<1];
	}
	#define fftfor(size)	\
		for(register word floor=1;floor<(size);floor<<=1)			\
			for(register word head=0;head<(size);head+=floor<<1)	\
				for(register word i=0;i<floor;++i)
	#define fft(num,root)(						\
		num2=num[head|i|floor]*root[i|floor],	\
		num[head|i|floor]=num[head|i]-num2,		\
		num[head|i]+=num2)
	#define id(size,i) realid[(i)|(size)]
	#define FOR(size) for(register word i=0;i<(size);++i)
	#define cover(eax,ecx,edx)(	\
		num1=eax[i]+eax[((size)-i)&~(size)],	\
		num2=eax[i]-eax[((size)-i)&~(size)],	\
		ecx[i]=complex(num1.real/2,num2.imag/2),	\
		edx[i]=complex(num1.imag/2,-num2.real/2))
	complex ecx[1<<mx],edx[1<<mx],eex[1<<mx],efx[1<<mx];
	inline void operator()(const word mod,word size,
		const word *const f,const word *const g,word *const f_times_g){
		FOR(size){
			register word head=id(size<<1,i);
			eax[head]=complex(f[i]>>15,f[i]&0x7fff);
			ebx[head]=complex(g[i]>>15,g[i]&0x7fff);
			head=id(size<<1,i|size);
			eax[head]=ebx[head]=0;
		}
		size<<=1;
		register complex num1,num2;
		fftfor(size) fft(eax,root),fft(ebx,root);
		FOR(size) cover(eax,ecx,edx),cover(ebx,eex,efx);
		num1=complex(0,1);
		FOR(size){
			register word head=id(size,i);
			eax[head]=ecx[i]*eex[i]+num1*edx[i]*efx[i];
			ebx[head]=ecx[i]*efx[i]+num1*edx[i]*eex[i];
		}
		fftfor(size) fft(eax,inv),fft(ebx,inv);
		FOR(size){
			register ull out=0;
			out=(ull)(eax[i].real/size+0.5)%mod;
			out=(ull)(ebx[i].real/size+0.5)%mod+(out%mod<<15)%mod;
			out=(ull)(ebx[i].imag/size+0.5)%mod+out%mod;
			out=(ull)(eax[i].imag/size+0.5)%mod+(out%mod<<15)%mod;
			f_times_g[i]=out%mod;
		}
	}
	template<typename type>
	inline void operator()(word size,
		const type *const f,const type *const g,type *const f_times_g){
		FOR(size){
			register word head=id(size<<1,i);
			eax[head]=complex(f[i],g[i]);
			head=id(size<<1,i|size);
			eax[head]=0;
		}
		size<<=1;
		register complex num1,num2;
		fftfor(size) fft(eax,root);
		FOR(size) ebx[id(size,i)]=eax[i]*eax[i];
		fftfor(size) fft(ebx,inv);
		FOR(size) f_times_g[i]=(ebx[i].imag/size+0.5)/2;
	}
	inline void operator()(word size,
		const complex *const f,const complex *const g,complex *const f_times_g){
		FOR(size){
			register word head=id(size<<1,i);
			eax[head]=f[i],ebx[head]=g[i];
			head=id(size<<1,i|size);
			eax[head]=ebx[head]=0;
		}
		size<<=1;
		register complex num2;
		fftfor(size) fft(eax,root),fft(ebx,root);
		FOR(size) f_times_g[id(size,i)]=eax[i]*ebx[i];
		fftfor(size) fft(f_times_g,inv);
		FOR(size) f_times_g[i]/=size;
	}
	#undef fftfor
	#undef fft
	#undef id
	#undef cover
}fft;
