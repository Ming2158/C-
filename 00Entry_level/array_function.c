#include <stdio.h>
void sum ( int begin, int end );//对function进行声明。
int add ( int a, int b );
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d \n", arr[0]);
    printf("%d \n", arr[1]);
    printf("%d \n", arr[2]);
    printf("%d \n", arr[3]);
    printf("%d \n", arr[4]);
    printf("\n");
/*
定义数组
int number [100]; double weight[20];
scanf ("%d", &number [i]);
*/

    sum ( 1, 10 );
    printf("\n");
/*函数调用
sum ( 1, 10 );  //调用函数，传入实参
void xxx () {} 无返回值
int xxx () {} 有返回值
*/
return 0;
}
void sum ( int begin, int end) {
    int i;
    int sum = 0;
    for ( i =begin; i <=end; i++ ) {
        sum += i;
    }
    printf ("%d到%d的和是%d \n", begin, end, sum);
}
int add ( int a, int b ) {
    int sum = a + b;
    return sum;
}