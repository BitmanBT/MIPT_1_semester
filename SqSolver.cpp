#include <stdio.h>
#include <math.h>

int SqSolver(double a, double b, double c, double* x1, double* x2);

double Discriminant(double a, double b, double c);

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
                      case 0: printf("No Roots");
                              break;
                      case 1: printf("One root, x = %lf", x1);
                              break;
                      case 2: printf("Two Roots, x1 = %lf, x2 = %lf", x1, x2);
                              break;
                      default:printf("All numbers are roots");
                              break;
                     }
   }

//-----------------------------------------------------------------------------


int SqSolver(double a, double b, double c, double* x1, double* x2) {
    if (a == 0) {
                  if (b == 0) {
                                if (c == 0) {
                                              return(3);
                                              }
                                else {
                                      return(0);
                                      };
                                }
                  else {
                        *x1 = -c/b;
                        return(1);
                        };
                  }
    else {
          double d = Discriminant(double a, double b, double c);
          if (d < 0) {
                      return (0);
                      }
          else if (d == 0) {
                            *x1 =(-b + sqrt(d))/2/a;
                            return(1);
                            }
          else {
                *x1 = (-b + sqrt(d))/2/a;
                *x2 = (-b - sqrt(d))/2/a;
                return(2);
                }
          }
    }
double Discriminant(double a, double b, double c) {
    double d = b*b-4*a*c;
    return d;
    }


