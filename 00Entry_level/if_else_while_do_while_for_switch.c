#include <stdio.h>
int main () {
    if (2 > 1)
    {
        printf("2 > 1 is true\n");
    }
    printf("\n");
/*
if\else\else if语句:  
    if ( 条件成立) {
        执行...
    }else if ( 条件成立) {
        执行...
    }else {
        执行...
    }
C语言提供了六个关系运算符:
== 相等
!= 不相等
> 大于
< 小于
>= 大于等于
<=  小于等于
(中间不可插入空格！)
*/

    printf("%d \n", 5 >3);
    printf("%d \n", 5 <=3);
    printf("\n");

/*
逻辑值：true真 1  或者  false假 0
*/

    int n = 5, m = 10;
    while ( n >0 ) {
        n--;
        printf("%d \n", n);
    }
    do {
        m--;
        printf("%d \n", m);
    } while (m > 0);
    printf("\n");
/*
    while (条件判断) {
    ...
    }
    do {
    ...
    } while (条件判断)

*/

    for (int i = 10; i > 0; i--) {
        printf("%d \n", i);
    }
    printf("\n");
/*
for循环： 
    for ( count =10; count >0; count--) {
    ...
    }
就读作：对于一开始的count=10，当count>0时，重复做循环体，每一轮循环在做完循环体内语句后，使count--
*/

    if ( 0 == 0 && 2 == 2 ) {
        /* if 中的等于，要用== */
        printf ("true \n");
    }
    printf("\n");
/*
逻辑运算
运算符
！ 逻辑“非” !a 如果a是ture结果就是false，如果a是false结果就是ture
&& 逻辑“与” a && b 如果a和b都是ture 结果就是ture，否则结果为false
|| 逻辑“或” a || b 如果a或b有一个结果为ture，结果为ture；两个false结果为false
优先级 ！> && > ||  
*/

    printf("输入你的分数： \n");
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    b=a/10;
    switch (b) {
        case 10:
        case 9:
        printf("A \n");
        break;
        case 8:
        printf("B \n");
        break;
        case 7:
        printf("C \n");
        break;
        case 6:
        printf("D \n");
        break;
        default:
        printf("E \n");
    }
    printf("\n");
/*
switch-case,多路分支
switch (控制表达式) {
case 常量:
    语句
    ...
case 常量:
    语句
    ...
default:
    语句
    ...
*/

    int y = 5;
    //int exit = 0;
    int one, two, five;
    //scanf ("input moneny: %d", &y);
    for ( one =1; one <y*10; one++ ) {
        for ( two =1; two <y*10/5; two++ ) {
            for ( five =1; five <y*10/5; five++ ) {
                if ( one +two*2 +five*5 ==y*5 ) {
                    printf("可以用%d个1角加%d个2角加%d个5角得到%d元。 \n", one, two, five, y);
                    goto out;
                    //exit = 1;
                   // break;
                }
                //if ( exit == 1 ) {
                //    break;
                //}
            }
            //if ( exit == 1 ) {
                //break;
            //}
        }
        //if ( exit == 1 ) {
            //break;
        //} 
    }
    out: printf("end \n");
    printf("\n");
/*
break,跳出循环。
goto out;
out:
*/
    return 0;
}