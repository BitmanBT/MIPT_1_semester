#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stddef.h>


char** Read_File_And_Create_Array_Of_Pointers(size_t* number_of_strings);

char* Read_File(FILE* input_file);

size_t Count_Length(FILE* input_file);

size_t Count_Strings(char* array_of_strings);

char** Create_Array_Of_Pointers(char* array_of_strings, unsigned int number_of_strings);

void Write_File(char** Array_Of_Pointers, unsigned int number_of_strings);

int Compile_1(const void* str_1, const void* str_2);

int Compile_2(const void* str_1, const void* str_2);

char* No_Spaces(char** string_x);
