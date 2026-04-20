#include<stdio.h>
/*
二维数组的遍历:
for ( i =0; i <row; i++) {
    for ( j =0; j <column; j++) {
        a [i][j] = i*j;
    }
} 
*/
int main()
{
    //读入矩阵
    const int size = 3;
    int board [size][size];
    int i, j;
    int numofx;
    int numofo;
    int result = -1;// -1：没人赢，1：x获胜； 0:o获胜。
    for ( i =0; i <size; i++) {
        for ( j =0; j <size; j++) {
            scanf ("%d", &board [i][j]);
        }
    }
    //检查行
    for ( i =0; i <size && result == -1 ; i++ ) {
        numofx = numofo = 0;
        for ( j =0; j <size; j++) {
            if ( board [i][j] == 1 ) {
                numofx++;
            } else {
                numofo++;
            }
        }
        if ( numofo == size ) {
            result = 0;
        } else if ( numofx == size ) {
            result = 1;
        }
    }
    //检查列
    if ( result == -1 ) {
            for ( j =0; j <size && result == -1 ; j++ ) {
            numofx = numofo = 0;
            for ( i =0; i <size; i++) {
                if ( board [i][j] == 1 ) {
                    numofx++;
                } else {
                    numofo++;
                }
            }
            if ( numofo == size ) {
                result = 0;
            } else if ( numofx == size ) {
                result = 1;
            }
        }
    }
    //检查对角线上升[0][2]、[1][1]、[2][0]
    if ( result == -1) {
        numofx = numofo = 0;
        for ( i =0; i <size; i++) {
            if ( board [i][size-i-1] == 1 ) {
                numofx++;
            } else {
                numofo++;
            }
        }
        if ( numofo == size ) {
                result = 0;
            } else if ( numofx == size ) {
                result = 1;
            }
    }
    //检查对角线下降,[0][0]、[1][1]、[2][2]
    if ( result == -1 ) {
        numofx = numofo = 0;
        for ( i =0; i <size; i++) {
            if ( board [i][i] == 1 ) {
                numofx++;
            } else {
                numofo++;
            }
        }
        if ( numofo == size ) {
                result = 0;
            } else if ( numofx == size ) {
                result = 1;
            }
    }
    //输出胜负结果
    switch ( result )
    {
    case 1:
        printf ("X win! \n");
        break;
    case 0:
        printf ("O win! \n");
        break;
    case -1:
        printf ("Nobody wins. \n");
        break;
    default:
        break;
    }
    return 0;
}
