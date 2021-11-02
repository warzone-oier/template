#ifndef VEC2_H
#define VEC2_H
#include<math.h>
#include"../../template.h"

template<typename type=int,
	typename ltype=ll,typename dtype=db>
struct vector{
	type x,y;
	inline vector(){}
	inline vector(const vector &p)=default;
	inline vector(const type &X,const type &Y):x(X),y(Y){};
	inline bool operator==(const vector &p){
		return x==p.x&&y==p.y;}
	inline bool operator!=(const vector &p){
		return x!=p.x||y!=p.y;}
	inline vector operator-()
		const{return vector(-x,-y);}
	inline vector operator+()const{return *this;}
	//相等和相反
	inline vector operator+(const vector &p)
		const{return vector(x+p.x,y+p.y);}
	inline vector operator-(const vector &p)
		const{return vector(x-p.x,y-p.y);}
	inline vector operator*(dtype num)
		const{return vector(x*num,y*num);}
	inline vector operator/(dtype num)
		const{return vector(x/num,y/num);}
	//线性运算
	inline void operator+=(const vector &p){x+=p.x,y+=p.y;}
	inline void operator-=(const vector &p){x-=p.x,y-=p.y;}
	inline void operator*=(dtype num){x*=num,y*=num;}
	inline void operator/=(dtype num){x/=num,y/=num;}
	//线性自运算
	inline ltype operator*(const vector &p)
		const{return (ltype)(x)*p.x+(ltype)(y)*p.y;}
	inline ltype operator^(const vector &p)
		const{return (ltype)(x)*p.y-(ltype)(y)*p.x;}
	inline dtype operator*(){return sqrt((*this)*(*this));}
	//非线性运算
};

template<typename type=int,
	typename ltype=ll,typename dtype=db>
struct matrix:vector<vector<type,ltype,dtype>,ltype,dtype>{
	typedef vector<type,ltype,dtype> vec;
	typedef vector<vec,ltype,dtype> base;
	inline matrix(){}
	inline matrix(const matrix &p)=default;
	inline matrix(const base &p):base(p){}
	inline matrix(const vec &X,const vec &Y):base(X,Y){}
	inline matrix(const type &a,const type &b,
				  const type &c,const type &d):
		base(vec(a,c),vec(b,d)){}
	inline vec operator()(const vec &p)const{//矩阵乘向量（线性变换）
		return base::x*p.x+base::y*p.y;}
	inline matrix operator()(const matrix &p)const{//矩阵乘法（线性变换复合）
		return matrix((*this)(p.x),(*this)(p.y));}
	inline ltype det()const{return base::x^base::y;}//行列式（叉积）
	inline matrix T()const{return matrix(//转置
		base::x.x,base::x.y,
		base::y.x,base::y.y);}
	inline matrix _1()const{return matrix(base(//逆矩阵
		vec(base::y.y,base::y.x),
		vec(base::x.y,base::x.x))/det());}
};
#endif