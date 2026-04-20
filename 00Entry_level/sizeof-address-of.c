#include<stdio.h>
int main(void)
{
    /* sizeof
    是一个运算符，给出某个类型或者变量在内存中所占据的字节数
    sizeof(int)
    sizeof(i)
    */
    int a;
    a = 6;
    printf("sizeof(int)=%ld\n", sizeof(int));
    printf("sizeof(float)=%ld\n", sizeof(float));
    printf("sizeof(double)=%ld\n", sizeof(double));
    printf("sizeof(a)=%ld\n", sizeof(a));

    //运算符&(跟+-*/一样),获得变量的地址，它的操作对象必须是变量
    int i = 0;
    printf("0x%lx\n", &i); //%x输出16进制，会截断高位用%lx，但是有warning，因为想让printf输出那个地址，应该用%p
    printf("%p\n", &i);
    //地址和整数并不是完全相同的，要看你的架构

    
    return 0;
}
