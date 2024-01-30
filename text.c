#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void fill_null(char *str, int count)
    for (int i = 0; i < count; i++){

    }



int main(){
    int j = 0;
    int i = 0;
    int temp = 0;
    int fd = open("test", O_RDWR);
    int buffer_size = 128;
    char c; 
    char* buffer = malloc(sizeof(char) * (buffer_size+1));
    int* arr = malloc(sizeof(int) * (buffer_size+1));
    while(read( fd, &c, 1)){
       if( c == ',' || c  == '\n' ){
        arr[j] = atoi(buffer);
        atoi(buffer);
        i = 0;
        fill_null(buffer, buffer_size);

       }
        buffer[i++] = c; \
    for (int a = 0; a < j-1; a++){
        for(int b = a+1; b < j; b++){
            if(arr[a] > arr[b])
        }
    }
    }
    for (i = 0; i < j; i++){

    }
    close(fd);
    free(buffer);
    free(arr);
    return 0;
}

