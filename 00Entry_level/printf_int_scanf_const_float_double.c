#include <stdio.h>
int main() {
    printf("Hello World\n");
    printf("\n");
/*
printf, is a standard library function in C that is used to print formatted output to the console. In this code, it is used to print the string "Hello World" followed by a newline character.
*/

    printf("   *\n");
    printf("  * *\n");
    printf(" * * *\n");
    printf("* * * *\n");
    printf("\n");
/*
\n, is a newline character, which moves the cursor to the next line after printing "Hello World". This ensures that any subsequent output will appear on a new line.
*/

    printf("123 + 111 = %d \n",123 + 111);
    printf("123 - 111 = %d \n",123 - 111);
    printf("12 x 12 = %d \n",12 * 12);
    printf("36 ÷ 12 = %d \n",36 / 12);
    printf("40 取余 12 %d \n",40 % 12);//printf 中文出现乱码，将编码格式改为Simplified Chinese (GB 2312)即可
    printf("(1 + 1) x 2 = %d \n",(1 + 1) * 2);
    printf("\n");
/*
运算符优先级：
在C语言中，运算符的优先级决定了表达式中各个运算符的计算顺序。
括号()具有最高的优先级，因此在表达式(1 + 1) * 2中，首先计算括号内的1 + 1，得到2，然后再将结果乘以2，最终得到4。
*/

    int m = 1 , n = 1;
    printf("%d %d \n",m,n);
    int a, b; //没赋值输出的初始值是变化的，垃圾值
    printf("%d %d \n",a,b);
    int num_1_test = 9;
    printf("%d \n",num_1_test);
    int change_0 = 100 - m;
    printf("%d \n",change_0);//C99写法:允许任何地方定义变量
    printf("\n");
/*
定义一个变量 int a = 0； 变量名是a 类型是int 初始值为 0
变量定义：int price; 
int price,amount;   变量用逗号隔开
int price = 1 , amount = 1;
变量本质————标识符：字母、数字（不可在开头）、下划线_ 、组成
赋值是"动态"的区别数学角度
*/

    printf("欢迎使用百元找零计算器! \n");//printf 中文出现乱码，将编码格式改为Simplified Chinese (GB 2312)即可
    int price = 0;
    printf("输入您的金额(元):"); 
    scanf("%d",&price);
    printf("%d \n",price);
    int change_1 = 100 - price;
    printf("找您%d(元) \n",change_1);
    printf("\n");
/*
scanf, is a standard library function in C that is used to read formatted input from the console. In this code, it is used to read an integer value from the user and store it in the variable price. The %d format specifier indicates that the input should be interpreted as an integer, and the & operator is used to pass the address of the variable price to scanf so that it can store the input value there.
int a = 0;
int b = 0;
scanf("%d,%d", &a, &b);
scanf("%d %d", &a, &b);
scanf("price%d %d", &a, &b);
printf("%d %d \n", a, b);
*/

    const int AMOUNT = 100;
    printf("\n");

/*
不要 magic number 比如 int change = 100 - price;
这100很神奇的就出现了  
const 是一个修饰符，加在int 前面，用来给这个变量加上一个const（不变的）的属性。
这个const属性就表示这个变量的值一旦初始化，就不能修改了。
int change = AMOUNT - price; 如果你试图对常量做修改，会报错！！！
*/
    float pi = 3.1415926;
    double e = 2.718281828;
    printf("%f \n",10.0/3); //默认小数后面6位
    printf("%.1f \n",10.0/3);
    printf("%.2f \n",10.0/3);
    printf("%.3f \n",10.0/3);
    printf("%0.4f \n",10.0/3);
    printf("%0.5f \n",10.0/3);
    printf("%0.6f \n",10.0/3);
    printf("%0.7f \n",10.0/3);
    printf("\n");
/*
%f 告诉scanf函数在所传地址位置上存储一个 float型值
%lf 告诉scanf函数在所传地址位置上存储一个 double型值
对编译器来说，在printf()函数中占位符 %f和%lf是等价的，都是double的占位符
%m.nf : 输出浮点数，m 为占据字符宽度(几位小数)
*/

    printf("注意运算优先级，不要嵌入式赋值！ \n");
    printf("\n");
/*
+ 单目不变 自右向左 eg. a * +b  (a乘以正b)
- 单目取负 自右向左 eg. a * -b  (a乘以负b)
= 赋值 自右向左 eg。 a = b = c (先算c=b,再算b=a)
*/

    int x = 10;
    printf("x = %d \n", x);
    printf("x++ = %d \n", x++);
    printf("++x = %d \n", ++x);
    printf("x = %d \n", x); 0;
    printf("\n");
/*
复合赋值：5个算数运算符，+ - * / %,可以和赋值运算符“=”结合起来。
形成复合赋值运算符：+=、-=、*=、/=、%=   注意两个之间不能有空格
eg. total += 5;  total = total + 5;
递增递减：++、--可以放在变量前面或后面，++a ，a++。
前后“结果”不一样：a++ 先使用a的值，再对a进行递增；++a 先对a进行递增，再使用a的值。
*/
    return 0;
}
