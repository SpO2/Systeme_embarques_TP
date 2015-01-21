/*********************************************************************/
/* Author: Romain Toma                                               */
/* Program: Nombres premier sur nombre aléatoire. (%1000)            */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#define RANDOMPATH "/dev/random"

int main(){
  int fp, ret, i, j, diviseur;
  unsigned int rand;

  fp = open(RANDOMPATH, O_RDONLY);
  if (fp < 0)
  {
    printf("Could not open -%s- for reading.\n",RANDOMPATH);
    return -1;
  }
  ret = read(fp, &rand, sizeof(rand));
  if (ret < 0)
  {
    printf("Could not read from -%s-.\n", RANDOMPATH);
    close(fp);
    return ret;
  }
  close(fp);
  rand = rand%100;
  printf("Nombre aleatoire : %d\r\n", rand); 
  for (i=2; i<=rand; i++)
  {
    diviseur = 0;
    for (j=1; j<=i; j++)
    {
      if (i%j==0)
      {
        diviseur++;
      }
    }
    if (diviseur == 2)
    {
      printf("%d\r\n", i);
    }
  } 
  
  return 0;
}
