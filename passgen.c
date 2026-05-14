#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define notif(sum, bdy) do { char _cmd[256]; snprintf(_cmd, sizeof(_cmd), "notify-send -t 1000 '%s' '%s'", sum, bdy); int _ret = system(_cmd); (void)_ret; } while (0)

const int MIN_LEN = 1;
const int MAX_LEN = 64;

int main(int argc, char *argv[])
{
    if(argc !=3 || strcmp(argv[1],"-l") != 0) {
    	notif("passgen", "missing argument: -l <length>");
    	return 1;
	}

    int len = atoi(argv[2]);
    if(len < MIN_LEN || len > MAX_LEN) {
        char msg[64];
        snprintf(msg, sizeof(msg), "invalid length: must be %i-%i", MIN_LEN, MAX_LEN);
    	notif("passgen", msg);
    	return 2;
	}

    const char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%&*(){}[]";
    char password[len+1];

    unsigned int seed;
    int urand = open("/dev/urandom", O_RDONLY);
    if(urand < 0 || read(urand, &seed, sizeof(seed)) != sizeof(seed)) 
	{
        seed = time(NULL) ^ (getpid() << 16);
    }
	if(urand >= 0) 
	{
        close(urand);
    }
    srand(seed);

    for(int i=0; i<len; i++)
        password[i] = chars[rand() % (sizeof(chars)-1)];
    password[len] = '\0';

    char cmd[256];
    snprintf(cmd, sizeof(cmd), "copyq copy '%s' && copyq add '%s'", password, password);

    if(system(cmd) != 0)
    {
    	notif("passgen", "failed to copy password to clipboard");
    	return 3;
    }

    return 0;
}
