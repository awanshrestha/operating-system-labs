#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){

    char arr[100];
    int n = 5;
    int count = 0;

    int f1 = open("start.txt", O_RDONLY);
    int f2 = open("end.txt", O_WRONLY);

    while (read(f1,arr,1))
    {
        if(count < n){
            lseek(f1, n,SEEK_CUR);
            write(f2, arr ,1);
            count = n;
        }
        else {
            count = 2 *n;
            lseek(f1, n, SEEK_CUR);
            write(f2, arr,1);
        }
    }
    

    close(f1);
    close(f2);

    return 0;
}