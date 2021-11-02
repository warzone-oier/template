#ifndef MATRIX_H
#define MATRIX_H
#include"../../../template.h"
template<word msize,word nsize>
struct matrix{
	db num[msize][nsize];
	inline matrix(){}
	inline matrix(const matrix&p){
		memset(num,p.num,sizeof(num));}
	inline db* operator[](word id){return num[id];}
	inline matrix& operator+=(const matrix& p){
		for(register word i=0;i<msize;++i)
			for(register word j=0;j<nsize;++j)
				num[i][j]+=p[i][j];
		return *this;
	}
	inline matrix& operator-=(const matrix&p){
		for(register word i=0;i<msize;++i)
			for(register word j=0;j<nsize;++j)
				num[i][j]-=p[i][j];
		return *this;
	}
	inline matrix& operator*=(db k){
		for(register word i=0;i<msize;++i)
			for(register word j=0;j<nsize;++j)
				num[i][j]*=k;
	}
	template<word lsize>
	inline matrix<msize,lsize> operator*
		(const matrix<nsize,lsize>&p){
			matrix<msize,lsize> out;
			register db ans;
			for(register word i=0;i<msize;++i)
				for(register word j=0;j<lsize;++j){
					for(register word k=ans=0;k<nsize;++k)
						ans+=num[i][k]*p.num[k][j];
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
	inline db& operator[](word id){
		return matrix<size,1>::num[id][0];}
	inline db operator *(const vector& p){
		register db out=0;
		for(register word i=0;i<size;++i)
			out+=(*this)[i]*p[i];
		return out;
	}
};
db A[600][600],B[600][600];
#endif