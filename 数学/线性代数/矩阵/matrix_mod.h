#ifndef MATRIX_H
#define MATRIX_H
#include"../../../template.h"
word mod;
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
template<typename type>
inline ull det(type &A,register word size){
	register ull ans=1,get;
	for(register word i=0;i<size;++i){
		for(register word j=i+1;j<size;++j)
			while(A[j][i]){
				if(A[i][i]>A[j][i]){
					get=mod-A[i][i]/A[j][i];
					for(register word k=i;k<size;++k)
						if((A[i][k]+=get*A[j][k]%mod)>=mod)
							A[i][k]-=mod;
				}
				if(A[i][i]==0){
					for(register word k=i;k<size;++k)
						get=A[i][k],A[i][k]=A[j][k],A[j][k]=get;
					if(ans) ans=mod-ans;
				}else{
					get=mod-A[j][i]/A[i][i];
					for(register word k=i;k<size;++k)
						if((A[j][k]+=get*A[i][k]%mod)>=mod)
							A[j][k]-=mod;
				}
			}
		if(A[i][i]==0) return 0;
		ans=ans*A[i][i]%mod;
	}
	return ans;
}
template<typename type>
inline word rank(type &A,register word line,register word column){
	register ull get;
	register word swap=column,i;
	for(i=0;i<line&&i<column;++i) do{
		for(register word j=i+1;j<line;++j) while(A[j][i]){
			if(A[i][i]>A[j][i]){
				get=mod-A[i][i]/A[j][i];
				for(register word k=i;k<column;++k)
					if((A[i][k]+=get*A[j][k]%mod)>=mod)
						A[i][k]-=mod;
			}
			if(A[i][i]==0){
				for(register word k=i;k<column;++k)
					get=A[i][k],A[i][k]=A[j][k],A[j][k]=get;
			}else{
				get=mod-A[j][i]/A[i][i];
				for(register word k=i;k<column;++k)
					if((A[j][k]+=get*A[i][k]%mod)>=mod)
						A[j][k]-=mod;
			}			
		}
		if(A[i][i]==0){
			if(--swap<=i) return i;
			for(register word j=0;j<line;++j)
				get=A[j][i],A[j][i]=A[j][swap],A[j][swap]=get;
		}
	}while(A[i][i]==0);
	return i;
}
#endif