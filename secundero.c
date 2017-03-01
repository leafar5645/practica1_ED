#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
 int i=1;
 while(i<10)
{
 printf("segundo %d\n",i);
 i++;
 sleep(1);
}
return 0;
}
