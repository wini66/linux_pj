#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void print_process_info(const char *pid) {
	char file_path[256];
	    snprintf(file_path, sizeof(file_path), "/proc/%s/status", pid);
	        FILE *fp = fopen(file_path, "r");
		    if (fp == NULL) {
			            perror("fopen");
				            return;
					        }
char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
	            if (strncmp(line, "Name:", 5) == 0 || strncmp(line, "State:", 6) == 0) {
			                printf("%s", line);
					        }
		        }

        fclose(fp);
}

int main() {
	    DIR *dir = opendir("/proc");
	        if (dir == NULL) {
			        perror("opendir");
				        exit(EXIT_FAILURE);
					    }
struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
	    if (entry->d_type == DT_DIR) {
		                if (atoi(entry->d_name) != 0) {
					                print_process_info(entry->d_name);
							            }
				        }
	        }

    closedir(dir);
        return 0;
}

