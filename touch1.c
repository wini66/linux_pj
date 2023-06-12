#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	    int fd;
	        if (argc < 2) {
			        return 1;
				    }
 fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
     close(fd);
         return 0;
}

