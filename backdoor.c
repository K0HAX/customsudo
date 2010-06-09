#include <stdio.h>

int main(void) {
        int olduid=500;
        olduid=getuid();
        setuid(0);
        if(getuid()){
                printf("must be suid root.\n");
        } else {
                printf("You are now root.\r\n");
                printf("Your old UID was %d.\r\n", olduid);
                system("/bin/bash");
        }
        return 0;
}
