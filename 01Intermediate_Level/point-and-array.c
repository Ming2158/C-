#include <stdio.h>

int main() {
    int b[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = b; // b退化为首元素指针，赋值给p

    // 1. 地址数值相同，但类型不同
    printf("b = %p\n", b);       // 0x7ffe... 首元素地址
    printf("&b[0] = %p\n", &b[0]);// 0x7ffe... 和b数值完全一致
    printf("&b = %p\n", &b);     // 0x7ffe... 数值相同，但类型是int(*)[10]
    printf("p = %p\n", p);       // 0x7ffe... 和b数值一致

    // 2. sizeof 完全不同
    printf("sizeof(b) = %zu\n", sizeof(b)); // 40（10*4，64位系统）
    printf("sizeof(p) = %zu\n", sizeof(p)); // 8（指针大小）

    // 3. 自增操作
    // b++; // 编译报错：表达式必须是可修改的左值
    p++;   // 合法，p指向b[1]

    printf("==========================\n");


    // ==========================
    // 1. 字符指针 → 指向字符串常量（只读！）
    // ==========================
    char *str = "hello";
    // str 是指针，存的是 "hello" 首地址
    // 内容不能改：str[0] = 'A' 会崩溃！

    printf("str = %s\n", str);        // hello
    printf("sizeof(str) = %d\n", sizeof(str)); // 8（指针大小）


    // ==========================
    // 2. 字符数组 → 栈上可修改字符串
    // ==========================
    char arr[] = "hello";
    // arr 是数组，存了 h e l l o \0
    // 内容可以改：arr[0] = 'A' → "Aello"

    printf("arr = %s\n", arr);        // hello
    printf("sizeof(arr) = %d\n", sizeof(arr)); // 6（5+1）


    // ==========================
    // 3. 指定大小的字符数组
    // ==========================
    char b[10] = "hello";
    // 数组大小 10，内容 hello\0 + 一堆空字符
    // 可修改

    printf("b = %s\n", b);            // hello
    printf("sizeof(b) = %d\n", sizeof(b)); // 10


    // ==========================
    // 4. 字符串数组 → 存多个字符串
    // ==========================
    char *strs[] = {"apple", "banana", "orange"};
    // strs 是数组，里面每个元素都是 char* 指针

    printf("%s\n", strs[0]); // apple
    printf("%s\n", strs[1]); // banana
    return 0;
}