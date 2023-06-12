#include <stdio.h>
#include <sys/utsname.h>

int main() {
	    struct utsname sys_info;
	        if (uname(&sys_info) == -1) {
			        perror("uname");
				        return 1;
					    }

		    printf("System name: %s\n", sys_info.sysname);
		        printf("Node name: %s\n", sys_info.nodename);
			    printf("Release: %s\n", sys_info.release);
			        printf("Version: %s\n", sys_info.version);
				    printf("Machine: %s\n", sys_info.machine);

				        return 0;
}

