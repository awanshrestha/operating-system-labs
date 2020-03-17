#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){

    int file = open("foo.txt", O_WRONLY | O_CREAT, 0);

    if(file < 0){
        perror("r1");
        exit(0);
    }

    int sz = write(file, "Hello", 4);

    printf("Written");

    close(file);

    return 0;
}