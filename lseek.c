
#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h> 
   
int main() 
{ 
    char arr[100]; 
    int n; 
    n = 5; 

    int f1 = open("start.txt", O_RDONLY); 
    int f2 = open("end.txt", O_WRONLY); 
  
    int count = 0; 
    while (read(f1, arr, 1)) 
    { 
        if (count < n) 
        { 
            lseek (f1, n, SEEK_CUR); 
            write (f2, arr, 10); 
            count = n; 
        } 
        else
        { 
            count = (2*n); 
            lseek(f1, count, SEEK_CUR); 
            write(f2, arr, 10); 
        } 
    } 
    close(f1); 
    close(f2); 

    return 0; 
} 
