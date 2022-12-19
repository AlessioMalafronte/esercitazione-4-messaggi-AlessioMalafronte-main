#ifndef __HEADER__
#define __HEADER__

#include <sys/types.h>

#define TOTALE_SERVER 3
#define TOTALE_CLIENT 8
#define TOTALE_MESSAGGI 15


/* TBD: definire una struttura per i messaggi, 
        includendo un campo intero in cui inserire
		il PID del mittente.
 */
struct messaggi {
    long type;
    pid_t pid_mittente;
};

void Client(int msg_id_balancer);
void Balancer(int msg_id_balancer, int msg_id_server[]);
void Server(int msg_id_server);


#endif /* __HEADER__ */
