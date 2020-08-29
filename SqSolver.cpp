#include <stdio.h>
#include <math.h>
#include <assert.h>

const int Infinite = 3;

const double EPS = 1e-5;

int SqSolver(double a, double b, double c, double* x1, double* x2);

double Discriminant(double a, double b, double c);

double Root1(double a, double b, double d);

double Root2(double a, double b, double d);

//-----------------------------------------------------------------------------

int main()
   {
    printf("Welcome to the Quadratic Equation Solver!\n"
           "Made by Ivan Gainullin, 2020\n");
    printf("Enter coefficients a, b and c\n");
    double a, b, c, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    int NumRoots = SqSolver(a, b, c,&x1,&x2);
    switch (NumRoots){
                      case 0: printf("No Roots\n");
                              break;
                      case 1: printf("One root, x = %lf\n", x1);
                              break;
                      case 2: printf("Two Roots, x1 = %lf, x2 = %lf\n", x1, x2);
                              break;
                      default:printf("All numbers are roots\n");
                              break;
                     }
    printf("Press random number\n");
    int random;
    scanf("%d", &random);
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

int SqSolver(double a, double b, double c, double* x1, double* x2) {
    assert(x1);
    assert(x2);
    if (fabs(a) < EPS) {
                        if (fabs(b) < EPS) {
                                            if (fabs(c) < EPS) {
                                                                return Infinite;
                                                                }
                                            else {
                                                  return 0;
                                                  };
                                            }
                        else {
                              *x1 = -c/b;
                              return 1;
                              };
                        }
    else {
          double d = Discriminant(a, b, c);
          if (d < 0) {
                      return 0;
                      }
          else if (fabs(d) < EPS) {
                                   *x1 = Root1(a, b, d);
                                   return 1;
                                   }
          else {
                *x1 = Root1(a, b, d);
                *x2 = Root2(a, b, d);
                return 2;
                }
          }
    }

//-----------------------------------------------------------------------------

/*!
  Function that finds the discriminant
  \param[in] a Square trinomial coefficient
  \param[in] b Square trinomial coefficient
  \param[in] c Square trinomial coefficient
  \return Discriminant
*/

double Discriminant(double a, double b, double c) {
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

double Root1(double a, double b, double d) {
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

double Root2(double a, double b, double d) {
    double x2 = (-b - sqrt(d))/2/a;
    return x2;
    }



