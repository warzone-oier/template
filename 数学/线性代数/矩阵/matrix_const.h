#ifndef MATRIX_H
#define MATRIX_H
#include"../../../template.h"
const word mod=998244353;
inline ull pow(register ull a,register word b){
	register ull ans=1;
	for(;b;b>>=1){
		if(b&1) (ans*=a)%=mod;
		(a*=a)%=mod;
	}
	return ans;
}
template<word msize,word nsize>
struct matrix{
	word num[msize][nsize];
	inline matrix(){}
	inline matrix(const matrix&p){
		memset(num,p.num,sizeof(num));}
	inline word* operator[](word id){return num[id];}
	inline matrix& operator+=(const matrix& p){
		for(register word i=0;i<msize;++i)
			for(register word j=0;j<nsize;++j)
				if((num[i][j]+=p[i][j])>=mod)
					num[i][j]-=mod;
		return *this;
	}
	inline matrix& operator-=(const matrix&p){
		for(register word i=0;i<msize;++i)
			for(register word j=0;j<nsize;++j)
				if((num[i][j]+=mod-p[i][j])>=mod)
					num[i][j]-=mod;
		return *this;
	}
	inline matrix& operator*=(register ull k){
		for(register word i=0;i<msize;++i)
			for(register word j=0;j<nsize;++j)
				num[i][j]=k*num[i][j]%mod;
	}
	template<word lsize>
	inline matrix<msize,lsize> operator*
		(const matrix<nsize,lsize>&p){
			matrix<msize,lsize> out;
			register ull ans;
			for(register word i=0;i<msize;++i)
				for(register word j=0;j<lsize;++j){
					for(register word k=ans=0;k<nsize;++k){
						ans+=(ull)(num[i][k])*p.num[k][j]%mod;
						if(ans>=mod) ans-=mod;
					}
					out[i][j]=ans;
				}
			return out;
		}
};
template<word size>
struct vector: public matrix<size,1>{
	template<typename type>
	inline vector(const type &p){
		memcpy(matrix<size,1>::num,p.num,
			sizeof(matrix<size,1>::num));}
	inline word& operator[](word id){
		return matrix<size,1>::num[id][0];}
	inline ull operator *(const vector& p){
		register ull out=0;
		for(register ull i=0;i<size;++i){
			out+=(ull)((*this)[i])*p[i]%mod;
			if(out>=mod) out-=mod;
		}
		return out;
	}
};
//计算 A 的逆矩阵，若有放入 B，若没有则 B 的值不确定
//返回 A 的行列式，A 处理后的值不确定
template<typename type>
inline ull _1(type &A,type &B,register word size){
	register ull ans=1,get;
	for(register word i=0;i<size;++i){
		if(A[i][i]==0){
			for(register word j=i+1;j<size;++j) if(A[j][i]){
				for(register word k=0;k<size;++k){
					if((A[i][k]+=A[j][k])>=mod) A[i][k]-=mod;
					if((B[i][k]+=B[j][k])>=mod) B[i][k]-=mod;
				}
				break;
			}
			if(A[i][i]==0) return 0;
		}
		if(A[i][i]!=1){
			ans=ans*A[i][i]%mod;
			get=pow(A[i][i],mod-2);
			for(register word k=0;k<size;++k){
				A[i][k]=get*A[i][k]%mod;
				B[i][k]=get*B[i][k]%mod;
			}
		}
		for(register word j=0;j<size;++j)
			if(j!=i&&(get=A[j][i])){
				get=mod-get;
				for(register word k=0;k<size;++k){
					if((A[j][k]+=get*A[i][k]%mod)>=mod) A[j][k]-=mod;
					if((B[j][k]+=get*B[i][k]%mod)>=mod) B[j][k]-=mod;
				}
			}
	}
	return ans;
}
//较快速地计算 A 的行列式，A 处理后的值不确定
template<typename type>
inline ull det(type &A,register word size){
	register ull ans=1,get;
	for(register word i=0;i<size;++i){
		register word j=i+1;
		if(A[i][i]==0){
			for(;j<size;++j) if(A[j][i]){
				for(register word k=i;k<size;++k)
					if((A[i][k]+=A[j][k])>=mod) A[i][k]-=mod;
				break;
			}
			if(A[i][i]==0) return 0;
		}
		if(A[i][i]!=1){
			ans=ans*A[i][i]%mod;
			get=pow(A[i][i],mod-2);
			for(register word k=i;k<size;++k)
				A[i][k]=get*A[i][k]%mod;
		}
		for(;j<size;++j) if(get=A[j][i]){
			get=mod-A[j][i];
			for(register word k=i;k<size;++k)
				if((A[j][k]+=get*A[i][k]%mod)>=mod) A[j][k]-=mod;
		}
	}
	return ans;
}
//计算 A 的秩，A 处理后的值不确定
template<typename type>
inline word rank(type &A,register word line,register word column){
	register ull get;
	register word swap=column,i;
	for(i=0;i<line&&i<column;++i){
		register word j=i+1;
		while(A[i][i]==0){
			for(j=i+1;j<line;++j) if(A[j][i]){
				for(register word k=i;k<column;++k)
					if((A[i][k]+=A[j][k])>=mod) A[i][k]-=mod;
				break;
			}
			if(A[i][i]==0){
				if(--swap<=i) return i;
				for(j=i;j<line;++j)
					get=A[j][i],A[j][i]=A[j][swap],A[j][swap]=get;
			}
		}
		if(A[i][i]!=1){
			get=pow(A[i][i],mod-2);
			for(register word k=i;k<column;++k)
				A[i][k]=get*A[i][k]%mod;
		}
		for(;j<line;++j) if(get=A[j][i]){
			get=mod-A[j][i];
			for(register word k=i;k<column;++k)
				if((A[j][k]+=get*A[i][k]%mod)>=mod) A[j][k]-=mod;
		}
	}
	return i;
}
template<typename type0,typename type1>
inline ull gauss(type0 &A,type1 &B,
	register word size,register word bsize){
	register ull ans=1,get;
	for(register word i=0;i<size;++i){
		if(A[i][i]==0){
			for(register word j=i+1;j<size;++j)
				if(A[j][i]){
					for(register word k=i;k<size;++k)
						if((A[i][k]+=A[j][k])>=mod) A[i][k]-=mod;
					for(register word k=0;k<bsize;++k)
						if((B[i][k]+=B[j][k])>=mod) B[i][k]-=mod;
					break;
				}
			if(A[i][i]==0) return 0;
		}
		if(A[i][i]!=1){
			ans=ans*A[i][i]%mod;
			get=pow(A[i][i],mod-2);
			for(register word k=i;k<size;++k)
				A[i][k]=get*A[i][k]%mod;
			for(register word k=0;k<bsize;++k)
				B[i][k]=get*B[i][k]%mod;
		}
		for(register word j=0;j<size;++j)
			if(j!=i&&(get=A[j][i])){
				get=mod-A[j][i];
				for(register word k=i;k<size;++k)
					if((A[j][k]+=get*A[i][k]%mod)>=mod) A[j][k]-=mod;
				for(register word k=0;k<bsize;++k)
					if((B[j][k]+=get*B[i][k]%mod)>=mod) B[j][k]-=mod;
			}
	}
	return ans;
}
#endif