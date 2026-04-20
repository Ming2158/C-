#include <stdio.h>
#include <stdlib.h>// 包含malloc/free的头文件
#include <string.h>

/*
 * =============================================
 * C语言动态内存分配（malloc/free）
 * 小白入门教程
 * =============================================
 *
 * 什么是动态内存分配？
 * - 程序运行时（而非编译时）决定需要多少内存
 * - 用完记得归还，否则会造成"内存泄漏"
 *
 * 重要概念：
 * - malloc：从堆（heap）申请一块内存
 * - free：把内存归还给系统
 * - 堆 vs 栈：栈是自动管理，堆是手动管理
 */

// 辅助函数：打印内存地址信息
void printInfo(int *arr, int size) {
    printf("  地址: %p, 大小: %d 字节\n", (void*)arr, size * (int)sizeof(int));
}

int main()
{
    // ===============================
    // 例子1：malloc基本用法
    // ===============================
    printf("===== 例子1：malloc基本用法 =====\n\n");

    // 需求：存储5个整数
    // 写法：malloc(数量 * 每个的大小)
    int *arr1 = (int *)malloc(5 * sizeof(int));

    if (arr1 == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    // 给分配来的内存写入数据
    for (int i = 0; i < 5; i++) {
        arr1[i] = (i + 1) * 10;
    }

    printf("分配了5个整数的空间:\n");
    for (int i = 0; i < 5; i++) {
        printf("  arr1[%d] = %d\n", i, arr1[i]);
    }
    printInfo(arr1, 5);

    // 重要：释放内存！
    free(arr1);
    arr1 = NULL;  // 避免"野指针"问题

    // ===============================
    // 例子2：malloc + 初始化为0
    // ===============================
    printf("\n===== 例子2：calloc（分配并初始化为0） =====\n\n");

    // calloc = allocation + zero-initialization（分配+清零）
    int *arr2 = (int *)calloc(5, sizeof(int));

    if (arr2 == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    printf("calloc分配的空间（自动初始化为0）:\n");
    for (int i = 0; i < 5; i++) {
        printf("  arr2[%d] = %d\n", i, arr2[i]);
    }
    printInfo(arr2, 5);

    free(arr2);
    arr2 = NULL;

    // ===============================
    // 例子3：realloc——调整内存大小
    // ===============================
    printf("\n===== 例子3：realloc（调整大小） =====\n\n");

    // 先分配3个整数
    int *arr3 = (int *)malloc(3 * sizeof(int));
    arr3[0] = 100; arr3[1] = 200; arr3[2] = 300;
    printf("原数组（3个元素）: %d, %d, %d\n", arr3[0], arr3[1], arr3[2]);

    // 扩大空间到6个元素
    int *arr3_new = (int *)realloc(arr3, 6 * sizeof(int));

    if (arr3_new == NULL) {
        printf("realloc失败！\n");
        free(arr3);
        return 1;
    }

    // 注意：realloc可能移动了内存地址，所以要用新地址
    printf("realloc后:\n");
    for (int i = 0; i < 6; i++) {
        printf("  arr3_new[%d] = %d\n", i, arr3_new[i]);
    }
    printf("新地址: %p\n", (void*)arr3_new);

    free(arr3_new);
    arr3_new = NULL;

    // ===============================
    // 例子4：动态分配字符串
    // ===============================
    printf("\n===== 例子4：动态字符串 =====\n\n");

    // char数组有两种方式：
    // 栈上：char str[100]; —— 大小固定
    // 堆上：char *str = malloc(n); —— 大小动态

    char *name = (char *)malloc(50 * sizeof(char));

    if (name == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    strcpy(name, "Hello, malloc!");
    printf("动态字符串: %s\n", name);
    printf("字符串长度: %zu\n", strlen(name));

    free(name);
    name = NULL;

    // ===============================
    // 例子5：结构体动态分配
    // ===============================
    printf("\n===== 例子5：结构体动态分配 =====\n\n");

    struct Student {
        int id;
        char name[30];
        float score;
    };

    // 给一个学生分配内存
    struct Student *stu = (struct Student *)malloc(sizeof(struct Student));

    if (stu == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    stu->id = 1001;
    strcpy(stu->name, "张三");
    stu->score = 95.5;

    printf("学生信息:\n");
    printf("  学号: %d\n", stu->id);
    printf("  姓名: %s\n", stu->name);
    printf("  成绩: %.1f\n", stu->score);

    free(stu);
    stu = NULL;

    // ===============================
    // 例子6：二维数组的动态分配
    // ===============================
    printf("\n===== 例子6：二维数组（动态分配） =====\n\n");

    int rows = 3;
    int cols = 4;

    // 分配一个 rows x cols 的二维数组
    int **matrix = (int **)malloc(rows * sizeof(int *));  // 先分配行指针

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));   // 每行分配列
    }

    // 给二维数组赋值
    int val = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = val++;
        }
    }

    printf("3x4 二维数组:\n");
    for (int i = 0; i < rows; i++) {
        printf("  行%d: ", i);
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 释放内存（先列后行，顺序不能乱）
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;

    // ===============================
    // 例子7：常见错误演示
    // ===============================
    printf("\n===== 例子7：常见错误（牢记！） =====\n\n");

    // ❌ 错误1：忘记检查NULL
    // int *p = malloc(1000000000000);  // 分配失败但没检查！

    // ❌ 错误2：内存泄漏
    // void leak() {
    //     int *p = malloc(sizeof(int));
    //     *p = 123;
    //     return;  // 函数结束，p丢了，再也找不到这块内存！
    // }

    // ❌ 错误3：重复释放
    // int *q = malloc(sizeof(int));
    // free(q);
    // free(q);  // 崩溃！已经释放过了

    // ❌ 错误4：野指针（释放后没设为NULL）
    // int *r = malloc(sizeof(int));
    // free(r);
    // *r = 456;  // 危险！r现在是野指针，指向无效内存

    // ✅ 正确做法：释放后立刻设为NULL
    int *safe = (int *)malloc(sizeof(int));
    free(safe);
    safe = NULL;  // 安全！不会再误用

    printf("正确做法：malloc后记得free，free后设为NULL\n");

    // ===============================
    // 总结
    // ===============================
    printf("\n===== 总结 =====\n");
    printf("1. malloc(size)：申请指定字节的内存，返回void*\n");
    printf("2. calloc(n, size)：申请n个size大小的内存，初始化为0\n");
    printf("3. realloc(ptr, new_size)：调整已分配内存的大小\n");
    printf("4. free(ptr)：释放内存，绝不能忘！\n");
    printf("5. 释放后立即设为NULL，避免野指针\n");
    printf("6. 内存分配在堆上，函数结束不会自动释放\n");

    return 0;
}
