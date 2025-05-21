#include "stdlib.h"
#include "unistd.h"
#include <sys/select.h>

int main(void){
	fd_set set1;
	fd_set set2;
	fd_set set3;
	struct timeval time;
	select(0, &set1, &set2, &set3, &time);
	return 0;
}
