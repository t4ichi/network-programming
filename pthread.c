//   $gcc  –pthread soucefile.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void pthread(int i) {
  usleep(i*100000); printf("%d",i); fflush(stdout);
  // i++;
  // usleep(i*30000); printf("%d",i); fflush(stdout);
  // i++;
  // usleep(i*30000); printf("%d",i); fflush(stdout);
  // i++;
  // usleep(i*30000); printf("%d",i); fflush(stdout);
  // i++;
  // usleep(i*30000); printf("%d",i); fflush(stdout);
}

int main() {
  pthread_t t1,t2,t3;
  int i,j;
  for(j = 0;j < 10;j++){
    pthread_create(&t1,NULL,(void *)pthread,(void *)1);
    pthread_create(&t2,NULL,(void *)pthread,(void *)2);
    pthread_create(&t3,NULL,(void *)pthread,(void *)3);

      for(i=0;i<40;i++) {
        putchar('.'); fflush(stdout); usleep(10000);
      }
      pthread_join(t1,NULL);
      pthread_join(t2,NULL);
      pthread_join(t3,NULL);
      printf("\n");
  }
}
