#include "asynctest.c"
#include <stdio.h>

void fCallBack(int a)
{
    //do something
    printf("a = %d\n",a);
    printf("fCallBack print! \n");
}


int main(void)
{
    SetCallBackFun(4,fCallBack);

    return 0;
}