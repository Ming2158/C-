#include <stdio.h>

/*
 * =============================================
 * C语言枚举（enum）详解 - 小白入门教程
 * =============================================
 *
 * 什么是枚举？
 * - 枚举是一种创建常量集合的方式
 * - 用有名字的符号代替冰冷的数字代码更易读
 *
 * 比如：星期一二三四五六日，用数字0-6表示容易出错，用 MON/TUE/WED 就清晰多了
 */

// 第1步：定义枚举
// 语法：enum 枚举名 { 常量1, 常量2, 常量3, ... };

// 星期枚举
enum Weekday {
    MON = 1,   // 手动指定从1开始（默认从0开始）
    TUE,       // 自动+1，得到2
    WED,       // 得到3
    THU,       // 得到4
    FRI,       // 得到5
    SAT,       // 得到6
    SUN        // 得到7
};

// 颜色枚举
enum Color {
    RED,    // 0
    GREEN,  // 1
    BLUE    // 2
};

// 状态枚举（带手动值）
enum Status {
    ERROR   = -1,
    OK      = 0,
    PENDING = 1
};

// 声明一个枚举变量（也可以合并写：enum Color { RED, GREEN, BLUE } c;）
enum Color favorite;

int main()
{
    // ===============================
    // 例子1：基本用法
    // ===============================
    printf("===== 例子1：基本用法 =====\n\n");

    // 定义枚举变量
    enum Weekday today = MON;  // 或直接写：enum Weekday today = 1;
    printf("今天是星期%d (MON=%d)\n", today, MON);

    // 枚举变量可以像整数一样比较
    if (today == MON) {
        printf("今天周一，要上班！\n");
    } else if (today == SAT || today == SUN) {
        printf("今天休息！\n");
    } else {
        printf("正常工作日\n");
    }

    // ===============================
    // 例子2：遍历枚举（所有值）
    // ===============================
    printf("\n===== 例子2：遍历枚举 =====\n\n");

    printf("一周的所有日子:\n");
    for (enum Weekday day = MON; day <= SUN; day++) {
        // 注意：day++ 依赖枚举值连续递增
        printf("  %d ", day);
        switch (day) {
            case MON: printf("Monday\n");    break;
            case TUE: printf("Tuesday\n");   break;
            case WED: printf("Wednesday\n"); break;
            case THU: printf("Thursday\n");  break;
            case FRI: printf("Friday\n");    break;
            case SAT: printf("Saturday\n");  break;
            case SUN: printf("Sunday\n");    break;
        }
    }

    // ===============================
    // 例子3：枚举在switch中的妙用
    // ===============================
    printf("\n===== 例子3：switch与枚举 =====\n\n");

    enum Status result = OK;

    switch (result) {
        case OK:
            printf("操作成功！\n");
            break;
        case ERROR:
            printf("操作失败！\n");
            break;
        case PENDING:
            printf("操作等待中...\n");
            break;
        default:
            printf("未知状态\n");
    }

    // ===============================
    // 例子4：枚举实战 —— 菜单选择
    // ===============================
    printf("\n===== 例子4：菜单系统 =====\n\n");

    enum Menu {
        ADD = 1,    // 添加
        DELETE,     // 删除
        UPDATE,     // 更新
        QUERY,      // 查询
        EXIT        // 退出
    };

    int choice = ADD;

    printf("当前选择: %d\n", choice);
    if (choice == ADD) {
        printf(" -> 执行添加操作\n");
    }

    // 模拟用户输入 3，选择"查询"
    choice = QUERY;
    printf("用户输入: %d -> QUERY\n", choice);
    switch (choice) {
        case ADD:    printf("添加数据\n");    break;
        case DELETE: printf("删除数据\n");   break;
        case UPDATE: printf("更新数据\n");   break;
        case QUERY:  printf("查询数据\n");   break;
        case EXIT:   printf("退出程序\n");   break;
    }

    // ===============================
    // 例子5：枚举数组（存储多个枚举值）
    // ===============================
    printf("\n===== 例子5：枚举数组 =====\n\n");

    enum Weekday schedule[3] = {MON, WED, FRI};
    printf("我的课程安排（周一、周三、周五）:\n");
    for (int i = 0; i < 3; i++) {
        switch (schedule[i]) {
            case MON: printf("  周一：数学\n");   break;
            case WED: printf("  周三：物理\n");   break;
            case FRI: printf("  周五：英语\n");   break;
            default:  printf("  无课\n");        break;
        }
    }

    // ===============================
    // 例子6：枚举与typedef（简化写法）
    // ===============================
    printf("\n===== 例子6：typedef简写 =====\n\n");

    // 使用 typedef 给枚举起别名，以后就不用写 enum 了
    typedef enum {
        FALSE = 0,
        TRUE  = 1
    } Bool;

    Bool flag = TRUE;
    printf("flag = %d (TRUE=%d, FALSE=%d)\n", flag, TRUE, FALSE);

    if (flag == TRUE) {
        printf("条件成立！\n");
    }

    // ===============================
    // 总结
    // ===============================
    printf("\n===== 总结 =====\n");
    printf("1. 枚举是一组命名的整型常量\n");
    printf("2. 默认从0开始，可手动指定值\n");
    printf("3. 让代码更易读：用 MON 代替数字 1\n");
    printf("4. 常用于：状态码、菜单选项、星期、颜色等固定集合\n");
    printf("5. 配合 typedef 可以简化书写\n");

    return 0;
}
