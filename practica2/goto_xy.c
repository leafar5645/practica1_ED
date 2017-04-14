#include <stdio.h>
#include <stdlib.h>
void gotoxy(int x,int y)
 {
 system("clear");
 printf("%c[%d;%df",0x1B,y,x);
 }

 int main(void)
{
gotoxy(20,10);
printf("hello world\n");
return 0;
}
