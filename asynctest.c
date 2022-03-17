#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef void (*pcb)(int a);
typedef struct parameter
{
    int a;
    pcb callback;
} parameter;

void *callback_thread(void *p1)
{
    //do something
    parameter *p = (parameter *)p1;
    while (1)
    {
        printf("GetCallBack print! \n");
        sleep(3); //delay 3s
        p->callback(p->a);
    }
}

extern int SetCallBackFun(int a, pcb callback)
{
    printf("SetCallBackFun print! \n");
    parameter *p = malloc(sizeof(parameter));
    p->a = 10;
    p->callback = callback;

    pthread_t thing1;
    pthread_create(&thing1, NULL, callback_thread, (void *)p);
    pthread_join(thing1, NULL);
}

