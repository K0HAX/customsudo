#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
  int i;
  char test[128];
  unsigned char result[MD5_DIGEST_LENGTH];

  scanf("%s",test);

  MD5(test, strlen(test), result);

  // output
  for(i = 0; i < MD5_DIGEST_LENGTH; i++)
    printf("%02x", result[i]);
  printf("\n");
  return EXIT_SUCCESS;
}
