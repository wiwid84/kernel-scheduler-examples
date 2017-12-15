#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
	struct sched_param param;
	int n = 0, niceness = 0;

	if (argc < 2) exit(1);
	niceness = atoi(argv[1]);
	niceness = (niceness < -20 || niceness > 19) ? 0 : niceness;

	printf("Setting SCHED_OTHER and priority to %d\n", niceness);
	param.sched_priority = 0;
	sched_setscheduler(0, SCHED_OTHER, &param);
	nice(niceness);

	while(1) {
		if (!(++n % 10000000)) {
			printf("%s OTHER Prio %d running (n=%d)\n", argv[2], 
					getpriority(PRIO_PROCESS, 0), n);
		}
	}
	exit(0);
}
