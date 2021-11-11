#ifndef NTT_H
#ifndef FFT_H
#define FFT_H
#include<cmath>
#include"fftdef.h"
#include"complex.h"
namespace FFT{
	complex root[1<<mx],inv[1<<mx],eax[1<<mx],ebx[1<<mx];
	struct FFTINIT{
		inline FFTINIT(){
			root[1u<<mx_].real=inv[1u<<mx_].real=1;
			const db PI=acos(-1.0)/(1<<mx_);
			for(word i=1;i<1u<<mx_;++i){
				root[1u<<mx_|i]=complex(cos(i*PI),sin(i*PI));
				inv[1u<<mx_|i]=complex(root[1u<<mx_|i].real,-root[1u<<mx_|i].imag);
			}
			for(word i=(1u<<mx_)-1;i;--i)
				root[i]=root[i<<1],inv[i]=inv[i<<1];
		}
	}fftinit;
	#define fft(f,root) [&](){						\
		complex num1=f[head|i|floor]*root[i|floor];	\
		f[head|i|floor]=f[head|i];					\
		f[head|i]+=num1,f[head|i|floor]-=num1;}()
	#define cover(eax,ecx,edx,size)(				\
		num1=eax[i]+eax[((size)-i)&~(size)],		\
		num2=eax[i]-eax[((size)-i)&~(size)],		\
		ecx[i]=complex(num1.real/2,num2.imag/2),	\
		edx[i]=complex(num1.imag/2,num2.real/-2))
	struct fftreg{
		complex ecx[1<<mx],edx[1<<mx];
		inline void operator()(const word size,const word *const f){
			FOR(size>>1){
				eax[id(size,i)]=complex(f[i]>>15,f[i]&0x7fff);
				eax[id(size,size>>1|i)]=0;
			}
			fftfor(size) fft(eax,root);
			complex num1,num2;
			FOR(size) cover(eax,ecx,edx,size);
		}
	};
	inline void conv(const word size,const fftreg &f,
		const fftreg &g,word *const f_times_g){
		complex num1(0,1);
		FOR(size){
			eax[id(size,i)]=f.ecx[i]*g.ecx[i]+f.edx[i]*g.edx[i]*num1;
			ebx[id(size,i)]=f.ecx[i]*g.edx[i]+f.edx[i]*g.ecx[i]*num1;
		}
		fftfor(size) fft(eax,inv),fft(ebx,inv);
		const word head=(1u<<15)%mod;
		FOR(size){
			ull out=(ull)(eax[i].real/size+0.5)%mod;
			out=(ull)(ebx[i].real/size+0.5)%mod+out%mod*head%mod;
			out=(ull)(ebx[i].imag/size+0.5)%mod+out%mod;
			out=(ull)(eax[i].imag/size+0.5)%mod+out%mod*head%mod;
			f_times_g[i]=out%mod;
		}
	}
}
using FFT::fftreg;
using FFT::conv;
#endif
#endif