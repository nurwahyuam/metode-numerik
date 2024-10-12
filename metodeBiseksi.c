#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

// X Awal = 2.5
// X Akhir = 2.6
// Batasan Error = 0.005

float fungsi(float x){
  return x*x*x - 7*x + 1;
}

int main(){
  int i = 0;
  float x, y, z, e;
  system("cls");
  printf("==================================================================\n");
  printf("|                         Metode Biseksi                         |\n");
  printf("==================================================================\n");
  printf("> Masukan Nilai X Awal: ");
  scanf("%f", &x);
  printf("\n> Masukan Nilai X Akhir: ");
  scanf("%f", &y);
  printf("\n> Masukan Batas Error: ");
  scanf("%f", &e);
  printf("==================================================================");
  getch();

  system("cls");
  printf("==================================================================\n");
  printf("|                         Metode Biseksi                         |\n");
  printf("==================================================================\n");
  printf("|i|    x    |    y    |    z    |   f(x)   |   f(y)   |   f(z)   |\n");
  printf("------------------------------------------------------------------\n");
  do {
    i++;
    z = (x + y) / 2;
    printf("|%d|  %.4f |  %.4f |  %.4f ", i, x, y, z);
    (fungsi(x) > 0) ? printf("|  %.4f  ",  fungsi(x)) : printf("|  %.4f ",  fungsi(x));
    (fungsi(y) > 0) ? printf("|  %.4f  ",  fungsi(y)) : printf("| %.4f  ",  fungsi(y));
    (fungsi(z) > 0) ? printf("|  %.4f  |\n",  fungsi(z)) : printf("| %.4f  |\n",  fungsi(z));
    (fungsi(z) * fungsi(x) > 0) ? (x = z) : (y = z);
  } while (fabs(fungsi(z)) > e);

  printf("==================================================================\n");
  printf("Nilai Error: %.4f di X: %.4f\n", fungsi(z), z);
  printf("==================================================================\n");

  return 0;
}