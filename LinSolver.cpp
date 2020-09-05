#include <stdio.h>
#include <math.h>
#include <assert.h>

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

     printf("Enter coefficient a: ");
     double a;
     scanf("%lf", &a);

     printf("\n                  b: ");
     double b;
     scanf("%lf", &b);

     int num_root = Lin_Solver(a, b);

     return 0;
    }

    //-----------------------------------------------------------------------------

    int Lin_Solver(double a, double b)
        {
         assert(a);
         assert(b);

         if (fabs(a) < EPS)
          {
           if (fabs(b) < EPS)
               {
                printf("\nAn infinite number of solutions");
                return Inf;
                }
           else
               {
                printf("\nNo solutions");
                return 0;
                };
          }
      else
          {
           printf("\nSolution is x = %lf", -b/a);
           return 1;
           };
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
                         else {printf("Lin_Solver Test on line %d FAILED: res = %d, should be %d\n" __LINE__, res, exp);};

         DO_TEST

         val_a = 0, val_b = 1;
         res = Lin_Solver(val_a, val_b);
         exp = 0;

         DO_TEST

         val_a = 1, val_b = 1;
         res = Lin_Solver(val_a, val_b);
         exp = 1;

         DO_TEST

         #undef DO_TEST
        }
