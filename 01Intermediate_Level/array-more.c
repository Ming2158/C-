#include<stdio.h>
int main(void)
{
    int i,length;
    //数组的集成初始化
    int a [] = {2,4,6,7,2,3,5,9,11,13,23,14,32};

    //初始化每个元素为0
    int count[10];
    for ( i =0; i <length; i++) {
        count[i] = 0;
    }

    //不遍历，让数组中每个书为0
    int b [12] = {0};
    for ( i =0; i<12; i++ ) {
        printf("%d\t", b[i]);
    }
    printf("\n");

    //给数组中指定位置赋值
    int c [12] = { [1]=2,4,[5]=6, };
    printf("%d\n", c [5]);
    for ( i =0; i<12; i++ ) {
        //报错，索引问题，不用深入纠结，这种写法仅限C99或更高级编译器
        //printf("%d\t", c[i]);
    }

    //你有一个数组，求这个数组有几个单元
    int num = 0;
    num = sizeof(a)/sizeof(a[0]);//可以直接背下来记住
    printf("这个数组有%d个单元。\n", num);

    //遍历数组做赋值
    for( i =0; i <length; i++ ) {
        b[i] = a[i];
    }

    //数组中找到特定的number
    int key,ret;
    for ( i =0; i < count; i++) {
        if ( a[i] == key ) {
            ret = i;
            break;//跳出循环
        }
    }
    return 0;
}
