#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  return (('\t'== c)||(' '== c));
}

int non_space_char(char c){
  return !space_char(c) && c != '\0';
}

/*char *word_start(char *str){

}

char *word_terminator(char *word){

}

int count_words(char *s){

}*/

void main(){
  char c = ' ';
  char d = 'f';
  printf(space_char(d) ? "True\n":"False\n"); //False
  printf(space_char(c) ? "True\n":"False\n"); //True
  printf(non_space_char(d) ? "True\n":"False\n"); //True
  printf(non_space_char(c) ? "True\n":"False\n"); //False
}
