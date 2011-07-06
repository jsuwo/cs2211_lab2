#include <stdio.h>
#include <string.h>
#include "input_helper.h"

void flush_input_buffer()
{
  while (getchar() != '\n');
}

char prompt_char()
{
  char response = getchar();
  flush_input_buffer();
  return response;
}

void prompt_string(char* buffer, int max_length, char* prompt)
{
  int done = 0;

  do {
    printf("%s: ", prompt);

    fgets(buffer, max_length, stdin);
    buffer[strlen(buffer)-1] = '\0';

    if (strlen(buffer) > 0)
      done = 1;
    else
      printf("\nInvalid input, please try again.\n");

  } while (!done);

}

int prompt_integer(char* prompt, int min_value, int max_value)
{
  int done = 0;
  int value;
  char buffer[BUFFER_SIZE];
  
  do {
    printf("%s: ", prompt);
    scanf("%d", &value);
    flush_input_buffer();

    if ((value >= min_value) && (value <= max_value))
      done = 1; 
    else
      printf("\nInvalid input.  Please enter a value between %d and %d.\n", min_value, max_value);

  } while (!done);

  return value;
}
