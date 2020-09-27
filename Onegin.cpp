#include "Header1.h"

int main()
    {
	 size_t number_of_strings = 0;

	 char** Array_Of_Pointers = Read_File_And_Create_Array_Of_Pointers(&number_of_strings);

	 Put_Zeros(Array_Of_Pointers, number_of_strings);

     //qsort(Array_Of_Pointers, number_of_strings, sizeof(char*), Compile_1);
     //Write_File(Array_Of_Pointers, number_of_strings);

     //qsort(Array_Of_Pointers, number_of_strings, sizeof(*Array_Of_Pointers), Compile_2);
     //Write_File(Array_Of_Pointers, number_of_strings);

     return 0;
    }

char** Read_File_And_Create_Array_Of_Pointers(size_t* number_of_strings)
    {
     FILE* input_file = fopen("Onegin.txt", "r");
     assert(input_file);

     char* array_of_strings = Read_File(input_file);
     assert(array_of_strings);

     *number_of_strings = Count_Strings(array_of_strings);
     char** Array_Of_Pointers = Create_Array_Of_Pointers(array_of_strings, *number_of_strings);

     assert(Array_Of_Pointers);

     return Array_Of_Pointers;
    }

char* Read_File(FILE* input_file)
    {
     assert(input_file);

     size_t length = Count_Length(input_file);

     char* array_of_strings = (char*) calloc(length + 1, sizeof(*array_of_strings));
     assert(array_of_strings);

     fread(array_of_strings, length + 1, sizeof(*array_of_strings), input_file);
     fclose(input_file);

     return array_of_strings;
    }

size_t Count_Length(FILE* input_file)
    {
     assert(input_file);

     fseek(input_file, 0, SEEK_END);
     size_t length = ftell(input_file);
     fseek(input_file, 0, SEEK_SET); //return us to the beginning of the file

     return length;
    }

size_t Count_Strings(char* array_of_strings)
    {
     assert(array_of_strings);

     size_t number_of_strings = 1;

	 for (int i = 0; array_of_strings[i] != '\0'; i++)
	     {
		  if (array_of_strings[i] == '\n')
		      {
		       number_of_strings++;
              };
	     };

     return number_of_strings;
    }

char** Create_Array_Of_Pointers(char* array_of_strings, size_t number_of_strings)
    {
     assert(array_of_strings);

     char** Array_Of_Pointers = (char**) calloc(number_of_strings + 1, sizeof(*Array_Of_Pointers));

     int position = 0;

	 for (int i = 1; array_of_strings[i] != '\0'; i++)
	     {
		  if (array_of_strings[i-1] == '\n')
		      {
			   Array_Of_Pointers[position] = &array_of_strings[i];
			   position++;
		      };
	     };

     return Array_Of_Pointers;
    }

void Write_File(char** Array_Of_Pointers, size_t number_of_strings)
    {
     assert(Array_Of_Pointers);

     FILE* output_file = fopen("Rez.txt", "w");
	 assert(output_file);

     //TODO Осмыссленные названия переменным
     //TODO Ускорить работу записи

     for (int i = 0; i < number_of_strings; i++)
         {
          fputs(Array_Of_Pointers[i], output_file);
          fputc('\n', output_file);
         };

     fclose(output_file);
    }

void Put_Zeros(char** Array_Of_Pointers, size_t number_of_strings)
    {
     assert(Array_Of_Pointers);
     assert(number_of_strings);

     for (int i = 0; i < number_of_strings; i++)
         {
          char* j;
          for (j = Array_Of_Pointers[i]; *j != '\n'; j = j + sizeof(char*));
          *j = '\0';
         };
    }

int Compile_1(const void* str_1, const void* str_2)
    {
    //TODO Почитай про strcmp, чтобы понять суть компаратора
	 assert(str_1);
	 assert(str_2);
	 return strcmp(*(const char**) str_1, *(const char**) str_2);
    }

int Compile_2(const void* str_1, const void* str_2)
    {
	 assert(str_1);
	 assert(str_2);

	 char* string_1 = *(char**) str_1;
     char* string_2 = *(char**) str_2;


     //TODO Разобраться с работой функции (некорректная работа и неэффективно)
     //string_1 = No_Spaces(&string_1);
     //string_2 = No_Spaces(&string_2);

     //TODO
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

char* No_Spaces (char** string_x)
    {
        //TODO Название переменной
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
