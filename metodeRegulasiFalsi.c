#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

double fungsi(double x)
{
  return (x * x * x) - (x * 7) + 1;
}

int main()
{
  double x1, x2, x3, a, b, c, e, status;
  int i = 1;

  system("cls");
  printf("=============================================================");
  printf("\n|                    Metode Regulasi Falsi                  |\n");
  printf("=============================================================");
  printf("\n> Masukkan nilai batas atas: ");
  scanf("%lf", &x1);
  printf("\n> Masukkan nilai batas bawah: ");
  scanf("%lf", &x2);
  printf("\n> Masukkan nilai toleransi: ");
  scanf("%lf", &e);
  printf("=============================================================");
  getch();

  system("cls");
  printf("=============================================================");
  printf("\n|                    Metode Regulasi Falsi                  |\n");
  printf("=============================================================");
  a = fungsi(x1);
  b = fungsi(x2);

  x3 = x1 - (a * ((x2 - x1) / (b - a)));
  c = fungsi(x3);
  printf("\nIterasi %d\n> Nilai Xa = %.3lf, f(Xa) = %.4lf\n> Nilai Xb = %.3lf, f(Xb) = %.4lf\n> Nilai Xc = %.3lf, f(Xc) = %.4lf\n", i, x1, a, x2, b, x3, c);
  printf("=============================================================");
  status = c * -1;

  while (status >= e)
  {
    i++;
    if (a * c > 0)
    {
      x1 = x3;
      a = fungsi(x1);
      x3 = x1 - (a * ((x2 - x1) / (b - a)));
      c = fungsi(x3);
      printf("\nIterasi %d\n> Nilai Xa = %.3lf, f(Xa) = %.4lf\n> Nilai Xb = %.3lf, f(Xb) = %.4lf\n> Nilai Xc = %.3lf, f(Xc) = %.4lf\n", i, x1, a, x2, b, x3, c);
      printf("=============================================================");
    }
    else if (b * c > 0)
    {
      x2 = x3;
      a = fungsi(x2);
      x3 = x1 - (a * ((x2 - x1) / (b - a)));
      c = fungsi(x3);
      printf("\nIterasi %d\n> Nilai Xa = %.3lf, f(Xa) = %.4lf\n> Nilai Xb = %.3lf, f(Xb) = %.4lf\n> Nilai Xc = %.3lf, f(Xc) = %.4lf\n", i, x1, a, x2, b, x3, c);
      printf("=============================================================");
    }
    else
    {
      printf("\nError\n");
      printf("=============================================================");
      break;
    }
    status = c * -1;
  }

  printf("\nJadi Nilai Error adalah x = %.3lf, f(x) = %.4lf\n", x3, c);
  printf("=============================================================");
  return 0;
}