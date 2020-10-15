#include "That's for Onegin.h"

//-----------------------------------------------------------------------------

int main()
    {
	 size_t number_of_strings = 0;

	 char** array_of_pointers = Read_File_And_Create_Array_Of_Pointers(&number_of_strings);

	 char** first_array = array_of_pointers;

	 FILE* output_file = fopen("Rez.txt", "w");
	 assert(output_file);

     qsort(array_of_pointers, number_of_strings, sizeof(*array_of_pointers), Compile_1);
     Write_File(array_of_pointers, number_of_strings);

     qsort(array_of_pointers, number_of_strings, sizeof(*array_of_pointers), Compile_2);
     Write_File(array_of_pointers, number_of_strings);

     Write_File(first_array, number_of_strings);

     fclose(output_file);

     return 0;
    }

//-----------------------------------------------------------------------------

/*!
  Function that reads the file and creates array of pointers for it
  \param[out] number_of_strings - points on the number of strings file contain
  \return Array_Of_Pointers - the beginning of the array of the pointers
*/

char** Read_File_And_Create_Array_Of_Pointers(size_t* number_of_strings)
    {
     FILE* input_file = fopen("Onegin.txt", "r");
     assert(input_file);

     char* array_of_strings = Read_File(input_file);
     assert(array_of_strings);

     *number_of_strings = Count_Strings(array_of_strings);
     char** array_of_pointers = Create_Array_Of_Pointers(array_of_strings, *number_of_strings);

     assert(array_of_pointers);

     return array_of_pointers;
    }

//-----------------------------------------------------------------------------

/*!
  Function that reads the file
  \param[in] input_file - pointer to the file
  \return array_of_strings - array that contains text from the file
*/

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

//-----------------------------------------------------------------------------

/*!
  Function, that counts length of the file (in symbols)
  \param[in] input_file - pointer to the file
  \return length - the length of the file (in symbols)
*/

size_t Count_Length(FILE* input_file)
    {
     assert(input_file);

     fseek(input_file, 0, SEEK_END);
     size_t length = ftell(input_file);
     fseek(input_file, 0, SEEK_SET); //return us to the beginning of the file

     return length;
    }

//-----------------------------------------------------------------------------

/*!
  Function that counts the number of strings text of the file contains
  \param[in] array_of_strings - array that contains text from the file
  \return number_of_strings - number of strings file contains
*/

size_t Count_Strings(char* array_of_strings)
    {
     assert(array_of_strings);

     size_t number_of_strings = 1;

	 for (int num_of_element = 0; array_of_strings[num_of_element] != '\0'; num_of_element++)
	     {
		  if (array_of_strings[num_of_element] == '\n')
		      {
		       number_of_strings++;
              }
	     }

     return number_of_strings;
    }

//-----------------------------------------------------------------------------

/*!
  \param[in] array_of_strings - pointer to the array which contains text from the file
  \param[in] number_of_strings - number of strings file contains
  \return Array_Of_Pointers - pointer to the beginning of the array of pointers
*/

char** Create_Array_Of_Pointers(char* array_of_strings, size_t number_of_strings)
    {
     assert(array_of_strings);

     char** array_of_pointers = (char**) calloc(number_of_strings + 1, sizeof(*array_of_pointers));
     assert(array_of_pointers);

     int num_of_element = 0;
     int position = 0;

     array_of_pointers[position] = array_of_strings;
     position++;

     while (array_of_strings[num_of_element - 1] != '\0')
         {
          if (array_of_strings[num_of_element] == '\n')
              {
               array_of_pointers[position] = array_of_strings + num_of_element + 1;
               position++;
              }
          num_of_element++;
         }

     Put_Zeros(array_of_pointers, number_of_strings);

     return array_of_pointers;
    }

//-----------------------------------------------------------------------------

/*!
  Function that writes into the file
  \param[in] Array_Of_Pointers - pointer to the beginning of the array of pointers
  \param[in] number_of_strings - number of strings file contains
*/

void Write_File(char** array_of_pointers, size_t number_of_strings)
    {
     assert(array_of_pointers);

     FILE* output_file = fopen("Rez.txt", "a");
	 assert(output_file);

     for (int num_of_line = 0; num_of_line < number_of_strings; num_of_line++)
         {
          fputs(array_of_pointers[num_of_line], output_file);
          fputc('\n', output_file);
         };
    }

//-----------------------------------------------------------------------------

/*!
  Function that puts '\0' instead of '\n' in the array_of_strings
  \param[in] Array_Of_Pointers - pointer to the beginning of the array of pointers
  \param[in] number_of_strings - number of strings file contains
*/

void Put_Zeros(char** array_of_pointers, size_t number_of_strings)
    {
     assert(array_of_pointers);
     assert(number_of_strings);

     for (int num_of_line = 0; num_of_line < number_of_strings - 1; num_of_line++)
         {
          char* num_of_element = array_of_pointers[num_of_line];
          assert(num_of_element);
          while(*(num_of_element++ )!= '\n');
          num_of_element--;
          *num_of_element = '\0';
         }
    }

//-----------------------------------------------------------------------------

/*!
  Compares strings (alphabetical order)
  \param[in] str_1 - first string
  \param[in] str_2 - second string
*/

int Compile_1(const void* str_1, const void* str_2)
    {
	 assert(str_1);
	 assert(str_2);

	 char* string_1 = *(char**) str_1;
     char* string_2 = *(char**) str_2;

     char* the_end_of_string_1 = To_The_End(string_1);
     char* the_end_of_string_2 = To_The_End(string_2);

     for (; (the_end_of_string_1 != string_1) || (the_end_of_string_2 != string_2);)
         {
          if (*string_1 > *string_2)
              return 1;

          if (*string_1 < *string_2)
              return -1;

          if (*string_1 == *string_2)
              return 0;

          string_1++;
          string_2++;
         }
    }

//-----------------------------------------------------------------------------

/*!
  Compares strings (reverse alphabetical order)
  \param[in] str_1 - first string
  \param[in] str_2 - second string
*/

int Compile_2(const void* str_1, const void* str_2)
    {
	 assert(str_1);
	 assert(str_2);

	 char* string_1 = *(char**) str_1;
     char* string_2 = *(char**) str_2;

     char* the_end_of_string_1 = To_The_End(string_1);
     char* the_end_of_string_2 = To_The_End(string_2);

     for (; (the_end_of_string_1 != string_1) || (the_end_of_string_2 != string_2);)
         {
          if (*string_1 < *string_2)
              return 1;

          if (*string_1 > *string_2)
              return -1;

          if (*string_1 == *string_2)
              return 0;

          string_1++;
          string_2++;
         }
    }

//-----------------------------------------------------------------------------

/*!
  Goes to the end of the string
  \param[in] string_x - string
  \return string_x + index - address of the end of the string
*/

char* To_The_End (char* string_x)
    {
     int num_of_element = 0;

     while (string_x[num_of_element++] != '\0');

     num_of_element--;

     return string_x + num_of_element;
    }
