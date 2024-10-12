#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

double fungsi(double x){
  return x*x*x + x*x - 3*x - 3;
}
double fungsiTurunan(double x){
  return 3*x*x + 2*x -3;
}
int main(){
  int i = 0;
  float x, y, e;
  system("cls");
  printf("===============================================================");
    printf("\n|                   Metode Newton Raphson                     |\n");
    printf("===============================================================\n");
  printf("> Masukan Nilai X: ");
  scanf("%f", &x);
  printf("\n> Masukan Batasan Error: ");
  scanf("%f", &e);
  printf("===============================================================");
  getch();

  system("cls");
    printf("===============================================================");
    printf("\n|                   Metode Newton Raphson                     |\n");
    printf("===============================================================\n");
    printf("| i |      x      |      y      |     f(x)     |     f(y)     |\n");
    printf("---------------------------------------------------------------\n");
  do {
    i++;
    fungsi(x);
    fungsiTurunan(x);
    if (fungsiTurunan(x) == 0){
      printf("Turunan bernilai 0. Metode tidak dapat dilanjutkan.\n");
      return 0;
    }
    y = x - (fungsi(x) / fungsiTurunan(x));
    fungsi(y);
    printf("| %d ", i);
    (x > 0) ? printf("|    %.4f   ", x) : printf("|   %.4f   ", x);
    (y > 0) ? printf("|    %.4f   ", y) : printf("|   %.4f   ", y);
    (fungsi(x) >= 10 || fungsi(x) < 0) ? printf("|   %.4f    ", fungsi(x)) : printf("|    %.4f    ", fungsi(x));
    (fungsi(y) >= 10 || fungsi(y) < 0) ? printf("|   %.4f    |\n", fungsi(y)) : printf("|    %.4f    |\n", fungsi(y));
    x = y;
  } while (fabs(fungsi(y)) > e);

  printf("===============================================================\n");
  printf("Nilai Error adalah %.4f di titik X = %.4f\n", fungsi(y), y);
  printf("===============================================================\n");
  
  return 0;
}