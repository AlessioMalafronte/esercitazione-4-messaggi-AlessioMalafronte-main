#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "registro.h"

void server(int id_coda_registro_richieste, int id_coda_registro_risposte, int id_server) {

    printf("Registro: Server...\n");

    int risorsa = 0;

    int id_coda_server = /* TBD */

    printf("Server: Invio messaggio BIND (id_server=%d, id_coda=%d)\n", id_server, id_coda_server);

    /* TBD: Inviare messaggio di BIND al registro,
     *      tramite la coda "id_coda_registro_richieste",
     *      e includere nel messaggio lo ID della
     *      coda privata del server "id_coda_server"
     */


    while(1) {

        printf("Server: In attesa di messaggi...\n");

        /* TBD: Prelevare un messaggio dalla coda del server */



        if(/* TBD: Messaggio di tipo SERVICE */) {

            printf("Server: Ricevuto messaggio SERVICE (id_server=%d, valore=%d)\n", id_server, /* TBD */);

            risorsa = /* TBD: Assegnare il valore ricevuto alla risorsa */;
        }
        else if(/* TBD: Messaggio di tipo EXIT */) {

            printf("Server: Ricevuto messaggio EXIT (id_server=%d)\n", id_server);

            /* TBD: De-allocare la coda del server */

            printf("Server: Uscita\n");

            /* TBD: Terminare il processo */
        }
        else {

            printf("Server: Ricevuto messaggio non riconosciuto\n");
        }

    }
}
