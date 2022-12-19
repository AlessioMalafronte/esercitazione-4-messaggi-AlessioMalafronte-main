#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "serversync.h"



void send_sinc(int ok_id, int req_id, messaggio * msg)
{

    int ret;

    /* TBD: Inviare il messaggio REQUEST TO SEND */

    struct RTS r;

    struct OTS o;

    r.type = getpid();

    printf("[%d] Client: invio request-to-send, type=%ld\n", getpid(), r.type);

    ret = msgsnd(req_id, &r, sizeof(struct RTS) - sizeof(long), 0);

    if (ret < 0)
    {
        perror("Errore msgsnd (request-to-send)");
        exit(1);
    }


    /* TBD: Ricevere il messaggio OK TO SEND */

    printf("[%d] Client: in attesa di ok-to-send...\n", getpid());

    ret = msgrcv(req_id, &o, sizeof(struct OTS) - sizeof(long), getpid(), 0);

    if (ret < 0)
    {
        perror("Errore msgrcv (ok-to-send)");
        exit(1);
    }

    printf("[%d] Client: ricevuto ok-to-send... type=%ld, id_coda=%d\n", getpid(), o.type, o.id_coda);




    /* TBD: Inviare il messaggio al server */

    int id_coda = o.id_coda;

    printf("[%d] Client: invio messaggio, coda=%d, type=%ld, valore=%d\n", getpid(), id_coda, msg->type, msg->val);

    ret = msgsnd(id_coda, msg, sizeof(messaggio) - sizeof(long), 0);

    if (ret < 0)
    {
        perror("Errore msgsnd (coda messaggi)");
        exit(1);
    }

}

void receive_sinc(int msg_id, int ok_id, int req_id, messaggio * msg)
{

    int ret;

    struct RTS r;

    struct OTS o;

    /* TBD: Ricevere il messaggio REQUEST TO SEND */

    printf("[%d] Server: in attesa di request-to-send...\n", getpid());

    ret = msgrcv(req_id, &r, sizeof(r) - sizeof(long), 0, 0);

    printf("[%d] Server: ricevuto request-to-send, type=%ld\n", getpid(), r.type);

    if (ret < 0)
    {
        perror("Errore msgrcv (request-to-send)");
        exit(1);
    }



    /* TBD: Inviare il messaggio OK TO SEND */

    printf("[%d] Server: invio ok-to-send, type=%ld, id_coda=%d\n", getpid(), o.type, o.id_coda);

    ret = msgsnd(ok_id, &o, sizeof(o) - sizeof(long), 0);

    if (ret < 0)
    {
        perror("Errore msgsnd (ok-to-send)");
        exit(1);
    }



    /* TBD: Ricevere il messaggio destinato al server, usando la struct indicata
            dal puntatore "msg" (passato dal chiamante della funzione) 
     */

    printf("[%d] Server: in attesa del messaggio...\n", getpid());

    ret = msgrcv(msg_id, msg, sizeof(messaggio)- sizeof(long), 0, 0);

    if (ret < 0)
    {
        perror("Errore msgrcv (coda messaggi)");
        exit(1);
    }

    printf("[%d] Server: ricevuto messaggio, type=%ld, valore=%d\n", getpid(), msg->type, msg->val);

}
