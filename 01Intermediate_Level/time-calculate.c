#include <stdio.h> 
int main(void) {
    int hour1, hour2, min1, min2, sec1, sec2;
    int total_sec1, total_sec2, diff_sec;  
    int hour, min, sec;
    printf("请输入两个时间点（格式：小时:分钟:秒 小时:分钟:秒）：\n");
    scanf("%d:%d:%d %d:%d:%d", &hour1, &min1, &sec1, &hour2, &min2, &sec2);
    total_sec1 = hour1 * 3600 + min1 * 60 + sec1;
    total_sec2 = hour2 * 3600 + min2 * 60 + sec2;
    if (total_sec1 > total_sec2) {
        diff_sec = total_sec1 - total_sec2;
    } else {
        diff_sec = total_sec2 - total_sec1;
    }
    hour = diff_sec / 3600;
    min = (diff_sec % 3600) / 60;  
    sec = diff_sec % 60;           
    printf("%02d:%02d:%02d\n", hour, min, sec);

/*
一、整数格式（最常用）
1. %d
十进制整数 int
例：printf("%d", 5); → 5
2. %2d
占 2 个字符宽度，不足用空格补在左边
例：5 → 5
3. %02d（你问的这个）
占 2 位，不足用 0 补左边
例：5 → 05，12 → 12
常用于：时间 08:05:09、日期、编号
4. %4d、%04d
%4d：占 4 位，空格补齐
%04d：占 4 位，0 补齐，如 5 → 0005
5. %ld
long 长整型

二、小数 / 浮点数
1. %f
float /double 默认输出 6 位小数
例：3.14 → 3.140000
2. %.2f
保留 2 位小数（四舍五入）
例：3.1415 → 3.14
3. %6.2f
总共占 6 位，其中小数 2 位，不够空格补
例：3.14 → 3.14
4. %06.2f
总共 6 位，小数 2 位，不足用 0 补
例：3.14 → 003.14

三、字符与字符串
1. %c
单个字符
例：printf("%c", 'A'); → A
2. %s
字符串
例：printf("%s", "hello"); → hello
3. %10s
字符串占 10 位，右对齐，左边补空格
4. %-10s
左对齐，右边补空格

四、进制相关（了解）
%x：十六进制小写
%X：十六进制大写
%o：八进制
%u：无符号整数

*/
    return 0;
}