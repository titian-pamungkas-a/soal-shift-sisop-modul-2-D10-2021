#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void remove_files(){
	pid_t rmfiles;
	int statusf;
	rmfiles = fork();
  	if (rmfiles < 0) {
	    exit(EXIT_FAILURE);
  	}
  	if (rmfiles == 0) {
	    execl("/bin/rm", "rm", "-r", "*/", NULL);
  	} else {
	    // this is parent
	    while ((wait(&statusf)) > 0);
	    
  	}	
}

int main() {
	pid_t child_id;
	int status;
	child_id = fork();
  	if (child_id < 0) {
	    exit(EXIT_FAILURE);
  	}
  	if (child_id == 0) {
	    execl("usr/bin/unzip", "unzip", "pets.zip", NULL);
  	} else {
	    // this is parent
	    while ((wait(&status)) > 0);
	    remove_files();
  	}	
}
