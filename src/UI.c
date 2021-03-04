#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

void tokenazitator(char *userInput,List *list){
  printf(">>");
  fgets(userInput, 1000, stdin);
  add_history(list, userInput);
  char **tokens = tokenize(userInput);
  print_tokens(tokens);
  free_tokens(tokens);
}

void historize(char *userInput, List *list){
  print_history(list);
  printf("#");
  fgets(userInput, 100, stdin);
  char *s = get_history(list, atoi(userInput));
  if(*s == '>'){
    printf("%i %s>",atoi(userInput),s);
  }
  else{
    printf("Result: %s", s);
    char**tokens = tokenize(s);
    print_tokens(tokens);
    free_tokens(tokens);
  }
}

void main(){
  char user_in[1000];
  List *list = init_history();
  printf("Tokenizer\n");
  while(1){
    putchar ('>');
    fgets (user_in, 1000, stdin);
    if(*user_in == 't'){
      tokenazitator(user_in, list);
    }
    else if(*user_in == 'h'){
      historize(user_in, list);
    }
    else if(*user_in == 'q'){
      break;
    }
    else{
      printf("Command Unknown. Please try again./n");
    }
  }
  free_history(list);
  printf("bye\n");
}
