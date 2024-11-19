// run-length encoding (RLE): compression technique that replaces repeated sequences 
// of characters with a count and the character itself 

#include <stdio.h>
#include <string.h>

void encode(char *input, char *output) {
  int count = 1; 
  int i, j = 0;

  for (i = 0; i < strlen(input); i++) {
    if (i + 1 < strlen(input) && input[i] == input[i + 1]) {
      count ++;
    }
    else {
      output[j++] = count + '0'; // convert count to character 
      output[j++] = input[i];
      count = 1;
    }
  }

  output[j] = '\0';
}

void decode(char *input, char *output) {
  int i = 0, j = 0;

  while(input[i]) {
    int count = input[i] - '0';
    i++;
    char ch = input[i++];
    while (count --) {
      output[j++] = ch;
    }
  }
output[j] = ''\0';
}

int main() {
  char input[100], encoded[100], decoded[100];\

  printf("enter a string: ");
  scanf("%s", input);

  encode(input, encoded);
  printf("encoded string; %s\n", encoded);

  decode(encoded, decoded);
  printf("decoded string; %s\n", decoded);

  return 0; 
}
