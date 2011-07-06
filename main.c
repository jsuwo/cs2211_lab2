#include <stdio.h>
#include <stdlib.h>
#include "input_helper.h"
#include "inventory.h"

#define CHOICE_ADD  '1'
#define CHOICE_FIND '2'
#define CHOICE_LIST '3'
#define CHOICE_DELE '4'
#define CHOICE_QUIT '5'
#define MAX_NAME_CHARS 80

void print_menu()
{
  puts("\nInventory Management System 1.0");
  puts("=================================\n");

#ifndef PART2
  puts("It works!");
#endif

#ifdef PART2
  puts("1. Add a new product");
#endif

#ifdef PART3
  puts("2. List products");
#endif

#ifdef PART4
  puts("3. Find a product");
#endif

#ifdef PART7
  puts("4. Delete a product");
#endif

  puts("5. Exit");

  printf("\n> ");
}

#ifdef PART2
void do_add_product()
{
  static char product_name[MAX_NAME_CHARS];
  int quantity;

  prompt_string(product_name, MAX_NAME_CHARS, "Product name");
  quantity = prompt_integer("Quantity in stock",1,9999);

  add_product(product_name, quantity);
}
#endif

#ifdef PART4
void do_find_product()
{
  char product_name[MAX_NAME_CHARS];
  prompt_string(product_name, MAX_NAME_CHARS, "Product name");

  find_product(product_name);
}
#endif

#ifdef PART7
void do_delete_product()
{
  char product_name[MAX_NAME_CHARS];
  prompt_string(product_name, MAX_NAME_CHARS, "Product name");

  delete_product(product_name);
}
#endif

int main()
{
  char response;
  do
  {
    print_menu();
    response = prompt_char();

    switch (response)
    {
#ifdef PART2
      case CHOICE_ADD:
        do_add_product();
        break;
#endif

#ifdef PART3
      case CHOICE_LIST:
        do_list_products();
        break;
#endif

#ifdef PART4
      case CHOICE_FIND:
        do_find_product();    
        break;
#endif

#ifdef PART7
      case CHOICE_DELE:
        do_delete_product();
        break;
#endif

      case CHOICE_QUIT:
        break;

      default:
        puts("\nInvalid choice, please try again.");
        break;
    }

  } while (response != CHOICE_QUIT);

  exit(EXIT_SUCCESS);
}
