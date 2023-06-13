#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void find(const char *dir_path, const char *search_term) {
	    DIR *dir = opendir(dir_path);
	        if (dir == NULL) {
			        perror("opendir");
				        return;
					    }
 struct dirent *entry;
     while ((entry = readdir(dir)) != NULL) {
	             if (strcmp(entry->d_name, search_term) == 0) {
			                 printf("%s/%s\n", dir_path, entry->d_name);
					         }
if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
	            char sub_dir_path[PATH_MAX];
		                snprintf(sub_dir_path, sizeof(sub_dir_path), "%s/%s", dir_path, entry->d_name);
				            find(sub_dir_path, search_term);
					            }
    }
  closedir(dir);
}

int main(int argc, char *argv[]) {
	    if (argc != 3) {
		            printf("Usage: ./find <directory> <search_term>\n");
			            return 1;
				        }
 char *directory = argv[1];
     char *search_term = argv[2];

         find(directory, search_term);

	     return 0;
}

