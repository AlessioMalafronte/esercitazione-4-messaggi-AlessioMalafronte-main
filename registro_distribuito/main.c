#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>

#include "registro.h"

int main() {


    /* TBD: Creare le code di messaggi, e avviare i processi server e registro,
     *      facendogli chiamare le funzioni server() e registro().
     */

    int id_coda_registro_richieste = /* TBD */;

    int id_coda_registro_risposte = /* TBD */;

    /* TBD: Avviare un processo figlio, e chiamare la funzione:
     *      registro(id_coda_registro_richieste,id_coda_registro_risposte);
     */

    for (int i = 0; i < 2; i++)
    {
        /* TBD: Avviare un processo figlio, e chiamare la funzione:
         *      server(id_coda_registro_richieste, id_coda_registro_risposte, i);
         */
    }


    /* NOTA: Lasciare questa sleep per avviare i client con un ritardo,
     *       in modo da dare il tempo ai server di registrarsi sul processo registro.
     */

    sleep(2);

    for (int i = 0; i < 3; i++)
    {
        /* TBD: Avviare un processo figlio, e chiamare la funzione:
         *      client(id_coda_registro_richieste, id_coda_registro_risposte);
         */
    }


    /* TBD: Attendere la terminazione dei processi client */


    printf("Padre: Invio messaggio EXIT\n");

    /* TBD: Inviare un messaggio di tipo EXIT al registro,
     *      tramite "id_coda_registro_richieste"
     */

    /* TBD: Attendere la terminazione dei processi server e del processo registro */

    /* TBD: Rimuovere le code */
}