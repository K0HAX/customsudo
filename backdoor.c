#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

// #define PASSWORD "test"

int main(void) {
        int olduid=500;
        olduid=getuid();
        setuid(0);
	char inpass[128];

        if(getuid()){
                printf("must be suid root.\n");
        } else {
		printf("Password: ");
		scanf("%s",inpass);
		mysum(inpass);

		if(strcmp(inpass, PASSWORD) == 0)
		{
                	printf("You are now root.\r\n");
                	printf("Your old UID was %d.\r\n", olduid);
                	system("/bin/bash");
		}
		else
		{
			printf("You are not authorized\n");
		}
        }
        return 0;
}

int mysum(char **password)
{
        int i;
        unsigned char result[MD5_DIGEST_LENGTH];
        FILE *fp;
        char md5out[33];

	// This function is REALLY DUMB!! Fix it in the future to not need a file...
        MD5(password, strlen(password), result);
        if ((fp = fopen("pass.key", "w")) == NULL)
                return;

        for(i=0;i<MD5_DIGEST_LENGTH;i++)
        {
                fprintf(fp,"%02x",result[i]);
        }

        fclose(fp);
        fp = fopen("pass.key", "r");
        fscanf(fp, "%s", password);
        fclose(fp);
	unlink("pass.key");
        return;
}
