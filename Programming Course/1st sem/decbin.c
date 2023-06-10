#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int);

int main()
{
  int n, dec;
  char *p;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &dec);
    p = decimal_to_binary(dec);
  }

while (p != NULL) {
     printf("Binary string of %d is: %s\n", dec, p);
}


  free(p);

  return 0;
}

char *decimal_to_binary(int n)
{
  int c, d, t;
  char *p;

  t = 0;
  p = (char*)malloc(32+1);

  if (p == NULL)
    exit(EXIT_FAILURE);

  for (c = 31 ; c >= 0 ; c--)
  {
    d = n >> c;

    if (d & 1)
      *(p+t) = 1 + '0';
    else
      *(p+t) = 0 + '0';

    t++;
  }
  *(p+t) = '\0';

  return  p;
}