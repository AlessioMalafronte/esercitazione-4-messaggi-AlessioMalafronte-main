#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "registro.h"

void registro(int id_coda_registro_richieste, int id_coda_registro_risposte) {
    
    printf("Registro: Avvio...\n");


    /* Questo vettore verrà usato per memorizzare gli ID delle code dei server */
    int id_code_server[2];
    id_code_server[0] = 0;
    id_code_server[1] = 0;


    while(1) {

        printf("Registro: In attesa di messaggi...\n");

        /* TBD: Prelevare un messaggio dalla coda "id_coda_registro_richieste" */


        if(/* TBD: Messaggio di tipo BIND */) {

            printf("Registro: Ricevuto messaggio BIND (id_server=%d, id_coda=%d)\n", /* TBD */, /* TBD */);

            if(/* TBD: Controllare che lo ID del server sia 0 oppure 1 */) {
                printf("Registro: ID server non valido\n");
                continue;
            }

            printf("Registro: Registrazione server %d\n", /* TBD */);

            id_code_server[/* TBD */] = /* TBD: Memorizzare lo ID della coda */;

        }
        else if(/* TBD: Messaggio di tipo QUERY */) {

            printf("Registro: Ricevuto messaggio QUERY (id_server=%d)\n", /* TBD */);

            if(/* TBD: Controllare che lo ID del server sia 0 oppure 1 */) {
                printf("Registro: ID server non valido\n");
                continue;
            }

            // TBD: Controllare che lo ID del server sia stato precedentemente registrato
            if(id_code_server[/* TBD */] == 0) {
                printf("Registro: ID server non registrato\n");
                continue;
            }

            /* TBD: Inviare un messaggio di risposta di tipo RESULT al client,
             *      tramite la coda "id_coda_registro_risposte" */

            printf("Registro: Invio messaggio RESULT (id_coda=%d)\n", /* TBD: ID della coda del server */);

        }
        else if(/* TBD: Messaggio di tipo EXIT */) {

            printf("Registro: Ricevuto messaggio EXIT\n");


            for(int i = 0; i<2; i++) {

                if(id_code_server[i] == 0) {
                    continue;
                }

                /* TBD: Inviare un messaggio di tipo EXIT al server, 
                 *      tramite la coda "id_code_server[i]"
                 */

                printf("Registro: Invio messaggio EXIT a server %d\n", i);

            }

            printf("Registro: Uscita\n");

            /* TBD: Terminare il processo */
            
        }
        else {

            printf("Registro: Ricevuto messaggio non riconosciuto\n");
        }
    }
}
