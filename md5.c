#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
  int i;
  int n;
  char test[128];
  unsigned char result[MD5_DIGEST_LENGTH];
  char sStringOut[512];

  scanf("%s",test);

  MD5(test, strlen(test), result);

  n = 0;
  for(i = 0; i < MD5_DIGEST_LENGTH; i++)
  {
    sprintf(&sStringOut[n], "%02x", result[i]);
    n = n + 2;
  }
  printf("%s\n", sStringOut);

  return EXIT_SUCCESS;
}
