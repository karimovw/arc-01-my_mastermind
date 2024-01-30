#include <stdio.h>
#include "string.h"
#include "stdlib.h"
int main(int argc, char**argv)
{
    char*str;
    int count = 0;
   for(int i = 0; i < 127; i++){
       count-=count;
       for(int j = 1; j < argc; j++){
           str = argv[j];
           for(int k = 0; str[k] != '\0'; k++){
               if(str[k] == i) count+=1;
           }
       }
       if(count != 0){
               printf("%c:%d\n",i,count);
           }
   }
    return 0;
}