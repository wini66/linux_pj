#include <dirent.h>

int main()
{	
	
	    
	    DIR *dir = opendir(".");
	        if (dir == NULL) {
			        perror("opendir");
				        exit(EXIT_FAILURE);
					    }

		   
		    struct dirent *entry;
		        while ((entry = readdir(dir)) != NULL) {
				        printf("%s\n", entry->d_name);
					    }

			    
			    closedir(dir);

			        return 0;
}
