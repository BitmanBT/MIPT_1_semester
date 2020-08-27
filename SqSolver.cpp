#include <stdio.h>
#include <math.h>

int SqSolver(double a1, double b1, double c1, double *x1, double *x2) {
                                                                      if (a1 == 0) {
                                                                                    if (b1 == 0) {
                                                                                                  if (c1 == 0) {
                                                                                                                return(3);
                                                                                                               }
                                                                                                  else {
                                                                                                        return(0);
                                                                                                       };
                                                                                                 }
                                                                                     else {
                                                                                           x1 = -c1/b1;
                                                                                           return(1);
                                                                                          };
                                                                                   }
                                                                     else {
                                                                           double d = b1*b1 - 4*a1*c1;
                                                                           if (d < 0) {
                                                                                       return (0);
                                                                                      }
                                                                           else if (d = 0) {
                                                                                          x1 =(-b1 + sqrt(d))/2/a1;
                                                                                          return(1);
                                                                                         }
                                                                           else {
                                                                                 x1 = (-b1 + sqrt(d))/2/a1;
                                                                                 x2 = (-b1 - sqrt(d))/2/a1;
                                                                                 return(2);
                                                                                }
                                                                          }
                                                                     }

int main()
   {
    printf("Welcome to the Quadratic Equation Solver!\n"
           "Made by Ivan Gainullin, 2020\n");
    printf("Enter coefficients a, b and c\n");
    double a, b, c, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    int NumRoots = SqSolver(a, b, c,*x1,*x2);
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
