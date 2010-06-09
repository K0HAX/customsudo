#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
  int i;
  char test[128];
  unsigned char result[MD5_DIGEST_LENGTH];
  FILE *fp;
  char md5out[33];
  char md5test2[33];

  scanf("%s",test);

  // really stupid hack to get MD5 back into something useful...
  MD5(test, strlen(test), result);
  if ((fp = fopen("pass.key", "w")) == NULL)
	return;

  // output
  for(i = 0; i < MD5_DIGEST_LENGTH; i++)
  {
    //printf("%02x", result[i]);
    fprintf(fp,"%02x", result[i]);
  }
  //printf("\n");

  fclose(fp);
  fp = fopen("pass.key", "r");
  fscanf(fp, "%s", md5out);
  printf("%s\n", md5out);
  fclose(fp);

  return EXIT_SUCCESS;
}
