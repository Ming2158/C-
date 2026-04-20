#include<stdio.h>
void f(int *p);
int main (void) {
    int i = 6;
    printf("&i = %p \n", &i);
    printf("i = %d \n", i);
    f(&i);
    printf("i = %d \n", i);
/*
指针point，就是保存"地址"的变量
int i;
int* p = &i //p是一个指针，指向的是一个int，i的地址交给了这个p。
p指向i

int* p,q;
int *p,q;
*p是一个int，q是int。*加给力p，于是p是一个指针了。
int* p; //注意：没有int*这种类型
int *p,*q;

作为参数的指针
void f(int *p);
在被调用的时候得到了某个变量的地址：
int i=0; f(&i);
在函数里面可以通过这个指针访问外面的这个i

* 是一个单目运算符，用来访问指针的值所表示的地址上的变量
可以做左值也可以做右值
int k = *p;
*p = k + 1;
*/
    return 0;
}
void f(int *p) {
    printf("p = %p \n", p);
    printf("*p = %d \n", *p);
    *p = 10;//通过指针修改了外面i的值
}