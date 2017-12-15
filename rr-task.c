#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	struct sched_param param;
	int n = 0, priority = 0;

	if (argc < 2) exit(1);
	priority = atoi(argv[1]);
	priority = (priority < 1 || priority > 99) ? 1 : priority;

	printf("Setting SCHED_RR and priority to %d\n", priority);
	param.sched_priority = priority;
	sched_setscheduler(0, SCHED_RR, &param);

	while(1) {
		if (!(++n % 10000000)) {
			sched_getparam(0, &param);
			printf("%s RR Prio %d running (n=%d)\n", argv[2], param.sched_priority, n);
		}
	}
	exit(0);
}
