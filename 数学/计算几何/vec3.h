#ifndef VEC3_H
#define VEC3_H
#include<math.h>
#include"../../template.h"

template<typename type=int,
	typename ltype=ll,typename dtype=db>
struct vector{
	type x,y,z;
	inline vector(){}
	inline vector(const vector &p)=default;
	inline vector(const type &X,const type &Y,const type& Z):x(X),y(Y),z(Z){};
	inline bool operator==(const vector &p)const{
		return x==p.x&&y==p.y&&z==p.z;}
	inline bool operator!=(const vector &p)const{
		return x!=p.x||y!=p.y||z!=p.z;}
	inline vector operator-()
		const{return vector(-x,-y,-z);}
	inline vector operator+()const{return *this;}
	//相等和相反
	inline vector operator+(const vector &p)
		const{return vector(x+p.x,y+p.y,z+p.z);}
	inline vector operator-(const vector &p)
		const{return vector(x-p.x,y-p.y,z-p.z);}
	inline vector operator*(dtype num)
		const{return vector(x*num,y*num,z*num);}
	inline vector operator/(dtype num)
		const{return vector(x/num,y/num,z/num);}
	//线性运算
	inline void operator+=(const vector &p){x+=p.x,y+=p.y,z+=p.z;}
	inline void operator-=(const vector &p){x-=p.x,y-=p.y,z-=p.z;}
	inline void operator*=(dtype num){x*=num,y*=num,z*=num;}
	inline void operator/=(dtype num){x/=num,y/=num,z/=num;}
	//线性自运算
	inline ltype operator*(const vector &p)
		const{return (ltype)(x)*p.x+(ltype)(y)*p.y+(ltype)(z)*p.z;}
	inline vector operator^(const vector &p)const{return vector(
		(ltype)(y)*p.z-(ltype)(z)*p.y,
		(ltype)(z)*p.x-(ltype)(x)*p.z,
		(ltype)(x)*p.y-(ltype)(y)*p.x);}
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
	inline matrix(const vec &X,const vec &Y,const vec &Z):base(X,Y,Z){}
	inline matrix(const type& xx,const type& xy,const type &xz,
				  const type& yx,const type& yy,const type &yz,
				  const type& zx,const type& zy,const type &zz):
				  base(vec(xx,yx,zx),vec(xy,yy,zy),vec(xz,yz,zz)){}
	inline vec operator()(const vec &p)const{//矩阵乘向量（线性变换）
		return base::x*p.x+base::y*p.y+base::z*p.z;}
	inline matrix operator()(const matrix &p)const{//矩阵乘法（线性变换复合）
		return matrix((*this)(p.x),(*this)(p.y),(*this)(p.z));}
	inline ltype det()const{return base::x*(base::y^base::z);}//行列式（向量复合积）
	inline matrix T()const{return matrix(//转置
		base::x.x,base::x.y,base::x.z,
		base::y.x,base::y.y,base::y.z,
		base::z.x,base::z.y,base::z.z);}
	inline matrix _1()const{//逆矩阵
		return matrix(base(
			base::y^base::z,
			base::z^base::x,
			base::x^base::y)/det()).T();}
	
};
#endif