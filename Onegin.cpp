#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

char** Read_File_And_Create_Array_Of_Pointers();

char* Read_File(FILE* input_file);

unsigned int count_length(FILE* input_file);

unsigned int count_strings(char* array_of_strings);

char** Create_Array_Of_Pointers(char* array_of_strings, unsigned int number_of_strings);

int main()
    {
     char** Array_Of_Pointers = Read_File_And_Create_Array_Of_Pointers();

     int number_of_strings = count_strings(Array_Of_Pointers[0]);  //pointer to the beginning of the array_of_strings

     return 0;
    }

char** Read_File_And_Create_Array_Of_Pointers()
    {
     FILE* input_file = fopen("Onegin.txt", "r");
     assert(input_file);

     char* array_of_strings = Read_File(input_file);
     assert(array_of_strings);

     unsigned int number_of_strings = count_strings(array_of_strings);
     char** Array_Of_Pointers = Create_Array_Of_Pointers(array_of_strings, number_of_strings);
     printf(*Array_Of_Pointers);

     assert(number_of_strings);
     assert(Array_Of_Pointers);

     return Array_Of_Pointers;
    }

char* Read_File(FILE* input_file)
    {
     assert(input_file);

     unsigned int length = count_length(input_file);

     char* array_of_strings = (char*) calloc(length + 1, sizeof(*array_of_strings));
     assert(array_of_strings);

     fread(array_of_strings, length + 1, sizeof(*array_of_strings), input_file);
     fclose(input_file);

     return array_of_strings;
    }

unsigned int count_length(FILE* input_file)
    {
     assert(input_file);

     fseek(input_file, 0, SEEK_END);
     unsigned int length = ftell(input_file);
     fseek(input_file, 0, SEEK_SET);  //return us to the beginning of the file

     return length;
    }

unsigned int count_strings(char* array_of_strings)
    {
     assert(array_of_strings);

     unsigned int number_of_strings = 1;
     int i = 0;

     while (array_of_strings[i] != '\0')
         {
          if (array_of_strings[i] == '\n')
              number_of_strings++;

          i++;
         };

     return number_of_strings;
    }

char** Create_Array_Of_Pointers(char* array_of_strings, unsigned int number_of_strings)
    {
     assert(array_of_strings);
     assert(number_of_strings);

     char** Array_Of_Pointers = (char**)  calloc(number_of_strings + 1, sizeof(*Array_Of_Pointers));

     int i = 0;

     while (array_of_strings[i] != '\0')
         {
          if (array_of_strings[i] == '\n')
              {
               Array_Of_Pointers[i] = '\0';
              }
          else
              {
               char* for_adress = &array_of_strings[i];
               Array_Of_Pointers[i] = &for_adress;
              };

          i++;
         };

     Array_Of_Pointers[i] = '\0';

     return Array_Of_Pointers;
    }
