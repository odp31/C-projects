#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 16

struct Node {
  char *str;
  int code;
  struct Node *next;
};

struct Node *head = NULL:

void insert(char *str, int code){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->str = strdup(str);
  newNode->code = code;
  newNode->next = head;
  head = newNode;
}

int search(char *str){
  struct Node *temp = head;
  while (temp != NULL) {
      if (strcmp(temp->str, str) == 0) {
        return temp->code;
      }
      temp = temp->next;
  }
  return -1; 
}

void encode(char *input, char*output) {
  int code = 256; 
  int i = 0, j = 0;
  char str[MAX_CODE_LENGTH + 1]; 
  str[0] = input[0];
  str[1] = '\0';

  while (input[i] != '\0') {
    int code = search(str);
    if (code != -1) {
      sprintf(output + j, "%d", code);
      j += strlen(output + j);
      strcpy(str, "");
      i++;
    }
    else {
      str[strlen(str)] = input[i];
      str[strlen(str) + 1] = '\0';
      insert(str, code);
      code++;
      i++;
    }
  }
// handle last str
if(strlen(str) > 0) {
  int code = search(str);
  sprintf(output + j, "%d", code);
  j += strlen(output + j);
}
output[j] = '\0';
}

void decode(char *input, char *output){
  int i = 0, j = 0;
  int code;
  char str[MAX_CODE_LENGTH + 1];
  str[0] = '\0'

  while(input[i] != '\0') {
    code = 0;
    while (input[i] != '' && input[i] != '\0') {
      code = code * 10 + (input[i] - '0');
      i++;
  }
i++;
// search dictionary for code
struct Node *temp = head;
while (temp!= NULL) {
  if(temp->code == code)
{
strcat(putput, temp-> str);
strcpy(str, temp->str);
break;
}
temp = temp->next;
}
// if code isnt found, its a new string
if(temp == NULL){
str[strlen(str)] = (char)code; 
str[strlen(str) + 1] = '\0';
strcat(output,str);
insert(str,code);
}
}
output[j] = '\0';
}

