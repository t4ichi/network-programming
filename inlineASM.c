 #include <stdio.h>
 
 int a = 5;
 int b = 8;
 int c ;
 int foo = 10, bar = 15;
 int d0, d1, d2;
 char src[]="abcdefg";
 char dest[]="0000000000";

 int main() {
     c = 0;
     asm ("    movl _a, %eax");
     asm ("    add  _b, %eax");
     asm ("    movl %eax, _c");
     printf("c  = %d\n", c);

     a=10;
     b=3;

     asm ("    movl _a, %eax");
     asm ("    sub  _b, %eax");
     asm ("    movl %eax, _c");
     printf("c  = %d\n", c);


       __asm__ __volatile__("addl  %%ebx,%%eax"
                           :"=a"(foo)
		           :"a"(foo), "b"(bar)
		           );
      printf("foo+bar=%d\n", foo);
	__asm__ __volatile__("1:\tlodsb\n\t"
                     "stosb\n\t"
		     "testb %%al,%%al\n\t"
		     "jne 1b"
	             : "=&S" (d0), "=&D" (d1), "=&a" (d2)
                     : "0" (src),"1" (dest) 
                     : "memory");
        printf("%s\n",dest);
     return 0;
 }

