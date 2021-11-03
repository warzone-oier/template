#pragma once
#include"../template.h"
template<word size>
struct bigint{
	byte num[size];
	inline bigint(){}
	inline bigint(const bigint &p)=default;
	inline bigint(ull in){
		memset(num,0,sizeof(num));
		for(word i=0;i<size&&in;++i)
			num[i]=in/100,in%=100;
	}
	
	//高精与低精运算（均为 O(n)）
	inline ll operator+=(ll in){
		for(word i=0;i<size&&in;++i){
			if(in+=num[i],in>=0) num[i]=in%100,in/=100;
			else if((-in)%100==0) num[i]=0,in/=100;
			else num[i]=100-((-in)%100),in=-((-in)/100+1);
		}
		return in;
	}
	inline bigint operator+(const ll in)const{
		bigint ans=*this;
		return ans+=in,ans;
	}
	inline ll operator-=(const ll in){return *this+=-in;}
	inline bigint operator-(const ll in)const{
		bigint ans=*this;
		return ans+=-in,ans;
	}
	inline ull operator*=(const ull in){
		ull out=0;
		for(word i=0;i<size;++i){
			out+=in*num[i];
			num[i]=out%100,out/=100;
		}
		return out;
	}
	inline bigint operator*(const ull in)const{
		bigint ans=*this;
		return ans*=in,ans;
	}
	inline ull operator/=(const ull mod){
		ull out=0;
		for(int i=size-1;i>=0;--i){
			out=out*100+num[i];
			num[i]=out/mod,out%=mod;
		}
		return out;
	}
	inline bigint operator/(const ull in)const{
		bigint ans=*this;
		return ans/=in,ans;
	}
	inline ull operator%(const ull mod)const{
		ull out=0;
		for(int i=size-1;i>=0;--i)
			out=(out*100+num[i])%mod;
		return out;
	}
	inline void operator%=(const ull mod){*this=*this%mod;}
	//高精与高精线性运算（O(n)）
	inline word operator+=(const bigint &p){
		word out=0;
		for(word i=0;i<size;++i){
			out+=num[i]+p.num[i];
			num[i]=out/100,out%=100;
		}
		return out;
	}
	inline bigint operator+(bigint p)const{return p+=*this;}
	inline int operator-=(const bigint &p){
		int out=0;
		for(word i=0;i<size;++i){
			out+=(int)(num[i])-p.num[i];
			if(out+=num[i],out>=0) num[i]=out%100,out/=100;
			else if((-out)%100==0) num[i]=0,out/=100;
			else num[i]=100-((-out)%100),out=-((-out)/100+1);
		}
		return out;
	}
	inline bigint operator-(const bigint &p)const{
		bigint ans=*this;
		return ans-=p,ans;
	}
	//高精与高精非线性运算（O(nlog n)）
	bigint<size> operator*(const bigint<size> &p)const;
	bigint<size> operator/(const bigint<size> &p)const;
	inline void operator*=(const bigint &p)const{*this=*this*p;}
	inline void operator/=(const bigint &p)const{*this=*this/p;}
};