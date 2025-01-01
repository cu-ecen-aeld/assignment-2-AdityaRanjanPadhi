#include<fcntl.h>
#include<syslog.h>
#include<string.h>
#include<unistd.h>

int  main(int argc, char ** argv){
	openlog(NULL,0,LOG_USER);
	if (argc!=3){
		syslog(LOG_ERR,"Invalid Number of Arguments: %d", argc);
		closelog();
		return 1;
	}

	char * filename = argv[1];
	char * data = argv[2];

	int fd;
	fd = creat(filename,0644);
	if (fd==-1){
		syslog(LOG_ERR,"No Filename");
		closelog();
		return 1;
	}

	ssize_t nr;
	nr = write(fd,data,strlen(data));
	syslog(LOG_DEBUG,"Writing %s to %s",data,filename);
	if (nr!=strlen(data)){
		syslog(LOG_ERR,"Data Write Incomplete");
		closelog();
		return 1;
	}
	closelog();
	return 0;
}
