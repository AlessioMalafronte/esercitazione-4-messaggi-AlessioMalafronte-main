#ifndef _SERVERSYNC_H_
#define _SERVERSYNC_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* TBD: Definire una struct per i messaggi "REQUEST TO SEND" */

struct RTS{
    long type;
};
/* TBD: Definire una struct per i messaggi "OK TO SEND" */
struct OTS{
    long type;
    int id_coda;
};

typedef struct {
    long type;
    int val;
} messaggio;

void receive_sinc(int msg_id, int ok_id, int req_id, messaggio * msg);
void send_sinc(int ok_id, int req_id, messaggio * msg);

#endif