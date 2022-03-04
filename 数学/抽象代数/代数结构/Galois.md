## 对称多项式与韦达定理

对于 $n$ 元多项式 $f(x_1,x_2,\cdots,x_n)$，若任意交换 $x_1,x_2,\cdots,x_n$ 的位置，  
$f(x_1,x_2,\cdots,x_n)$ 不改变，则称 $f$ 为关于 $x_1,x_2,\cdots,x_n$ 的**对称多项式**。

易发现，对称多项式的每一个单项式等价类相当于将 $n$ 个相同的球  
放进无数个盒子里的一个方案。

根据因式分解与一元 $n$ 次方程的关系，  
对于一元 $n$ 次方程 $x^n+p_1x+p_2x+\cdots+p_n=0$  
的解 $x_1,x_2,\cdots,x_n$，有韦达定理

$$
\begin{cases}
	\displaystyle\sum_{1\le a_1\le n} x_{a_1}=-p_1  \\
	\displaystyle\sum_{1\le a_1<a_2\le n} x_{a_1}x_{a_2}=p_2\\
	\displaystyle\sum_{1\le a_1<a_2<a_3\le n} x_{a_1}x_{a_2}x_{a_3}=-p_3\\
	\cdots\\
	\displaystyle x_1x_2\cdots x_n=(-1)^np_n
\end{cases}
$$
易发现，等式的左边都是关于 $x_1,x_2,\cdots,x_n$ 的对称多项式，  
它们被称为**初等对称多项式**，记为 $\sigma_1,\sigma_2,\cdots,\sigma_n$。

### 性质
- 若干对称多项式之积的线性组合仍是对称多项式。（显然）
- 对称多项式基本定理：  
  任意对称多项式都能唯一分解为若干初等对称多项式之积的线性组合。  
  证明：对于 $n$ 元对称多项式 $f$，将其所有单项式等价类排序    
	（先按各元总次数从大到小排序，相同则按最大次数从大到小排序，  
	  又相同则按次大次数从大到小排序...以此类推）

  设其排序后第一个单项式等价类为 
	$$a\sum_{p}\prod_k x_{p_k}^{l_k}\quad(l_1\le l_2\le\cdots\le l_n)$$
	设 $l_0=0$，显然其等于
	$$a\sum_{p}\prod_{k}\left(\prod_{i=1}^k x_{p_k}\right)^{l_k-l_{k-1}}$$
    于是构造对称多项式 $a\prod_k\sigma_k^{l_k-l_{k-1}}$，显然其排序后第一个单项式等价类与 $f$ 相同  
	（乘 $\sigma_k$ 相当于任选 $k$ 个球移动到下一个盒子里，贪心可唯一确定序最大的方案）  
	将 $f$ 减去 $a\prod_k\sigma_k^{l_k-l_{k-1}}$，其最靠前的单项式等价类的序减小。  
	机械重复该过程，即可把 $f$ 唯一分解为初等对称多项式之积的线性组合。

## 预解式与预解方程

拉格朗日指出，求解一元 $n$ 次方程的过程，本质上是在破坏韦达定理中根的对称性。

对于一元 $n$ 次方程 $x^n+p_1x^{n-1}+p_2x^{n-2}+\cdots+p_n=0$ 的 $n$ 个根 $x_1,x_2,\cdots,x_n$，  
定义**预解式**为 $n$ 元置换到 $x_1,x_2,\cdots,x_n$ 的**非对称**多项式函数

$$u(\tau)=f(x_{\tau_1},x_{\tau_2},\cdots,x_{\tau_n})$$


预解式有如下性质：

对于所有的 $n$ 元置换 $\tau_1,\tau_2,\cdots,\tau_{n!}$，  
关于 $u(\tau_1),u(\tau_2),\cdots,u(\tau_{n!})$ 的对称多项式同时也是关于 $x_1,x_2,\cdots,x_n$ 的对称多项式。

在此基础上，定义**预解方程**为关于 $y$ 的方程

$$(y-u(\tau_1))(y-u(\tau_2))\cdots(y-u(\tau_{n!}))=0$$

根据韦达定理，该方程的系数为关于 $u(\tau_1),u(\tau_2),\cdots,u(\tau_{n!})$ 的基本对称多项式，  
也就同时是关于 $x_1,x_2,\cdots,x_n$ 的对称多项式，可以用 关于 $x_1,x_2,\cdots,x_n$ 的  
初等对称多项式，即原方程的系数 $p_1,p_2,\cdots,p_n$ 机械地唯一表示出来。

若预解式在根的置换下发生改变，求出预解方程的解就得知了  
原先的 $n$ 个根的一个**非对称**的关系，从而破坏根的对称性，化为低次方程。

预解方程看似次数比原方程大得多，但是：
- $u(\tau)$ 可能仍有一定的对称性，导致辅助方程有许多重根。
- 若使 $u^k(\tau)$ 具有对称性，可以求出 $u^k(\tau)$ 后开方得到 $u(\tau)$。

## 二次、三次、四次方程解法

### 二次方程解法
对于一元二次方程

$$x^2-ax+b=0$$

其有两个根 $x_1,x_2$，满足韦达定理

$$\begin{cases}
	x_1+x_2=a\\
	x_1x_2=b
\end{cases}$$

考虑预解式 $u(\tau)=x_{\tau_1}-x_{\tau_2}$，其有两个不同的取值

$$u\begin{pmatrix}1 &2\\1 &2\end{pmatrix}=x_1-x_2=p,\\
u\begin{pmatrix}1 &2\\2 &1\end{pmatrix}=x_2-x_1=-p$$

显然，$u^2(\tau)$ 具有对称性

$$u^2(\tau)=p^2$$

于是对于预解方程

$$(y+p)(y-p)=y^2-p^2=0$$

我们可以将 $p^2$ 唯一分解为 $x_1,x_2$ 的初等对称多项式

$$p^2=(x_1-x_2)^2=(x_1+x_2)^2-4x_1x_2$$

代入 $p^2=a^2-4b$ 即可解出

$$y^2=a^2-4b$$

由此我们知道了非对称关系 $x_1-x_2=\sqrt{a^2-4b}$，与对称关系 $x_1+x_2=a$ 联立，

即可解出 $x_1=\dfrac{-a+\sqrt{a^2-4b}}{2},x_2=\dfrac{-a-\sqrt{a^2-4b}}{2}$

### 三次方程解法

对于一元三次方程

$$x^3-ax^2+bx-c=0$$

其有三个根 $x_1,x_2,x_3$，满足韦达定理

$$\begin{cases}
	x_1+x_2+x_3=a\\
	x_1x_2+x_1x_3+x_2x_3=b\\
	x_1x_2x_3=c
\end{cases}$$
考虑预解式 $u(\tau)=x_{\tau_1}+\omega x_{\tau_2}+\omega^2x_{\tau_3},\omega$ 为三次单位根，其有六个不同的取值

$$
u\begin{pmatrix}1&2&3\\1&2&3\end{pmatrix}=x_1+\omega x_2+\omega^2 x_3=p\\
u\begin{pmatrix}1&2&3\\3&1&2\end{pmatrix}=x_3+\omega x_1+\omega^2 x_2=\omega p\\
u\begin{pmatrix}1&2&3\\2&3&1\end{pmatrix}=x_2+\omega x_3+\omega^2 x_1=\omega^2 p\\
u\begin{pmatrix}1&2&3\\1&3&2\end{pmatrix}=x_1+\omega x_3+\omega^2 x_2=q\\
u\begin{pmatrix}1&2&3\\2&1&3\end{pmatrix}=x_2+\omega x_1+\omega^2 x_3=\omega q\\
u\begin{pmatrix}1&2&3\\3&2&1\end{pmatrix}=x_3+\omega x_2+\omega^2 x_1=\omega^2 q
$$

易发现，$u^3(\tau)$ 具有对称性

$$u^3\begin{pmatrix}1&2&3\\1&2&3\end{pmatrix}=u^3\begin{pmatrix}1&2&3\\3&1&2\end{pmatrix}=u^3\begin{pmatrix}1&2&3\\2&3&1\end{pmatrix}=p^3$$
$$u^3\begin{pmatrix}1&2&3\\1&3&2\end{pmatrix}=u^3\begin{pmatrix}1&2&3\\2&1&3\end{pmatrix}=u^3\begin{pmatrix}1&2&3\\3&2&1\end{pmatrix}=q^3$$
于是对于预解方程

$$(y^3-p^3)(y^3-q^3)=0$$

通过韦达定理，将预解方程的系数唯一分解为 $x_1,x_2,x_3$ 的初等对称多项式

$$
p^3+q^3=(x_1+\omega x_2+\omega^2 x_3)^3+(x_1+\omega^2x_2+\omega x^3)^3\\
=2(x_1+x_2+x_3)^3-9(x_1+x_2+x_3)(x_1x_2+x_1x_3+x_2x_3)+27x_1x_2x_3$$
$$
p^3q^3=(x_1+\omega x_2+\omega^2 x_3)^3(x_1+\omega^2x_2+\omega x^3)^3\\
=((x_1+x_2+x_3)^2-3(x_1x_2+x_1x_3+x_2x_3))^3
$$

代入 $p^3+q^3=2a^3-9ab+27c,p^3q^3=(a^2-3b)^3$，即可解出

$$y^3=\dfrac{(p^3+q^3)\pm\sqrt{(p^3+q^3)^2-4p^3q^3}}{2}$$

由此得知了 $x_1,x_2,x_3$ 的两个非对称关系
$$\begin{cases}
	x_1+\omega x_2+\omega^2 x_3=\sqrt[3]{\dfrac{(p^3+q^3)+\sqrt{(p^3+q^3)^2-4p^3q^3}}{2}}\\
	x_1+\omega^2 x_2+\omega x_3=\sqrt[3]{\dfrac{(p^3+q^3)-\sqrt{(p^3+q^3)^2-4p^3q^3}}{2}}
\end{cases}$$

与对称关系 $x_1+x_2+x_3=a$ 联立，即可解出 $x_1,x_2,x_3$ 。

### 四次方程解法

对于一元四次方程

$$x^4-ax^3+bx^2-cx+d=0$$

其有四个根 $x_1,x_2,x_3,x_4$，满足韦达定理

$$
\begin{cases}
	x_1+x_2+x_3+x_4=a\\
	x_1x_2+x_1x_3+x_1x_4+x_2x_3+x_2x_4+x_3x_4=b\\
	x_1x_2x_3+x_1x_2x_4+x_1x_3x_4+x_2x_3x_4=c\\
	x_1x_2x_3x_4=d
\end{cases}
$$

首先考虑预解式 $u(\tau)=x_{\tau_1}+ix_{\tau_2}-x_{\tau_3}-ix_{\tau_4}$，其在置换下有 $4! =24$ 种不同的取值。

发现尽管 $u^4(\tau)$ 具有对称性，但置换下不同的取值有六个，  

预解方程为六次，行不通。考虑保留一定的对称性，对于如下预解式

$$u(\tau)=x_{\tau_1}x_{\tau_2}+x_{\tau_3}x_{\tau_4}$$

其在根的置换下只有三种不同的取值：  
$p=x_1x_2+x_3x_4$，$q=x_1x_3+x_2x_4,r=x_1x_4+x_2x_3$，  
于是预解方程为
$$(y-p)^4(y-q)^4(y-r)^4=0$$
其本质上是个三次方程
$$(y-p)(y-q)(y-r)=0$$

通过韦达定理，可将其系数分解为 $x_1,x_2,x_3,x_4$ 的初等对称多项式

$$
\begin{cases}
p+q+r=b\\
pq+pr+qr=ac-4d\\
pqr=a^2d+c^2-4bd
\end{cases}
$$

代入解出 $y$，从而得知 $p,q,r$ 三个非对称关系。

与 对称关系 $x_1x_2x_3x_4=d$ 联立，求解一元二次方程，  
对称性被进一步破坏为 $x_1x_2,x_1x_3,x_1x_4,x_2x_3,x_2x_4,x_3x_4$。  
再与 $x_1x_2x_3+x_1x_2x_4+x_1x_3x_4+x_2x_3x_4=c$，从而解得 $x_1,x_2,x_3,x_4$。
