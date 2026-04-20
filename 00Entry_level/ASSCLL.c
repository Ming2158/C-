#include<stdio.h>
int main(void)
{
    /*
    character->char是一种整数，也是一种字符类型：字符。
    这是因为：
    用单引号表示的字符字面量：'a','1'
    ''也是一个字符
    printf和scanf里面用 %c 来输入输出字符
    */
    char c;
    char d;
    c = 1;
    d = '1';
    if ( c == d ) {
        printf("相等\n");
    } else {
        printf("不想等\n");
    }
    printf("c=%d\n", c);
    printf("d=%d\n", d);
    char a;
    printf("请输入a的值:");
    scanf("%c", &a);//scanf读%d，不能处理char变量
    printf("a=%d\n", a);
    printf("a='%c'\n", a);

    //ASCLL码
    if (d == 49)
    {
        printf("OK\n");
    }

    //字符运算
    char e = 'A';
    e++;
    printf("e=%c\n", e);
    printf("'Z' - 'A' = %d\n", 'Z'-'A');

    //字母在ASCLL码中顺序排列，但是大小写字母不在一起
    //大小写转换
    printf("'a'到'A'的距离为:%d\n", 'a' - 'A');
    printf("'b'到'B'的距离为:%d\n", 'b' - 'B');
    char upercase;
    char lowercase;
    printf("请输入一个大写字母和一个小写字母:");
    scanf(" %c %c", &upercase, &lowercase);//在第一个%c前加上空格，无视所有残留空白。否则第一个%C可能读的不是scanf输入的字母，而是空格或换航\n
    printf("大写转小写:%c\n", upercase + 'a' - 'A');
    printf("小写转大写:%c\n", lowercase - ('a' - 'A'));
    return 0;
}
