#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *hist = malloc(sizeof(List*));
  hist -> root = NULL; //ASSIGN hist.root() TO NULL
  return hist;
}

void add_history(List *list, char *str){
  Item *listItem = malloc(sizeof(Item));
  int idCount = 0;
  if(list -> root == NULL){
    list -> root = listItem;
  }
  else{
    struct s_Item *temp = list -> root;
    idCount++;
    while(temp -> next != NULL){
      idCount++;
      temp = temp -> next;
    }
    temp -> next = listItem;
  }
  listItem -> id = idCount;
  int charCount = 0;
  while(*str != '\0'){
    charCount++;
    str++;
  }
  str = str-charCount;
  char *strCp = copy_str(str, charCount);
  listItem -> str = strCp;
  listItem -> next = NULL;
}
