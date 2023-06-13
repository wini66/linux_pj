#include <stdio.h>
#include <signal.h>

int running = 1;

void sigint_handler(int signum) {
	    running = 0;
}

int main() {
	     
	         signal(SIGINT, sigint_handler);
	    
	             while (running) {
	                     printf("yes\n");
	                         }
	    
	                             return 0;
	                            }

