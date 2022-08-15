#include <stdio.h>
#include <syslog.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	openlog(NULL,0, LOG_USER);
	
	if(argc < 3)
	{
        	syslog(LOG_ERR, "invalid number of arguments, expecting 2, received : %d", argc);
		return 1;
	}	
/*
	if(access(argv[1], F_OK) !=0)
	{
		syslog(LOG_ERR, "\"%s\" file not present",argv[1]);
		return -1;
	}
*/
	FILE *fptr = fopen(argv[1],"w+");
	if(fptr == NULL)
	{
		syslog(LOG_ERR, "not able to open the specified file %s",
				argv[1]);
		return 1;
	}
	if(fprintf(fptr,"%s", argv[2]) < 0)
	{
		syslog(LOG_ERR, "error while writing data to file \"%s\"",
				argv[1]);
		return 1;
	}
	syslog(LOG_DEBUG, "writing \" %s \" to file \"%s\"",argv[2],argv[1]);

	/* return 0 for success,
	 * when we execute this binary from shell script
	 * and if we return 1, script will get terminated.
	 */
	return 0;
}

		


