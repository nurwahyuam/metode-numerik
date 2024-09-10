#include <stdio.h>
#include <math.h>

void metodeTabel()
{
  double x1, x2, e1, e2;
  int n, a, b, c;
  double result = 1;
  double result2 = 1;

  printf("\nMetode Tabel\n");
  printf("Masukan X Awal: ");
  scanf("%lf", &x1);
  printf("Masukan X Akhir: ");
  scanf("%lf", &x2);
  printf("Masukan Range N: ");
  scanf("%d", &n);
  printf("Masukan A dari Fungsi: ");
  scanf("%d", &a);
  printf("Masukan B dari Fungsi: ");
  scanf("%d", &b);
  printf("Masukan C dari Fungsi: ");
  scanf("%d", &c);

  printf("\n=========================");
  printf("\n|======== Tabel ========|\n");
  printf("=========================\n");
  for (int i = 0; i < n; i++)
  {
    double h = (double)(x2 - x1) / n;
    double x = (double)x1 + (i * h);
    // f(x) = x^3 - 4x - 9
    double fungsi = (double)((a * (x * x)) + (b * x) + c);
    double error = fabs(fungsi);
    if (error <= result)
    {
      if (error == result)
      {
        result2 = error;
        e2 = x;
      }
      else
      {
        result = error;
        e1 = x;
      }
    }
    printf("| %.2lf | %.3lf | %.3lf |\n", x, fungsi, error);
  }
  printf("=========================\n");
  if (result == result2)
  {
    printf("Nilai Error di X1 %.2lf dan X2 %.2lf paling terdekat: %.3lf dan %.3lf\n", e1, e2, result, result2);
  }
  else
  {
    printf("Nilai Error di X %.2lf paling terdekat: %.3lf\n", e1, result);
  }
}

double f(double x)
{
  return (x * x * x) - (7 * x) + 1;
}

void metodeBiseksi()
{
  int i = 0;
  double a, b, c, tol;

  printf("\nMetode Biseksi\n");
  printf("Masukan X Awal: ");
  scanf("%lf", &a);
  printf("Masukan X Akhir: ");
  scanf("%lf", &b);
  printf("Masukan Toleransi: ");
  scanf("%lf", &tol);

  if (f(a) * f(b) >= 0)
  {
    printf("Tidak ada akar\n");
    return;
  }

  printf("\n=========================");
  printf("\n|========= Tabel =======|\n");
  printf("=========================\n");

  while ((b - a) / 2 > tol)
  {
    c = (a + b) / 2;

    if (f(c) == 0)
    {
      break;
    }
    printf("Iterasi : %d\n", i + 1);
    printf("a = %.3lf, f(a) = %f\n", a, f(a));
    printf("b = %.3lf, f(b) = %f\n", b, f(b));
    printf("c = %.3lf, f(c) = %f\n", c, f(c));
    printf("=========================\n");

    if (f(a) * f(c) < 0)
    {
      b = c;
    }
    else
    {
      a = c;
    }
    i++;
  }
  printf("Akar ditemukan di: %.3f\n", c);
}

int main()
{
  int pilihan;
  char ulangi;

  do{
    printf("\nMasukan Pilihan Metode Kalian\n1: Metode Tabel,\n2: Metode Biseksi\nPilih Metode: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
      metodeTabel();
      break;
    case 2:
      metodeBiseksi();
      break;
    default:
      printf("Invalid\n");
      break;
    }
    printf("\nLanjut? (y/n): ");
    scanf(" %c", &ulangi);
  } while (ulangi == 'y' || ulangi == 'Y');

  printf("\nProgram Selesai");
  return 0;
}