#include <stdio.h>
#include <string.h>

/*
 * =============================================
 * C语言联合体（Union）详解 - 小白入门教程
 * =============================================
 *
 * 什么是联合体？
 * - 联合体就像一个"共享房间"
 * - 所有成员共用同一块内存，一次只能存一个成员的值
 * - 内存大小等于最大成员的大小
 *
 * 对比结构体：
 * - 结构体：每人一个房间，互不影响（各成员都有独立内存）
 * - 联合体：所有人共用一个房间（所有成员共享同一块内存）
 */

// 第1步：定义一个联合体
// 这个联合体可以用来存储不同类型的值，但同一时间只能存储一个
union Data {
    int i;      // 整数
    float f;    // 浮点数
    char str[20]; // 字符串
};

int main()
{
    // ===============================
    // 例子1：基本用法
    // ===============================
    printf("===== 例子1：基本用法 =====\n\n");

    union Data data;  // 定义一个联合体变量

    // 给整数成员赋值
    data.i = 10;
    printf("给整数成员赋值: data.i = %d\n", data.i);

    // 给浮点数成员赋值 会覆盖 整数的值（因为共享内存）
    data.f = 3.14;
    printf("给浮点数成员赋值: data.f = %.2f\n", data.f);
    // 注意：此时 data.i 的值已经变得乱七八糟了，因为被浮点数覆盖了
    printf("但此时 data.i 的值（内存被覆盖）: %d\n", data.i);

    // 给字符串赋值 也会覆盖之前的所有值
    strcpy(data.str, "Hello");
    printf("给字符串成员赋值: data.str = %s\n", data.str);
    printf("此时 data.i 的值: %d\n", data.i);
    printf("此时 data.f 的值: %.2f\n", data.f);

    // 结论：同一时间只有一个成员的值是有效的

    // ===============================
    // 例子2：节省内存
    // ===============================
    printf("\n===== 例子2：节省内存 =====\n\n");

    struct {
        int type;       // 类型标识
        int i;          // 当type=1时使用
        float f;        // 当type=2时使用
    } structData;      // 结构体版本：三个成员，内存叠加

    union {
        int type;       // 类型标识
        int i;          // 当type=1时使用
        float f;        // 当type=2时使用
    } unionData;       // 联合体版本：共享内存

    printf("结构体大小: %zu 字节\n", sizeof(structData));
    printf("联合体大小: %zu 字节\n", sizeof(unionData));
    printf("\n结论：联合体更省内存！\n");

    // ===============================
    // 例子3：实际应用场景
    // ===============================
    printf("\n===== 例子3：实际应用 =====\n\n");

    // 场景：做一个简易计算器，需要存储整数或小数
    union Value {
        int intVal;
        double doubleVal;
    };

    union Value result;
    int isInteger = 1;  // 标记：1表示整数结果，0表示小数结果

    // 场景1：计算 10 / 3 = 3（整数）
    result.intVal = 10 / 3;
    isInteger = 1;
    if (isInteger) {
        printf("10 / 3 = %d (整数运算)\n", result.intVal);
    } else {
        printf("结果 = %.2f (小数运算)\n", result.doubleVal);
    }

    // 场景2：计算 10.0 / 3.0 = 3.33（小数）
    result.doubleVal = 10.0 / 3.0;
    isInteger = 0;
    if (isInteger) {
        printf("结果 = %d (整数运算)\n", result.intVal);
    } else {
        printf("10.0 / 3.0 = %.2f (小数运算)\n", result.doubleVal);
    }

    // ===============================
    // 例子4：通过类型标识使用联合体
    // ===============================
    printf("\n===== 例子4：类型标识 =====\n\n");

    // 定义一个带类型标识的结构体，包含联合体
    struct {
        int type;  // 0=整数, 1=浮点数, 2=字符串
        union {
            int i;
            float f;
            char s[30];
        } data;
    } record;

    // 存一个整数
    record.type = 0;
    record.data.i = 42;
    printf("type=%d, value=%d\n", record.type, record.data.i);

    // 存一个浮点数
    record.type = 1;
    record.data.f = 2.718;
    printf("type=%d, value=%.3f\n", record.type, record.data.f);

    // 存一个字符串
    record.type = 2;
    strcpy(record.data.s, "C语言真有趣！");
    printf("type=%d, value=%s\n", record.type, record.data.s);

    // ===============================
    // 总结
    // ===============================
    printf("\n===== 总结 =====\n");
    printf("1. 联合体的所有成员共享同一块内存\n");
    printf("2. 给一个成员赋值会覆盖其他成员的值\n");
    printf("3. 联合体的大小 = 最大成员的大小\n");
    printf("4. 常用场景：需要存储不同类型但同时只用一个的情况\n");
    printf("5. 配合类型标识（如type字段）使用更安全\n");

    return 0;
}
