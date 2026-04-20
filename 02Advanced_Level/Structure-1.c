#include <stdio.h>

// 定义一个名为 point 的结构体，包含两个整型成员：x 和 y 坐标
struct point
{
    int x;
    int y;
};

// 三个函数声明
struct point* getStruct(struct point*);  // 返回值是指向 struct point 的指针，参数也是指针
void output(struct point);               // 返回值 void，参数是结构体副本（传值）
void print(const struct point *p);      // 返回值 void，参数是指向常量的指针

int main (int argc, char *argv[]) {
    struct point y = {0,0};   // 定义一个 point 结构体变量 y，初始化为 {0, 0}
    getStruct(&y);            // 调用 getStruct，传入 y 的地址，让用户输入 x 和 y 的值
    output(y);                // 调用 output，以传值方式传入 y 的副本
    output(*getStruct(&y));   // 调用 getStruct 获取指针，再解引用得到结构体副本传给 output
    print(getStruct(&y));     // 调用 getStruct 获取指针，直接传给 print（传指针）
    return 0;
}

// getStruct 函数：从键盘读取两个整数填充到 p 所指向的结构体，返回该指针
struct point* getStruct(struct point *p) {
    scanf("%d", &p->x);      // 通过指针访问成员，为 x 赋值
    scanf("%d", &p->y);      // 通过指针访问成员，为 y 赋值
    printf("%d, %d \n", p->x, p->y);  // 打印当前输入的值
    return p;                 // 返回调用者传入的结构体地址
}

// output 函数：以传值方式接收结构体，打印其成员
void output(struct point p) {
    printf("%d, %d \n", p.x, p.y);  // 直接通过点号访问成员
}

// print 函数：以常量指针方式接收结构体，打印其成员
void print(const struct point *p) {
    printf("%d, %d \n", p->x, p->y);  // 通过指针访问成员
}