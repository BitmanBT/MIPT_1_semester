#include <stdio.h>
#include <math.h>
#include <assert.h>

const int Infinite = 3;

const double EPS = 1e-6;

int SqSolver(double a, double b, double c, double* x1, double* x2);

int LinSolver(double a, double b, double* x);

bool IfNull(double a);

double GetCoeff(const char* Var);

double Discriminant(double a, double b, double c);

double Root1(double a, double b, double d);

double Root2(double a, double b, double d);

void Test_SqSolver();

void Test_LinSolver();

void Test_Discriminant();

void Test_Root1();

void Test_Root2();

void Test_IfNull();

//-----------------------------------------------------------------------------

int main()
   {
    printf("Welcome to the Quadratic Equation Solver!\n"
           "Made by Ivan Gainullin, 2020\n");

    Test_SqSolver();
    Test_LinSolver();
    Test_Discriminant();
    Test_Root1();
    Test_Root2();
    Test_IfNull();

    double a = GetCoeff("aa");
    double b = GetCoeff("bb");
    double c = GetCoeff("cc");

    double x1 = NAN,
           x2 = NAN;

    int NumRoots = SqSolver(a, b, c, &x1, &x2);

    switch (NumRoots){
                      case 0:        printf("No Roots\n");
                                     break;

                      case 1:        printf("One root, x = %lf\n", x1);
                                     break;

                      case 2:        printf("Two Roots, x1 = %lf, x2 = %lf\n", x1, x2);
                                     break;

                      case Infinite: printf("All numbers are roots\n");
                                     break;

                      default:       printf("Unknown error: NumRoots = %d", NumRoots);
                                     break;
                     }
    return 0;
   }

//-----------------------------------------------------------------------------

/*!
  Function that solves a quadratic equation
  \param[in] a Square trinomial coefficient
  \param[in] b Square trinomial coefficient
  \param[in] c Square trinomial coefficient
  \param[out] x1 Pointer to a variable to store the first root
  \param[out] x2 Pointer to a variable to store the first root
  \return Number of roots
*/

int SqSolver(double a, double b, double c, double* x1, double* x2)
    {
     assert(x1 != x2);
     assert(a == a);
     assert(b == b);
     assert(c == c);


     if (IfNull(a))
         return LinSolver(b, c, x1);


     if (IfNull(c))
         {
          *x1 = 0;
          return 1 + LinSolver(a, b, x2);
         };


     double d = Discriminant(a, b, c);


     if (d > 0)
         {
          *x1 = Root1(a, b, d);
          *x2 = Root2(a, b, d);
          return 2;
         }
     else if (IfNull(d))
         {
          *x1 = Root1(a, b, d);
          return 1;
         }
     else
         {
          return 0;
         }
    }

//-----------------------------------------------------------------------------

/*!
  Function that solves a linear equation
  \param[in] a Linear binominal coefficient
  \param[in] b Linear binominal coefficient
  \param[in] c Linear binominal coefficient
  \param[out] x Pointer to a variable to store the root
  \return Number of roots
*/

int LinSolver(double a, double b, double* x)
        {
         if (IfNull(a))
             {
              if (IfNull(b))
                  {
                   return Infinite;
                  }
              else
                  {
                   return 0;
                  };
             }
         else
             {
              *x = -b/a;
              return 1;
             };
        }

//-----------------------------------------------------------------------------

/*!
  Function that finds the discriminant
  \param[in] a Square trinomial coefficient
  \param[in] b Square trinomial coefficient
  \param[in] c Square trinomial coefficient
  \return Discriminant
*/

double Discriminant(double a, double b, double c)
    {
     double d = b*b-4*a*c;
     return d;
    }

//-----------------------------------------------------------------------------

/*!
  A function that finds the first (or only) root of a square trinomial, if it exists
  \param[in] a Square trinomial coefficient
  \param[in] b Square trinomial coefficient
  \param[in] d Discriminant
  \return Root
*/

double Root1(double a, double b, double d)
    {
     double x1 = (-b + sqrt(d))/2/a;
     return x1;
    }

//-----------------------------------------------------------------------------

/*!
  A function that finds the second root of a square trinomial, if it exists
  \param[in] a Square trinomial coefficient
  \param[in] b Square trinomial coefficient
  \param[in] d Discriminant
  \return Root
*/

double Root2(double a, double b, double d)
    {
     double x2 = (-b - sqrt(d))/2/a;
     return x2;
    }

//-----------------------------------------------------------------------------

/*!
  A function that takes variable values
  \param[in] Var The name of the variable
  \return Variable value
*/

double GetCoeff(const char* Var)
    {
     int ScanVar = 0;

     double res = NAN;

     printf("Enter coefficient %s: ", Var);

     ScanVar = scanf("                      %lf", &res);

     while (ScanVar == 0)
         {
          printf("\nThere are some problems. Try to enter coefficient %s one more time: ", Var);
          fflush(stdin);
          ScanVar = scanf("%lf", &res);
         };

     return res;
    }

//-----------------------------------------------------------------------------

/*!
  A function that checks if the number is 0 (or very close to 0)
  \param[in] Number
  \return 1 if '0' (or close), 0 if not
*/

bool IfNull(double a)
    {
     if (fabs(a) < EPS)
         {
          return 1;
         }
     else return 0;
    }

//-----------------------------------------------------------------------------

void Test_SqSolver()
    {
     double x1, x2;

     double val_a = 0, val_b = 0, val_c = 0;
     int res = SqSolver(val_a, val_b, val_c, &x1, &x2);
     int exp = Infinite;

     #define DO_TEST if (SqSolver(val_a, val_b, val_c, &x1, &x2) == exp) \
                         { \
                          printf("SqSolver Test on line %d OK\n", __LINE__); \
                         } \
                     else \
                         { \
                          printf("SqSolver Test on line %d FAILED: SqSolver(%g, %g, %g) == %d, should be %d\n", __LINE__, val_a, val_b, val_c, res, exp); \
                         };

     DO_TEST

     val_a = 0, val_b = 0, val_c = 1;
     res = SqSolver(val_a, val_b, val_c, &x1, &x2);
     exp = 0;

     DO_TEST

     val_a = 0, val_b = 1, val_c = 1;
     res = SqSolver(val_a, val_b, val_c, &x1, &x2);
     exp = 1;

     DO_TEST

     val_a = 4, val_b = 7, val_c = 2;
     res = SqSolver(val_a, val_b, val_c, &x1, &x2);
     exp = 2;

     DO_TEST

     #undef DO_TEST
    }

//-----------------------------------------------------------------------------

void Test_LinSolver()
    {
     double x = NAN;

     double val_a = 0, val_b = 0;
     int res = LinSolver(val_a, val_b, &x);
     int exp = Infinite;

     #define DO_TEST if (res == exp) \
                         { \
                          printf("LinSolver Test on line %d OK\n", __LINE__); \
                         } \
                     else \
                         { \
                          printf("LinSolver Test on line %d FAILED: res = %d, should be %d\n", __LINE__, res, exp); \
                         };


     DO_TEST

     val_a = 0, val_b = 1;
     res = LinSolver(val_a, val_b, &x);
     exp = 0;

     DO_TEST

     val_a = 0, val_b = 2;
     res = LinSolver(val_a, val_b, &x);
     exp = 0;

     DO_TEST

     val_a = 1, val_b = 1;
     res = LinSolver(val_a, val_b, &x);
     exp = 1;

     DO_TEST

     val_a = 2, val_b = 3;
     res = LinSolver(val_a, val_b, &x);
     exp = 1;

     DO_TEST

     val_a = 3, val_b = 2;
     res = LinSolver(val_a, val_b, &x);
     exp = 1;

     DO_TEST

     val_a = 5, val_b = 4;
     res = LinSolver(val_a, val_b, &x);
     exp = 1;

     DO_TEST

     val_a = 4, val_b = 5;
     res = LinSolver(val_a, val_b, &x);
     exp = 1;

     DO_TEST

     #undef DO_TEST
    }

//-----------------------------------------------------------------------------

void Test_Discriminant()
    {
     double val_a = 2, val_b = 5, val_c = 2;
     double res = Discriminant(val_a, val_b, val_c);
     double exp = 9;

     if (fabs(exp-res) < EPS)
         {
          printf("Discriminant Test on line %d OK\n", __LINE__);
         }
     else
         {
          printf("Discriminant Test on line %d FAILED: Discriminant(%g, %g, %g) == %g, should be %g\n", __LINE__, val_a, val_b, val_c, res, exp);
         }
    }

//-----------------------------------------------------------------------------

void Test_Root1()
    {
     double val_a = 2, val_b = 1, val_d = 9;
     double res = Root1(val_a, val_b, val_d);
     double exp = 0.5;

     if (fabs(exp-res) < EPS)
         {
          printf("Root1 Test on line %d OK\n", __LINE__);
         }
     else
         {
          printf("Root1 Test on line %d FAILED: Root1(%g, %g, %g) == %g, should be %g\n", __LINE__, val_a, val_b, val_d, res, exp);
         }
    }

//-----------------------------------------------------------------------------

void Test_Root2()
    {
     double val_a = 2, val_b = 1, val_d = 9;
     double res = Root2(val_a, val_b, val_d);
     double exp = -1;

     if (fabs(exp-res) < EPS)
         {
          printf("Root2 Test on line %d OK\n", __LINE__);
         }
     else
         {
          printf("Root2 Test on line %d FAILED: Root2(%g, %g, %g) == %g, should be %g\n", __LINE__, val_a, val_b, val_d, res, exp);
         }
    }

//-----------------------------------------------------------------------------

void Test_IfNull()
    {
     double a = 0;
     bool exp = 1;
     bool res = IfNull(a);

     if (res == exp)
         {
          printf("IfNull Test on line %d OK\n", __LINE__);
         }
     else
         {
          printf("IfNull Test on line %d FAILED: res = 0, should be 1\n", __LINE__);
         };

     a = 5;
     exp = 0;
     res = IfNull(a);

     if (res == exp)
         {
          printf("IfNull Test on line %d OK\n", __LINE__);
         }
     else
         {
          printf("IfNull Test on line %d FAILED: res = 1, should be 0\n", __LINE__);
         };
    }



