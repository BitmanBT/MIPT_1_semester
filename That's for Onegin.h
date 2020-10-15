#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stddef.h>

/*!
  Function that reads the file and creates array of pointers for it
  \param[out] number_of_strings - points on the number of strings file contain
  \return Array_Of_Pointers - the beginning of the array of the pointers
*/

char** Read_File_And_Create_Array_Of_Pointers(size_t* number_of_strings);

//-----------------------------------------------------------------------------

/*!
  Function that reads the file
  \param[in] input_file - pointer to the file
  \return array_of_strings - array that contains text from the file
*/

char* Read_File(FILE* input_file);

//-----------------------------------------------------------------------------

/*!
  Function, that counts length of the file (in symbols)
  \param[in] input_file - pointer to the file
  \return length - the length of the file (in symbols)
*/

size_t Count_Length(FILE* input_file);

//-----------------------------------------------------------------------------

/*!
  Function that counts the number of strings text of the file contains
  \param[in] array_of_strings - array that contains text from the file
  \return number_of_strings - number of strings file contains
*/

size_t Count_Strings(char* array_of_strings);

//-----------------------------------------------------------------------------

/*!
  \param[in] array_of_strings - pointer to the array which contains text from the file
  \param[in] number_of_strings - number of strings file contains
  \return Array_Of_Pointers - pointer to the beginning of the array of pointers
*/

char** Create_Array_Of_Pointers(char* array_of_strings, size_t number_of_strings);

//-----------------------------------------------------------------------------

/*!
  Function that writes into the file
  \param[in] Array_Of_Pointers - pointer to the beginning of the array of pointers
  \param[in] number_of_strings - number of strings file contains
*/

void Write_File(char** Array_Of_Pointers, size_t number_of_strings);

//-----------------------------------------------------------------------------

/*!
  Function that puts '\0' instead of '\n' in the array_of_strings
  \param[in] Array_Of_Pointers - pointer to the beginning of the array of pointers
  \param[in] number_of_strings - number of strings file contains
*/

void Put_Zeros(char** Array_Of_Pointers, size_t number_of_strings);

//-----------------------------------------------------------------------------

/*!
  Compares strings (alphabetical order)
  \param[in] str_1 - first string
  \param[in] str_2 - second string
*/

int Compile_1(const void* str_1, const void* str_2);

//-----------------------------------------------------------------------------

/*!
  Compares strings (reverse alphabetical order)
  \param[in] str_1 - first string
  \param[in] str_2 - second string
*/

int Compile_2(const void* str_1, const void* str_2);

//-----------------------------------------------------------------------------

/*!
  Goes to the end of the string
  \param[in] string_x - string
  \return string_x + index - address of the end of the string
*/

char* To_The_End(char* string_x);
