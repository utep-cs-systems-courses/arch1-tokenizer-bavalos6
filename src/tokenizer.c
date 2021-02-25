#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  return (('\t'== c)||(' '== c));
}

int non_space_char(char c){
  return !space_char(c) && c != '\0';
}

char *word_start(char *str){
  char *word = str;
  while(space_char(*word)){
    word++;
  }
}

char *word_terminator(char *word){
  if(*word == '\0'){ //IF THERE IS NO WORD, RETURN EMPTY POINTER
    return word;
  }
  else{
    word = word_start(word); //LOOKING FOR NEXT WORD
    while(non_space_char(*word) && *word != '\0'){ //LOOKING FOR THE NEXT SPACE CHAR OR NULL TERMINATOR
      word++;  //MOVE THROUGH THE POINTER (THROUGH THE WORD)
    }
  }
  return word;
}

int count_words(char *str){
  str = word_start(str);
  int count = 0;
  if(*str != '\0'){
    count++;
    while(*(str = word_terminator(str)) != '\0'){
      if(*word_start(str) == '\0'){
	break;
      }
      count++;
    }
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *copy = malloc(sizeof(char) * (len + 1)); //FINDS FREE MEMORY TO STORE
  for(int i = 0; i < len; i++){
    *copy++ = *inStr++;
  }
  *copy = '\0';
  copy = copy - len;
  return copy;		      
}

char **tokenize(char* str){
  int len = count_words(str);
  char **array = (char**) malloc(sizeof(char*) * (len + 1));
  char *strT;
  int wordLen;
  for(int i = 0; i < len; i++){
    str = word_start(str);
    strT = word_terminator(str);
    wordLen = strT - str;
    array[i] = copy_str(str, wordLen);
    str = strT;
  }
  array[len] = '\0';
  return array;
}

void main(){
  char c = ' ';
  char d = 'f';
  printf(space_char(d) ? "True\n":"False\n"); //False
  printf(space_char(c) ? "True\n":"False\n"); //True
  printf(non_space_char(d) ? "True\n":"False\n"); //True
  printf(non_space_char(c) ? "True\n":"False\n"); //False
  char word[] = " Rata Sucia";
  char *ptr = &word[0];
  printf("%s\n",word_start(ptr));
  printf("%s\n",word_terminator(ptr));
  printf("%i\n",count_words(ptr));
  printf("%p\n",ptr);
  printf("%p\n",copy_str(ptr,11));
}
