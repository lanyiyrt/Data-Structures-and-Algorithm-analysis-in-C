//这是在CSDN上看到的一个答案
//目前看不懂，等过一段时间在过来看看，现在现在这里备注一下。
#include<stdio.h>  
#include<math.h>  
#include"Polynomial.h"  
#define MAXN 1000  
  
Polynomial PowersOfXO[MAXN];  
  
int main() {  
    int  p, cnt, i;  
    Polynomial ans = creatPolynomial();  
    Polynomial fx = creatPolynomial();  
    ElementType e;  
    e.Coefficient = 1;  
    e.Exponent = 0;  
    Insert(e, ans.list);  
    inputPolynomial(fx);  
    scanf("%d", &p);  
    cnt = (int)log2(p);  
    PowersOfXO[0].list = fx.list;  
    for (i = 1; i <= cnt; i++){  
         PowersOfXO[i] = creatPolynomial();  
         MulPolynomial( PowersOfXO[i - 1] , PowersOfXO[i - 1], PowersOfXO[i]);  
    }  
    i = 0;  
    while (p > 0) {//将n转换为2进制，如果为1乘  
        if (p % 2 == 1) {  
            Polynomial temp = creatPolynomial();  
            MulPolynomial(ans, PowersOfXO[i], temp);  
            ans.list = temp.list;  
        }  
        i++;  
        p /= 2;  
    }  
    printAll(ans);  
} 
