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

void Write_File(char** Array_Of_Pointers, unsigned int number_of_strings);

int Compile_1(const void* str_1, const void* str_2);

int Compile_2(const void* str_1, const void* str_2);

char* the_end_of_str (char** string_x);

int main()
    {
     char** Array_Of_Pointers = Read_File_And_Create_Array_Of_Pointers();

     int number_of_strings = count_strings(Array_Of_Pointers[0]); //pointer to the beginning of the array_of_strings

     qsort(Array_Of_Pointers, number_of_strings, sizeof(*Array_Of_Pointers), Compile_1);
     Write_File(Array_Of_Pointers, number_of_strings);

     qsort(Array_Of_Pointers, number_of_strings, sizeof(*Array_Of_Pointers), Compile_2);
     Write_File(Array_Of_Pointers, number_of_strings);

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
     fseek(input_file, 0, SEEK_SET); //return us to the beginning of the file

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

char* * Create_Array_Of_Pointers(char* array_of_strings, unsigned int number_of_strings)
    {
     assert(array_of_strings);
     assert(number_of_strings);

     char** Array_Of_Pointers = (char**) calloc(number_of_strings + 1, sizeof(*Array_Of_Pointers));

     int i        = 0,
         position = 0;

     Array_Of_Pointers[position] = &array_of_strings[i];

     while (array_of_strings[i] != '\0')
         {
          i++;
          if (array_of_strings[i] == '\n')
              {
               position++;
               Array_Of_Pointers[position] = &array_of_strings[i];
              };
         };

     return Array_Of_Pointers;
    }

void Write_File(char** Array_Of_Pointers, unsigned int number_of_strings)
    {
     assert(Array_Of_Pointers);
     assert(number_of_strings);

     int i = 0;
     FILE* output_file = fopen("Rez.txt", "w");

     for (i = 0; i < number_of_strings; i++)
         {
          fputs(Array_Of_Pointers[i], output_file);
          fputc('\n', output_file);
         };

     fclose(output_file);
    }

int Compile_1(const void* str_1, const void* str_2)
    {
     return strcmp(*(const char**) str_1, *(const char**) str_2);
    }

int Compile_2(const void* str_1, const void* str_2)
    {
     char* string_1 = *(char**) str_1;
     char* string_2 = *(char**) str_2;

     string_1 = the_end_of_str(&string_1);
     string_2 = the_end_of_str(&string_2);

     for (;;)
         {
          if (*string_1 < *string_2)
              return 1;
          if (*string_1 > *string_2)
              return -1;
          string_1++;
          string_2++;
         };
    }

char* the_end_of_str (char** string_x)
    {
     int i = 0;

     while (*string_x[i] != '\0')
         {
          i++;
         };

     char** new_string_x = (char**) calloc(i+1, sizeof(*new_string_x));

     int position = 0;
     int new_i    = 0;

     while (i > new_i)
         {
          if (!isspace(**string_x) && **string_x != '\0')
              {
               new_string_x[position] = string_x[new_i];
               position++;
              };

          new_i++;
         };

     return *new_string_x;
    }
