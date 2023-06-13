#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void list_files(const char *directory_path, int show_hidden, int show_size, int show_recursive) {
	    DIR *dir = opendir(directory_path);
	        if (dir == NULL) {
			        perror("opendir");
				        exit(EXIT_FAILURE);
					    }
 struct dirent *entry;
     while ((entry = readdir(dir)) != NULL) {
	            
	             if (!show_hidden && entry->d_name[0] == '.')
			                 continue;

		            
		             printf("%s", entry->d_name);

			             
			             if (show_size) {
					                 struct stat file_stat;
							             char file_path[PATH_MAX];
								                 snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
										             if (stat(file_path, &file_stat) == 0) {
												                     printf(" (%lld bytes)", (long long)file_stat.st_size);
														                 }
											             }
printf("\n");

       
        if (show_recursive && entry->d_type == DT_DIR && strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
		            char sub_dir_path[PATH_MAX];
			                snprintf(sub_dir_path, sizeof(sub_dir_path), "%s/%s", directory_path, entry->d_name);
					            list_files(sub_dir_path, show_hidden, show_size, show_recursive);
						            }
	    }

         closedir(dir);
}

int main(int argc, char *argv[]) {
	    const char *directory_path = ".";
	        int show_hidden = 0;        
		    int show_size = 0;         
		        int show_recursive = 0;     

  for (int i = 1; i < argc; i++) {
if (argv[i][0] == '-') {
	for (int j = 1; argv[i][j]; j++) {
		switch (argv[i][j]) {
			  case 'a':
				  show_hidden = 1;
				  break;
				   case 'l':
				  show_size = 1;
				   break;
				   case 'R':
				   show_recursive = 1;
				    break;
				     default:
				    fprintf(stderr, "Unknown option: %c\n", argv[i][j]);
				    exit(EXIT_FAILURE);
				      }
		 }
} else {
	directory_path = argv[i];
	 }
 }

list_files(directory_path, show_hidden, show_size, show_recursive);

    return 0;
    }

