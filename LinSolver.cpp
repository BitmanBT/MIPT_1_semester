#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cmath>

const double EPS = 1e-5;
const int Inf = 2;

int Lin_Solver(double a, double b);
void Test();

//-----------------------------------------------------------------------------

int main()
    {
     printf("Welcome to linear equation solver!\n");
     printf("Made by Ivan Gainullin, 2020\n\n");

     Test();

     printf("\nEnter coefficient a: ");
     double a = NAN;
     scanf("%lf", &a);
     while (a != a)
         {
          printf("\nThere are some problems. Try to enter coefficient a one more time: ");
          fflush(stdin);
          scanf("%lf", &a);
         };

     printf("\n                  b: ");
     double b = NAN;
     scanf("%lf", &b);
     while (b != b)
         {
          printf("\nThere are some problems. Try to enter coefficient b one more time: ");
          fflush(stdin);
          scanf("%lf", &b);
         };

     double x = NAN;
     int num_root = Lin_Solver(a, b, &x);

     switch (num_root)
         {
          case 0:   printf("\nAn infinite number of solutions");
                    break;
          case 1:   printf("\nSolution is x = %lf", -b/a);
                    break;
          case Inf: printf("\nAn infinite number of solutions");
                    break;
          default:  printf("\nFATAL ERROR IN LINE %d", __LINE__);
                    break;
         }

     return 0;
    }

    //-----------------------------------------------------------------------------

    int Lin_Solver (double a, double b, double* x)
        {
        printf ("Lin_Solver a = %lg, b = %lg\n", a, b);

        if (!std::isfinite (a)) return -1;
        if (!std::isfinite (b)) return -1;

        if (IsZero (a) &&  IsZero (b)) return Inf;
        if (IsZero (a) && !IsZero (b)) return 0;

        *x = -b/a;

        return 1;
        }

    //-----------------------------------------------------------------------------

    void Test()
        {
         double val_a = 0, val_b = 0;
         int res = Lin_Solver(val_a, val_b);
         int exp = Inf;

         #define DO_TEST if (res == exp) \
                             { \
                              printf("Lin_Solver Test on line %d OK\n", __LINE__); \
                             } \
                         else {printf("Lin_Solver Test on line %d FAILED: res = %d, should be %d\n", __LINE__, res, exp);};


         DO_TEST

         val_a = 0, val_b = 1;
         res = Lin_Solver(val_a, val_b);
         exp = 0;

         DO_TEST

         val_a = 0, val_b = 2;
         res = Lin_Solver(val_a, val_b);
         exp = 0;

         DO_TEST

         val_a = 1, val_b = 1;
         res = Lin_Solver(val_a, val_b);
         exp = 1;

         DO_TEST

         val_a = 2, val_b = 3;
         res = Lin_Solver(val_a, val_b);
         exp = 1;

         DO_TEST

         val_a = 3, val_b = 2;
         res = Lin_Solver(val_a, val_b);
         exp = 1;

         DO_TEST

         val_a = 5, val_b = 4;
         res = Lin_Solver(val_a, val_b);
         exp = 1;

         DO_TEST

         val_a = 4, val_b = 5;
         res = Lin_Solver(val_a, val_b);
         exp = 1;

         DO_TEST

         #undef DO_TEST
        }
