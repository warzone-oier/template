#pragma once
#include"../../template.h"
struct complex{
	db real,imag;
	inline complex(){}
	inline complex(const complex& p){
		real=p.real,imag=p.imag;}
	inline complex(db a,db b=0):real(a),imag(b){}
	inline complex operator ~()const{
		return complex(real,-imag);}
	inline complex operator +(const complex &p)const{
		return complex(real+p.real,imag+p.imag);}
	inline complex operator -(const complex &p)const{
		return complex(real-p.real,imag-p.imag);}
	inline complex operator *(const complex &p)const{
		return complex(real*p.real-imag*p.imag,
			real*p.imag+imag*p.real);}
	inline void operator +=(const complex &p){
		real+=p.real,imag+=p.imag;}
	//FFT 必需的基本函数

	inline void operator-=(const complex &p){
		real-=p.real,imag-=p.imag;}
	inline void operator*=(const complex &p){
		(*this)=(*this)*p;}
	inline complex operator -()const{
		return complex(-real,-imag);}
	inline complex operator +(db num)const{
		return complex(real+num,imag);}
	inline complex operator -(db num)const{
		return complex(real-num,imag);}
	inline complex operator *(db num)const{
		return complex(real*num,imag*num);}
	inline complex operator /(db num)const{
		return complex(real/num,imag/num);}
	inline void operator+=(db num){real+=num;}
	inline void operator-=(db num){real-=num;}
	inline void operator*=(db num){real*=num,imag*=num;}
	inline void operator/=(db num){real/=num,imag/=num;}
	inline complex operator /(const complex &p)const{
		return (*this)*complex(p.real,-p.imag)
			/(p.real*p.real+p.imag*p.imag);}
	inline void operator /=(const complex &p){
		(*this)*=complex(p.real,-p.imag);
		(*this)/=(p.real*p.real+p.imag*p.imag);
	}
};