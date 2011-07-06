#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#define BUFFER_SIZE 25

void flush_input_buffer();
char prompt_char();
void prompt_string(char* buffer, int max_length, char* prompt);
int prompt_integer(char* prompt, int min_value, int max_value);

#endif
