#include<stdio.h> 
#include <fcntl.h> 
#include <stdlib.h>

int main() 
{ 
  int fd, sz; 
  char *c = (char *) calloc(100, sizeof(char)); 
  
  fd = open("foo.txt", O_RDONLY); 
  if (fd < 0) { 
      perror("r1");
       exit(0); 
    } 
  
  sz = read(fd, c, 10); 
  printf( " %d bytes  were read.\n", sz); 
  c[sz] = '\0'; 
  printf("Those bytes are as follows: % s\n", c); 
} 