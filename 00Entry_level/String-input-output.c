#include<stdio.h>
int main(void)
{
    /*
    字符串的输入输出%s
    安全的输入：
    %s %7s,控制数量

    char string[8];
    scanf("%s", string);
    printf("%s", string);
    scanf读入一个单词，知道识别到空格、tab、回车为止
    */
    char string[8];
    scanf("%s", string);//不用&，因为string是数组，就是一个指针
    printf("%s##\n", string);   

    /*
    常见错误
    char *string;
    scanf("%s", string);
    以为char*就是字符串类型，定义了一个字符串类型的变量string就可以用了
    由于string没有初始化为0，所以每一次运行不一定出错
    空字符串
    char buffer[100] = "";
    这是一个空的字符串，buffer[0] = \0
    */
    char str[100];  // 数组在栈上分配了100字节的内存
    char *string_1 = str;  // 指针指向数组的首地址（初始化）
    
    printf("请输入字符串：");
    scanf("%s", string_1);  // 正确，string_1指向有效的内存
    
    printf("你输入的是：%s\n", string_1);
    return 0;
}
