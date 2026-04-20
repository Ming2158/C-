#include<stdio.h>
/*
结构
struct point  有一个叫point的结构类型，里面有两个成员x和y
{
    int x;
    int y;
};
声明结构变量2种方法：
struct point p1,p2;

struct point
{
    int x;
    int y;
}p1,p2;  p1,与p2都是point里面的有x跟y的值的结构变量
*/

//声明结构
struct date
{
    int month;
    int year;
    int day;
};
int main(int argc, char const *argv[])
{
    // struct date
    // {
    //     int month;
    //     int year;
    //     int day;
    // };

    //声明结构变量
    struct date today;//today有month，day， year三个值
    struct date today1 = {07, 31, 2014};
    //结构变量初始化
    today.month = 01;
    today.day = 11;
    today.year = 2007;
    //today = (truct date) {01, 2007, 11}
    printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);

    struct date day;
    day = today;//数组不可以互相 =，但是结构变量可以
    printf("Day's date is %i-%i-%i.\n", day.year, day.month, day.day);

    struct date *pDate = &today;//结构变量的地址
    printf("aaddress of today is %p\n", pDate);

    struct date myday;
    struct date *p = &myday;//结构变量的地址
    (*p).month = 12;//通过指针访问结构变量的成员，*p是myday，(*p).month就是myday.month
    p->month = 12;//通过指针访问结构变量的成员，p->month就是myday.month
    return 0;
}
