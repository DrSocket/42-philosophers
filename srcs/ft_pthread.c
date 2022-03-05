#include "philosophers.h"

int		prime[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
void*	routine()
{
	printf("Test from threads\n");
	sleep(3);
	printf("Ending thread\n");
	return (0);
}

int		ft_pthread(int ac, char **av)
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return (0);
}