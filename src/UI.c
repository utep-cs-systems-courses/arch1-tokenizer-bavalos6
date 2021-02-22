#include <stdio.h>
#include <stdlib.h>

void main(){
  char user_in[1000];
  while(1){
    putchar ('>');
    fgets (user_in, 1000, stdin);
    if(*user_in == '$'){
      break;
    }
    printf (user_in);
  }
  
}
